/* 
    Simple integer stack with basic push, pop functionality.
    TODO: update with improved stack design while still maintaining compatibility.
*/
#include <vector>
#include <iostream>
#include <stdexcept>

class StackOverflow : public std::logic_error
{
public:
    StackOverflow(int limit) 
        : m_limit(limit),
          std::logic_error( "Stack Overflow Error: maximum size of stack exceeded")
    { }
    int getLimitExceeded() const
    {
        return m_limit;
    }
private:
    int m_limit;
};

class StackUnderflow : public std::logic_error
{
public:
    StackUnderflow() : 
        std::logic_error( "Stack Underflow Error: access to empty stack")
    { }
};

class IntegerStack // use composition (is-implemented-in-terms-of), instead of inheritance (is-a)
{
public:
    IntegerStack() 
        : m_maxSize(g_defMaxSize)
    { }
    IntegerStack(int limit) 
        : m_maxSize(limit)
    { }
    void push(int item)
    {
        if (m_vec.size() < m_maxSize)
        {
            m_vec.push_back(item);
        }
        else
        {
            throw StackOverflow(m_maxSize);
        }
    }
    int pop()
    {
        if (*this)
        {
            int value = m_vec.back();
            m_vec.pop_back();
            return value;
        }
        else 
            throw StackUnderflow();

    }
    inline int peek() const
    {
        return m_vec.back();
    }
    inline operator bool() const
    {
        return m_vec.size() > 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const IntegerStack& stack)
    {
        if (stack)
        {
            int index = stack.m_vec.size() - 1;
            os << stack.m_vec[index--] << " <- sp\n";
            for (; index >= 0; --index)
            {
                os << stack.m_vec[index]  << "\n";
            }
        }
        else
        {
            os << "<empty>";
        }
        return os;
    }
private:
    const int m_maxSize;
    std::vector<int> m_vec;
    static int g_defMaxSize;
};

int IntegerStack::g_defMaxSize = 1000;
