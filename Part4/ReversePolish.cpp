/* 
   Design a reverse polish calculator to evaluate postfix expressions using stack.
   Ask for user input and print the result back to the console.

   Example: 
    Input: 10 10 + 
    Output: 20
*/

#include <iostream>
#include "IntegerStack.cpp"
#include <string>
#include <sstream>
#include <stdexcept>

class DivisionByZero : public std::runtime_error
{
public:
    DivisionByZero() 
        : std::runtime_error("division by zero")
    { }
};

class BadToken;

class Token
{
public:
    friend std::stringstream& operator>>(std::stringstream& ss, Token& token)
    {
        ss >> token.m_tok;
        return ss;
    }
    bool isInteger()
    {
        try
        {
            m_val = std::stoi(m_tok);
        }
        catch (const std::invalid_argument&)
        {
            return false;
        }
        return true;
    }
    bool isOperator() const
    {
        if (m_tok.find_first_of("+-*/%") == std::string::npos)
        {
            return false;
        }
        return true;
    }
    inline operator int() const
    {
        return m_val;
    }
    int operator()(int, int) const;
private:
    std::string m_tok;
    int m_val;
    friend class BadToken;
};

class BadToken : public std::logic_error
{
public:
    BadToken(const Token& token, const std::string& suffix)
        : std::logic_error("Bad token '" + token.m_tok + "': " + suffix)
    { }
};

int Token::operator()(int operand1, int operand2) const
{
    int result;
    switch (m_tok[0])
    {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0)
                throw DivisionByZero();
            result = operand1 / operand2;
            break;
        case '%':
            if (operand2 == 0)
                throw DivisionByZero();
            result = operand1 % operand2;
            break;
        default:
            throw BadToken(*this, "unrecognized operator");
    }
    return result;
}

class BadExpression : public std::logic_error
{
public:
    BadExpression(const std::string& description) 
        : std::logic_error(description)
    { }
};

int eval(const std::string& line)
{
    std::stringstream expr(line);

    Token token;
    IntegerStack stack;
    int operand1, operand2, result = 0;
    while (expr >> token)
    {
        if (token.isOperator())
        {
            try
            {
                operand2 = stack.pop();
                operand1 = stack.pop();
                result = token(operand1, operand2);
                stack.push(result);
            }
            catch (const StackUnderflow&) { throw BadExpression("more operators than operands"); }
            catch (const DivisionByZero&) { throw; }
            catch (const StackOverflow&) { throw BadExpression("expresssion too long"); }
        }
        else if (token.isInteger())
        {
            stack.push(token);
        }
        else
        {
            throw BadToken(token, "neither operator, nor operand");
        }
    }

    result = stack.pop();
    if (stack)
    {
        throw BadExpression("more operands than operators");
    }
    else
    {
        return result;
    }
}

int main()
{
    std::cout << "====================================================================" << '\n'
              << "||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||" << '\n'
              << "|| , __                                , __       _          _    ||" << '\n'
              << "||/|/  \\                              /|/  \\     | | o      | |   ||" << '\n'
              << "|| |___/  _        _   ,_    ,   _     |___/ __  | |     ,  | |   ||" << '\n'
              << "|| | \\   |/  |  |_|/  /  |  / \\_|/     |    /  \\_|/  |  / \\_|/ \\  ||" << '\n'
              << "|| |  \\_/|__/ \\/  |__/   |_/ \\/ |__/   |    \\__/ |__/|_/ \\/ |   |_/|" << '\n'
              << "||                                                                ||" << '\n'
              << "||       ___        _               _                             ||" << '\n'
              << "||      / (_)      | |             | |                     |      ||" << '\n'
              << "||     |      __,  | |  __         | |  __, _|_  __   ,_   |      ||" << '\n'
              << "||     |     /  |  |/  /    |   |  |/  /  |  |  /  \\_/  |  |      ||" << '\n'
              << "||      \\___/\\_/|_/|__/\\___/ \\_/|_/|__/\\_/|_/|_/\\__/    |_/o      ||" << '\n'
              << "||                                                                ||" << '\n'
              << "||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||" << '\n'
              << "====================================================================" << std::endl;
    while (true)
    {
        std::cout << "Enter a postfix expression to evaluate: ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "quit")
            break;

        try
        {
            int result = eval(line);
            std::cout << "Result = " << result << std::endl;
        }
        catch (const BadExpression& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
        catch (const DivisionByZero& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
        catch (const BadToken& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
    }
}
