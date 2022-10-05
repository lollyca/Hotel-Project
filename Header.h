#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Hotel {

private:
	int numberOfRooms, roomPrice, roomsReserved=0, roomsAvailable=0, income=0;
	string roomName;

public:
	Hotel(int rooms, int price, string name);
	void displayInventory();
	void roomReservation(int numReserved);
	void roomRevenue();
};

#endif