// this is the boilerplate made by editing user snippet
//this is the program to display the Shop item id and Price
#include <iostream>
using namespace std;
class Shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void countme(void)
    {
        counter = 0;
    }
    void setPrice(void);
    void displayPrice(void);
};

void Shop::setPrice(void)
{
    cout << "Enter the Id of item no" << counter + 1<<endl;
    cin >> itemId[counter];
    cout << "Enter the Price " << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop::displayPrice(void)
{

    for (int i = 0; i < counter; i++)
    {
        cout << "the price of your item id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop pasal;
    pasal.countme();
    pasal.setPrice();
    pasal.setPrice();
    pasal.displayPrice();

    return 0;
}