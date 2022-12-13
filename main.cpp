#include <iostream>
#include <fstream>
#include "HotelManager.h"
using namespace std;

int main()
{
	HotelManager hotelManager;
	hotelManager.displayInventory();

	fstream myFile;

	myFile.open("hotelTest.txt", ios::out);

	if (!myFile.is_open())
	{
		cout << "File was not open" << endl;
		return 0;
		myFile.close();
	}
	else
	{
		myFile << "Welcome to the Hotel Helozinha!" << endl;
		myFile.close();
	}

	string managerChoice;
	do
	{
		cout << "\n";
		cout << "\n";
		cout << "\t   Menu:" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Please choose one option or press Q to QUIT." << endl;
		cout << "1 - Make a reservation" << endl;
		cout << "2 - Show today's inventory of the day" << endl;
		cout << "3 - Save data" << endl;
		cout << "4 - View existing bookings" << endl;
		cout << "Q - Quit" << endl;
		cin >> managerChoice;

		if (managerChoice == "1")
		{
			hotelManager.roomReservation();
		}
		else if (managerChoice == "2")
		{
			hotelManager.getTotal();
		}
		// criar um close the day
		else if (managerChoice == "3")
		{
			hotelManager.saveData();
		}
		else if (managerChoice == "4")
		{
			cout << "Enter a date to view bookings\n";
			string date;
			cin >> date;
			hotelManager.showDay(date);
		}

	} while (managerChoice != "Q");

	cout << "\n";
	cout << "Have a good day!" << endl;
}
