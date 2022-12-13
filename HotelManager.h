#include "RoomHeader.h"
#include <array>

const int totalRooms = 122;

class HotelManager
{
	public:
		string todayDate;
		
		array<Room, totalRooms> hotelArray;

		HotelManager();
		void displayInventory();
		void roomReservation();
		void getTotal();
		int countAvailableRooms(string type);
		int getTotalRevenue();
		Room bookFirstAvailable(string type, string client);
		void saveData();
		void showDay(string date);
};
