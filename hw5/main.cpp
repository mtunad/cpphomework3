#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int sales[150][5];
    char choice = 1;
    int day = 0, row = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sales[i][j] = 0;
        }
    }

    cout << "\n\nReport of Product and Salespeoplesales";

    do
    {
        cout << endl << "Enter details of day " << (day + 1);
        do
        {
            cout << endl << "Enter salesperson number: ";
            cin >> sales[row][0];

            cout << endl << "Enter the product number: ";
            cin >> sales[row][1];
            

            cout << endl << "Enter the total dollar value of that product sold that day: ";
            cin >> sales[row][2];

            sales[row][3] = day + 1;

            cout << endl << "Do you want to enter one more Y/N: ";
            cin >> choice;

            row++;
        } while(tolower(choice) != 'n');
        day++;
    } while(day < 30);

    int productTotal, salesmanSales[4];

    for (int d = 1; d <= day; d++)
    {
        for (int z = 0; z < 4; z++)
        {
            salesmanSales[z] = 0;
        }

        cout << endl << endl << "\t\tSales summary for day " << d << endl;
        cout << "Product#    Salesperson1     Salesperson1      Salesperson1     Salesperson1     Total";
        cout << endl << "-------------------------------------------------------------------";

        for (int product = 1; product < 6; product++)
        {
            productTotal = 0;
            cout << endl << setw(5) << product;

            for (int sperson = 1; sperson  < 5; sperson ++)
            {
                bool found = false;
                for (int r = 0; r < row; r++)
                {
                    if (sales[r][1] == product)
                        if (sales[r][0] == sperson)
                            if (sales[r][3]==d)
                            {
                                productTotal += sales[r][2];
                                salesmanSales[sperson-1] += sales[r][2];
                                cout << setw(13) << sales[r][2];
                                found = true;   
                             }   
                }
                if (found == false)
                    cout << setw(13) << "0";
            }
            cout << setw(10) << productTotal;
        }

        cout << endl << "-------------------------------------------------------------------";
        cout << endl << "Total";

        productTotal = 0;

        for (int z = 0; z < 4; z++)
        {
            cout << setw(13) << salesmanSales[z];
            productTotal += salesmanSales[z];
        }
        
        cout << setw(10) << productTotal;

        cout << endl << "-------------------------------------------------------------------";
    }
    

    return 0;
}