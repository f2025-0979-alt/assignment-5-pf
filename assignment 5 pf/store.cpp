#include <iostream>   
#include <vector>     
#include <fstream>    
using namespace std;


struct Order
{
    int orderID;          
    string customerName;  
    int items;            
    double price;         
};

int main()
{
  
    vector<Order> orders;

    int n;
    cout << "Enter number of orders: ";
    cin >> n;

   
    for (int i = 0; i < n; i++)
    {
        Order o;

        cout << "Enter details for Order " << i + 1 << endl;

        cout << "Order ID: ";
        cin >> o.orderID;

        cout << "Customer Name: ";
        cin.ignore();
        getline(cin, o.customerName);

        cout << "Number of Items: ";
        cin >> o.items;

        cout << "Price per Item: ";
        cin >> o.price;

        orders.push_back(o); 
    }

 
    ofstream outFile("priority_orders.txt");

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < orders.size(); i++)
    {
        double totalAmount = orders[i].items * orders[i].price;

        if (totalAmount > 5000)
        {
            outFile << orders[i].orderID << endl;
            outFile << orders[i].customerName << endl;
            outFile << totalAmount << endl;
        }
    }

    outFile.close();

   
    ifstream inFile("priority_orders.txt");

    if (!inFile)
    {
        cout << "Error reading file!" << endl;
        return 1;
    }

    cout << "Priority Orders (Total > 5000):";

    int id;
    string name;
    double total;

    while (inFile >> id)
    {
        inFile.ignore();
        getline(inFile, name);
        inFile >> total;

        cout << "\nOrder ID: " << id;
        cout << "\nCustomer Name: " << name;
        cout << "\nTotal Amount: " << total << endl;
    }

    inFile.close();

    return 0;
}
