#include "Header.h"
using namespace std;

int main()
{
	int totalRooms = 122;
	const int COUT = 70;
	const int SCENIC = 35;
	const int SUITE = 15;
	const int PENT = 2;
	int date, reservationInput;


	Room arrCourtyard[COUT];
	Room arrScenic[SCENIC];
	Room arrSuite[SUITE];
	Room arrPenthouse[PENT];


	cout << "Enter today's date ---> ";
	cin >> date;

	arrCourtyard->setName(arrCourtyard, COUT, "Courtyard");
	arrScenic->setName(arrScenic, SCENIC, "Scenic");
	arrSuite->setName(arrSuite, SUITE, "Deluxe Suite");
	arrPenthouse->setName(arrPenthouse, PENT, "Penthouse");

	arrCourtyard->setPrice(arrCourtyard, COUT, 125);
	arrScenic->setPrice(arrScenic, SCENIC, 145);
	arrSuite->setPrice(arrSuite, SUITE, 350);
	arrPenthouse->setPrice(arrPenthouse, PENT, 1135);

	arrCourtyard->setCondition(arrCourtyard, COUT);
	arrScenic->setCondition(arrScenic, SCENIC);
	arrSuite->setCondition(arrSuite, SUITE);
	arrPenthouse->setCondition(arrPenthouse, PENT);


	cout << "Inventory" << endl;
	cout << "Courtyard - " << COUT << " - $" << arrCourtyard->getRoomPrice() << " a night" << endl;
	cout << "Scenic - " << SCENIC << " - $" << arrScenic->getRoomPrice() << " a night" << endl;
	cout << "Deluxe Suite - " << SUITE << " - $" << arrSuite->getRoomPrice() << " a night" << endl;
	cout << "Penthouse - " << PENT << " - $" << arrPenthouse->getRoomPrice() << " a night" << endl;
	cout << "\n";

	cout << "Reservation system: " << endl;
	cout << "What room would you like to reserve? " << endl;
	cout << "1 --- Courtyard - 70 - $125 a night" << endl;
	cout << "2 --- Scenic - 35 - $145 a night" << endl;
	cout << "3 --- Deluxe Suite - 15 - $350 a night" << endl;
	cout << "4 --- Penthouse - 2 - $1135 a night" << endl;
	cin >> reservationInput;

	switch (reservationInput)
	{
	case 1:
		arrCourtyard->setReservation(arrCourtyard);
		break;
	case 2:
		arrScenic->setReservation(arrScenic);
		break;
	case 3:
		arrSuite->setReservation(arrSuite);
		break;
	case 4:
		arrPenthouse->setReservation(arrPenthouse);
		break;
	}

}




