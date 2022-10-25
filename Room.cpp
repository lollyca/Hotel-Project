#include "Header.h"
#include<array>

using namespace std;

void Room::setName(Room array[], int size, string name) {
	for (int i = 0; i < size; i++) {
		array[i].roomStyle = name;
	}
}

void Room::setNumber(Room array[], int size, int roomNumber) {
	for (int i = 0; i < size; i++) {
		array[i].roomNumber = i;
	}
}

void Room::setPrice(Room array[], int size, double price) {
	for (int i = 0; i < size; i++) {
		array[i].roomPrice = price;
	}
}

void Room::setCondition(Room array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i].isAvailable = true;
	}
}

void Room::setReservation(Room array[]) {
	array->isAvailable = false;
}






