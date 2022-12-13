#include <fstream>
#include <iostream>
#include <string>
#include "HotelManager.h"
using namespace std;

HotelManager::HotelManager()
{
	for (int i = 0; i < hotelArray.size(); i++)
	{
		Room newRoom;
		newRoom.isAvailable = true;
		if (i < 70)
		{
			newRoom.type = "Courtyard";
			newRoom.price = 125;
			newRoom.roomNumber = i + 101;
		}
		else if (i < 105)
		{
			newRoom.type = "Scenic";
			newRoom.price = 145;
			newRoom.roomNumber = i + (131);
		}
		else if (i < 120)
		{
			newRoom.type = "Deluxe";
			newRoom.price = 350;
			newRoom.roomNumber = i + (131);
		}
		else if (i < 122)
		{
			newRoom.type = "Penthouse";
			newRoom.price = 1135;
			newRoom.roomNumber = i + (181);
		}
		hotelArray[i] = newRoom;
	}
};

void HotelManager::displayInventory()
{
	cout << "Please enter today's date (MM/DD/YY): ---> ";
	cin >> todayDate;
	cout << "\n";
	cout << "   Welcome to Hotel Helozinha" << endl;
	cout << "\n";
	cout << "\t   Inventory:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << setw(15) << left << "Courtyard" << setw(6) << left << "70" << setw(6) << right << "$125" << endl;
	cout << setw(15) << left << "Scenic" << setw(6) << left << "35" << setw(6) << right << "$145" << endl;
	cout << setw(15) << left << "D. Suite" << setw(6) << left << "15" << setw(6) << right << "$350" << endl;
	cout << setw(15) << left << "Penthouse" << setw(6) << left << "2" << setw(6) << right << "$1135" << endl;
	cout << setw(15) << left << "Total Rooms" << setw(6) << left << "122" << endl;
};

void HotelManager::roomReservation()
{
	int reservationInput;

	cout << "\n";
	cout << "\n";
	cout << "\t   Reservation System:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "What room would you like to reserve? " << endl;
	cout << "1 --- Courtyard - $125 a night" << endl;
	cout << "2 --- Scenic - $145 a night" << endl;
	cout << "3 --- Deluxe Suite - $350 a night" << endl;
	cout << "4 --- Penthouse - $1135 a night" << endl;
	cin >> reservationInput;

	int availableRooms = 0;
	string client;

	cout << "Please enter First and Last Name ---> ";
	cin.ignore();
	getline(cin, client);

	switch (reservationInput)
	{
	case 1:
		availableRooms = countAvailableRooms("Courtyard");
		if (availableRooms > 0)
		{
			Room toReserve = bookFirstAvailable("Courtyard", client);
			cout << "Thank you for your reservation! " << toReserve.roomNumber << endl;
			break;
		}
		else
		{
			cout << "No rooms available" << endl;
			break;
		}

		break;

	case 2:
		availableRooms = countAvailableRooms("Scenic");
		if (availableRooms > 0)
		{
			Room toReserve = bookFirstAvailable("Scenic", client);
			cout << "Thank you for your reservation! " << toReserve.roomNumber << endl;
			break;
		}
		else
		{
			cout << "No rooms available" << endl;
			break;
		}

		break;

	case 3:
		availableRooms = countAvailableRooms("Deluxe");
		if (availableRooms > 0)
		{
			Room toReserve = bookFirstAvailable("Deluxe", client);
			cout << "Thank you for your reservation! " << toReserve.roomNumber << endl;
			break;
		}
		else
		{
			cout << "No rooms available" << endl;
			break;
		}

		break;

	case 4:
		availableRooms = countAvailableRooms("Penthouse");
		if (availableRooms > 0)
		{
			Room toReserve = bookFirstAvailable("Penthouse", client);
			cout << "Thank you for your reservation! " << toReserve.roomNumber << endl;
			break;
		}
		else
		{
			cout << "No rooms available" << endl;
			break;
		}

		break;
	}
};

