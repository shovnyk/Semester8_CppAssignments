/* 
    Input the Cost Price and Selling Price of an article.
    Now calculate gain or loss.
*/

#include <iostream>

using namespace std;

int main()
{
    int costPrice;
    int sellingPrice;

    cout << "Enter the cost price of the article (in Rs.): ";
    cin >> costPrice;

    cout << "Enter the selling price of the article (in Rs.): ";
    cin >> sellingPrice;

    int diff = sellingPrice - costPrice;

    if (diff > 0) {
        cout << "Gain = Rs. " << diff;
    }
    else {
        cout << "Loss = Rs. " << -diff;
    }
    cout << endl;
}
