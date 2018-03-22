#ifndef calendar_H
#define calendar_H
#include <iostream>
#include <vector>
using namespace std;

class Calendar {
    public:
    bool ** calendar;
    int daysInFebruary;

    //constructor
    //sets up the dynamic array
    Calendar(int year);
    
    //Pre Condition: valid days are entered into the function in the form
    //               monthCheckedIN, DayCheckedIn, MonthCheckedOut, DayCheckedOut.
    //Post Condition: returns true if the span of days are available to be booked
    //               returns false if the span of days cannot be booked
    bool getDateAvailability(int month, int day, int monthEnd, int dayEnd);
    
    //Pre Condition: valid days are entered into the function in the form 
    //               monthCheckedIN, DayCheckedIn, MonthCheckedOut, DayCheckedOut.
    //Post Condition: returns amount of days booked and reserves date in calendar
    int reservedate(int month, int day, int monthEnd, int dayEnd);
    
    //Pre Condition: valid days are entered into the function in the form 
    //               monthCheckedIN, DayCheckedIn, MonthCheckedOut, DayCheckedOut.
    //Post Condition: cancels specified days in calendar
    void cancelreservation(int month, int day, int monthEnd, int dayEnd);
    
    //Pre Condition: input date in form monthCheckedIN, DayCheckedIn, MonthCheckedOut, DayCheckedOut.
    //Post Condition: couts invalide date if invalid otherwise does nothing.
    bool checkIfValidDate(int month, int day, int monthEnd, int dayEnd);
    
};
#endif // calendar_H