void HotelManager::getTotal()
{
	int availableCourtyardRooms = countAvailableRooms("Courtyard");
	int availableScenicRooms = countAvailableRooms("Scenic");
	int availableDeluxeRooms = countAvailableRooms("Deluxe");
	int availablePenthouseRooms = countAvailableRooms("Penthouse");

	int totalRev = getTotalRevenue();

	cout << "\n";
	cout << "\n";
	cout << "\t   Inventory Of The Day:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "\t   Rooms Available:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << setw(15) << left << "Courtyard" << setw(6) << left << availableCourtyardRooms << endl;
	cout << setw(15) << left << "Scenic" << setw(6) << left << availableScenicRooms << endl;
	cout << setw(15) << left << "D. Suite" << setw(6) << left << availableDeluxeRooms << endl;
	cout << setw(15) << left << "Penthouse" << setw(6) << left << availablePenthouseRooms << endl;
	cout << "\n";
	cout << "-------------------------------------------" << endl;
	cout << "\t   Rooms Booked:" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < hotelArray.size(); i++)
	{
		if (hotelArray[i].isAvailable == false)
		{
			cout << setw(15) << left << hotelArray[i].type << setw(1) << right << "$" << setw(6) << left << hotelArray[i].price << hotelArray[i].guestName << endl;
			// cout << setw(15) << left << hotelArray[i].getClienteName() << endl;
		}
	}
	cout << "-------------------------------------------" << endl;
	cout << setw(15) << left << "Total Revenue" << setw(1) << right << "$" << setw(6) << left << totalRev << endl;
	cout << "-------------------------------------------" << endl;
	cout << "\n";
	cout << "\n";
};

int HotelManager::countAvailableRooms(string type)
{
	int roomsAvailable = 0;
	for (int i = 0; i < 122; i++)
	{
		if (type == hotelArray[i].type && hotelArray[i].isAvailable == true)
		{
			roomsAvailable++;
		}
	}
	return roomsAvailable;
}

Room HotelManager::bookFirstAvailable(string type, string client)
{
	for (int i = 0; i < 122; i++)
	{
		if (hotelArray[i].type == type && hotelArray[i].isAvailable == true)
		{
			hotelArray[i].isAvailable = false;
			hotelArray[i].guestName = client;
			return hotelArray[i];
		}
	}

	return Room();
}

int HotelManager::getTotalRevenue()
{
	int revenue = 0;
	for (int i = 0; i < 122; i++)
	{
		if (hotelArray[i].isAvailable == false)
		{
			revenue += hotelArray[i].price;
		}
	}

	return revenue;
}

void HotelManager::saveData()
{
	fstream hotelDataFile;

	hotelDataFile.open("hotelData.txt", ios::app);

	if (!hotelDataFile.is_open())
	{
		cout << "File was not open! UNEXPECTED BEHAVIOR" << endl;
	}
	else
	{
		// Save the data in this format: (room number/room type/guest name)
		// 11/05/22
		// 301             Courtyard       Whinnie the Poo
		hotelDataFile << todayDate << endl;

		for (int i = 0; i < 122; i++)
		{
			Room room = hotelArray[i];
			if (room.isAvailable == false)
			{
				hotelDataFile << setw(5) << left << room.roomNumber << setw(15) << left << room.type << setw(10) << left << room.guestName << endl;
			}
		}
		
		hotelDataFile << "&&&" << endl;
		hotelDataFile << "\n";
		hotelDataFile.close();
	}
}

void HotelManager::showDay(string date)
{
	ifstream hotelDataFile("hotelData.txt");
	string line;
	while (getline(hotelDataFile, line))
	{
		if (line == date)
		{
			cout << "\n";
			cout << "--------------------------------------------------------" << endl;
			cout << "\t\t      Search:" << endl;
			cout << "Bookings for date - " << line << endl;

			while (line != "&&&")
			{
				getline(hotelDataFile, line);
				if (line != "&&&")
				{
					cout << line << endl;
				}
			}

			cout << "--------------------------------------------------------" << endl;
			return;
		}
	}
}