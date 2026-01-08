#include <iostream>   
#include <vector>   
#include <fstream>    
using namespace std;


struct Employee
{
    int id;           
    string name;     
    double monthlySalary; 
};

int main()
{
    
    vector<Employee> employees;

    int n;
    cout << "Enter number of employees: ";
    cin >> n;

   
    for (int i = 0; i < n; i++)
    {
        Employee emp;  

        cout << "Enter details for employee " << i + 1 << endl;

        cout << "Employee ID: ";
        cin >> emp.id;

        cout << "Employee Name: ";
        cin.ignore();              
        getline(cin, emp.name);    

        cout << "Monthly Salary: ";
        cin >> emp.monthlySalary;

        employees.push_back(emp); 
    }

    double limit;
    cout <<endl<< "Enter yearly salary limit: ";
    cin >> limit;

   
    ofstream outFile("high_salary.txt");

   
    if (!outFile)
    {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    
    for (int i = 0; i < employees.size(); i++)
    {
        double yearlySalary = employees[i].monthlySalary * 12;

        if (yearlySalary > limit)
        {
            outFile << employees[i].id << endl;
            outFile << employees[i].name << endl;
            outFile << yearlySalary << endl;
        }
    }

    outFile.close();
    cout << "\nData saved to high_salary.txt successfully." << endl;

  
    ifstream inFile("high_salary.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout <<endl<< "Employees with High Salary:";

    int id;
    string name;
    double yearlySalary;

    while (inFile >> id)
    {
        inFile.ignore();
        getline(inFile, name);
        inFile >> yearlySalary;

        cout << "\n      Employee ID: " << id;
          cout << "\n  Name: " << name;
        cout << "\n  Yearly Salary: " << yearlySalary << endl;
    }

    inFile.close();

    return 0;
}
