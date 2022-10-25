
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <array>


using namespace std;

class Room {
private:
	int roomNumber;
	double roomPrice;
	string roomStyle;
	bool isAvailable;
	

public:
	void setName(Room array[], int size, string name);
	void setNumber(Room array[], int size, int roomNumber);
	void setPrice(Room array[], int size, double price);
	void setCondition(Room array[], int size);
	int getRoomNumber() {return roomNumber;}
	double getRoomPrice() {return roomPrice;}
	string getRoomStyle() {return roomStyle;}
	bool getCondition() { return isAvailable; }

	void setReservation(Room array[]);


};


#endif