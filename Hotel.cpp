#include "Header.h"

using namespace std;

Hotel::Hotel(int rooms, int price, string name) {
	numberOfRooms = rooms;
	roomPrice = price;
	roomName = name;
}

void Hotel::displayInventory() {
	cout << setw(15) << left << roomName;
	cout << left << "$" << setw(10) << left << roomPrice;
	cout << setw(10) << left << numberOfRooms << endl;
}

void Hotel::roomReservation(int numReserved) {
	roomsReserved = roomsReserved + numReserved;
	roomsAvailable = numberOfRooms - roomsReserved;

	cout << roomName << ":" << endl;
	cout << "Rooms reserved " << roomsReserved << endl;
	cout << "Rooms available " << roomsAvailable << endl; 
}

void Hotel::roomRevenue() {
	income = roomsReserved * roomPrice;
	cout << roomName << ":" << endl;
	cout << "Revenue: $" << income << endl;
}

/*
Fourth, the user can choose a getTotal() function that will display remaining room inventory, what was reserved and revenue generated for the day.
*/

