//
//  main.cpp
//  PRG-5-9-Hotel-Occupancy
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//
//  Write a program that calculates the occupancy rate for a hotel. The program should
//  start by asking the user how many floors the hotel has. A loop should then iterate once
//  for each floor. In each iteration, the loop should ask the user for the number of rooms
//  on the floor and how many of them are occupied. After all the iterations, the program
//  should display how many rooms the hotel has, how many of them are occupied, how
//  many are unoccupied, and the percentage of rooms that are occupied. The percentage
//  may be calculated by dividing the number of rooms occupied by the number of rooms.
//
//  NOTE: It is traditional that most hotels do not have a thirteenth floor. The loop in
//  this program should skip the entire thirteenth iteration.
//
//  Input Validation: Do not accept a value of less than 1 for the number of floors. Do not
//  accept a number less than 10 for the number of rooms on a floor.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int intHotelFloors,
        intHotelRooms,
        intHotelRoomsTotal,
        intHotelRoomsOccupied,
        intHotelRoomsOccupiedTotal,
        intHotelRoomsUnoccupiedTotal;
    
    float fltRoomsOccupiedPercentage;
    
    //Configure output for decimal value of hotel occupied percentage
    cout << setprecision(1) << fixed << showpoint;
    
    cout << "How many floors does the hotel have?\n";
    cin >> intHotelFloors;
    while(!cin || intHotelFloors < 1 || intHotelFloors > 250)
    {
        cout << "Please enter an integer value of floors from 1 to 250:\n";
        cin.clear();
        cin.ignore();
        cin >> intHotelFloors;
    }
    
    // Initialize counters
    intHotelRoomsTotal = 0;
    intHotelRoomsOccupiedTotal = 0;
    
    for(int i = 0 ; i < intHotelFloors ; i++)
    {
        if(i != 13) // Check floor each time incremented to check for 13th floor
        {
            cout << "How many rooms are on floor " << i << "?\n";
            cin >> intHotelRooms;
            
            intHotelRoomsTotal += intHotelRooms;
            
            cout << "How many rooms are occupied on floor " << i << "?\n";
            cin >> intHotelRoomsOccupied;
            
            while(intHotelRoomsOccupied > intHotelRooms)
            {
                cout << "You cannot have more occupied rooms than the total number of "
                     << intHotelRooms << endl
                     << "please enter in the total number of occupied rooms:\n";
                cin >> intHotelRoomsOccupied;
            }
            
            intHotelRoomsOccupiedTotal += intHotelRoomsOccupied;
        }
        else // Case for floor 13, nothing happens and is skipped
        {
            
        }
    }
    
    fltRoomsOccupiedPercentage = 100 * (static_cast<float>(intHotelRoomsOccupiedTotal) /
                                        static_cast<float>(intHotelRoomsTotal));
    
    intHotelRoomsUnoccupiedTotal = intHotelRoomsTotal - intHotelRoomsOccupiedTotal;
    
    cout << "The hotel has a total of " << intHotelRoomsTotal << " rooms.\n"
         << "The hotel has a total of " << intHotelRoomsOccupiedTotal << " occupied rooms.\n"
         << "The hotel has a total of " << intHotelRoomsUnoccupiedTotal << " unoccupied rooms.\n"
         << "The hotel has an occupancy rate of " << fltRoomsOccupiedPercentage << '%' << endl;
    
    return 0;
}




