#include <iostream>

using namespace std;

class Car
{
 public:
    string make;
	string model;
	int year;
	double pricePerDay;
	bool available;

};


void printCars(Car cars[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ": " << cars[i].year<< " " << cars[i].make << " " << cars[i].model<< ", $" << cars[i].pricePerDay<< " per day" << endl;
	}
}

int main()
{
	Car cars[3];
	cars[0].make="Toyota";
	cars[0].model="Camry";
	cars[0].year=2020;
	cars[0].pricePerDay=50;
	cars[0].available= true;

	cars[1].make="Honda";
	cars[1].model="Civic";
	cars[1].year= 2019;
	cars[1].pricePerDay= 40;
	cars[1].available= true;

	cars[2].make="Ford";
	cars[2].model="Mustang";
	cars[2].year=2018;
	cars[2].pricePerDay=60;
	cars[2].available=false;

char userChoice;
do
{
    cout << "Here are the cars we have available for rent: " << endl;
    printCars(cars, 3);
    cout << "Enter the number of the car you would like to rent! Press r to return a car or c to contact us. To exit press x" << endl;
    cin >> userChoice;
    if (userChoice == 'r')
    {
        cout << "Enter the number of the car you would like to return: ";
        int carChoice;
        cin >> carChoice;
        if (carChoice < 1 || carChoice > 3)
        {
            cout << "Invalid choice. Please select a valid car" << endl;
        }
        else
        {
            if (cars[carChoice - 1].available == false)
            {
                cars[carChoice - 1].available=true;
                cout << "Car successfully returned" << endl;
            }
            else
            {
                cout << "Car is not rented" << endl;
            }
        }
    }
    else if (userChoice == 'c')
    {
        cout << "Please contact us:\n BHU/21/04/05/0038\n BHU/21/04/05/0037\n BHU/21/04/09/0003\n BHU/21/04/05/0029\n BHU/21/04/05/0044" << endl;
    }


		else
		{
			int carChoice = userChoice - '0';
			if (carChoice < 1 || carChoice > 3 || !cars[carChoice - 1].available)
			{
				cout << "Invalid choice/Car unavailable, please select a valid car" << endl;
			}
			else
			{
				int numDays;
				cout << "How many days would you like to rent the car: ";
				cin >> numDays;
				if (numDays < 1)
        {
            cout << "Invalid input. Please enter a positive number" << endl;
        }
        else
        {
            double totalCost = cars[carChoice - 1].pricePerDay* numDays;

            cout << "The total cost of your rental is $" << totalCost << endl;
        }


				cars[carChoice - 1].available=false;
				cout << "Thank you for renting." << endl;
			}
		}
		cout << "Enter 'x' to exit or any other key to continue: " << endl;
		cin >> userChoice;
		if (userChoice == 'x')
		{
			cout << "Exiting program. Thank you for using our service." << endl;
			break;
		}
	} while (true);

	return 0;
}
