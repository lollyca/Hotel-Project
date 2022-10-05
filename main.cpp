#include "Header.h"

int main()
{
    Hotel courtyard(70, 125, "Courtyard");
    Hotel scenic(35, 145, "Scenic");
    Hotel suite(15, 350, "Suite");
    Hotel penthouse(2, 1135, "Penthouse");

    cout << setw(25) << "HOTEL INVENTORY" << endl;
    cout << setw(15) << left << "ROOM STYLE" << setw(2) << "PRICE" << setw(10) << right << "ROOMS" << endl;
    courtyard.displayInventory();
    scenic.displayInventory();
    suite.displayInventory();
    penthouse.displayInventory();
    cout << "\n";
    courtyard.roomReservation(4);
    cout << "\n";
    courtyard.roomRevenue(); 
    cout << "\n";
    courtyard.roomReservation(1);
    cout << "\n";
    courtyard.roomRevenue();
    cout << "\n";
    suite.roomReservation(2);
    cout << "\n";
    suite.roomRevenue();
}


