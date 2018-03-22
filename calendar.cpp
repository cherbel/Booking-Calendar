#include <iostream>
#include <vector>
#include "calendar.h"

using namespace std;

Calendar::Calendar(int year){
        
        //sets amount of months
        calendar = new bool*[12];
        
        //sets days in calendar
        calendar[0] = new bool[31];
        fill_n(calendar[0], 31, true);
        //leap year calculations
        if((year % 4 == 0) && (year % 100 != 0 || year & 400 == 0)) { 
            calendar[1] = new bool[29];
            fill_n(calendar[1], 29, true);
            daysInFebruary = 29;
        }else{
            calendar[1] = new bool[28];
            fill_n(calendar[1], 28, true);
            daysInFebruary = 28;
        }
        calendar[2] = new bool[31];
        fill_n(calendar[2], 31, true);
        calendar[3] = new bool[30];
        fill_n(calendar[3], 30, true);
        calendar[4] = new bool[31];
        fill_n(calendar[4], 31, true);
        calendar[5] = new bool[30];
        fill_n(calendar[5], 30, true);
        calendar[6] = new bool[31];
        fill_n(calendar[6], 31, true);
        calendar[7] = new bool[31];
        fill_n(calendar[7], 31, true);
        calendar[8] = new bool[30];
        fill_n(calendar[8], 30, true);
        calendar[9] = new bool[31];
        fill_n(calendar[9], 31, true);
        calendar[10] = new bool[30];
        fill_n(calendar[10], 30, true);
        calendar[11] = new bool[31];
        fill_n(calendar[11], 31, true);

}

bool Calendar::getDateAvailability(int month, int day, int monthEnd, int dayEnd){
    month--;
    monthEnd--;
    int monthTemp = month, daysInMonth;
    while(monthTemp <= monthEnd ){
        //determines days to examine for specific month
        if(monthTemp == 3 || monthTemp == 5 || monthTemp == 8 || monthTemp == 10){
            daysInMonth = 30;
        }else if(monthTemp == 1) {
            daysInMonth = daysInFebruary;
        }else{
            daysInMonth = 31;
        }
        //finds if time period is empty
        if(month == monthEnd){
            for(int i = day - 1; i < dayEnd - 1; i++){
                if(calendar[monthTemp][i] == false){
                    return false;
                }
            }
        }else if(monthTemp == month){
            for(int i = day - 1; i < daysInMonth; i++){
                if(calendar[monthTemp][i] == false){
                    return false;
                }
            }
        }else if(monthTemp == monthEnd){
            for(int i = 0; i < dayEnd - 1; i++){
                if(dayEnd - 2 >= 0){
                   if(calendar[monthTemp][i] == false){
                        return false;
                    } 
                }
            }
        }else{
            for(int i = 0; i < daysInMonth; i++){
                if(calendar[monthTemp][i] == false){
                        return false;
                } 
            }
        }
    monthTemp++;
    }
    return true;
}

int Calendar::reservedate(int month, int day, int monthEnd, int dayEnd){
    month--;
    monthEnd--;
    int monthTemp = month, daysStayed = 0, daysInMonth;
    while(monthTemp <= monthEnd){
        //finds days in month to write to
        if(monthTemp == 3 || monthTemp == 5 || monthTemp == 8 || monthTemp == 10){
            daysInMonth = 30;
        }else if(monthTemp == 1) {
            daysInMonth = daysInFebruary;
        }else{
            daysInMonth = 31;
        }
        //decides what to fill in month
        if(month == monthEnd){
            for(int i = day - 1; i < dayEnd - 1; i++){
                calendar[monthTemp][i] = false;
                daysStayed++;
            }
        }else if(monthTemp == month){
            for(int i = day - 1; i < daysInMonth; i++){
                calendar[monthTemp][i] = false;
                daysStayed++;
            }
        }else if(monthTemp == monthEnd){
            for(int i = 0; i < dayEnd - 1; i++){
                if(dayEnd - 2 >= 0){
                     calendar[monthTemp][i] = false;
                     daysStayed++;
                }
            }
        }else{
            for(int i = 0; i < daysInMonth; i++){
                calendar[monthTemp][i] = false;
                daysStayed++;
            }
        }
    monthTemp++;
    }
    return daysStayed;
}

void Calendar::cancelreservation(int month, int day, int monthEnd, int dayEnd){
    month--;
    monthEnd--;
    int monthTemp = month, daysInMonth;
    while(monthTemp <= monthEnd){
        //finds days in month to write to
        if(monthTemp == 3 || monthTemp == 5 || monthTemp == 8 || monthTemp == 10){
            daysInMonth = 30;
        }else if(monthTemp == 1) {
            daysInMonth = daysInFebruary;
        }else{
            daysInMonth = 31;
        }
        //cancels reservation
        if(month == monthEnd){
            for(int i = day - 1; i < dayEnd - 1; i++){
                calendar[monthTemp][i] = true;
            }
        }else if(monthTemp == month){
            for(int i = day - 1; i < daysInMonth; i++){
                calendar[monthTemp][i] = true;
            }
        }else if(monthTemp == monthEnd){
            for(int i = 0; i < dayEnd - 1; i++){
                if(dayEnd - 2 >= 0){
                     calendar[monthTemp][i] = true;  
                }
            }
        }else{
            for(int i = 0; i < daysInMonth; i++){
                calendar[monthTemp][i] = true;
            }
        }
    monthTemp++;
    }
}

bool Calendar::checkIfValidDate(int month, int day, int monthEnd, int dayEnd){
    //checks if months are valid
    //checks to make sure your not trying to book backwards or negative days
    if(month > 12 || monthEnd > 12 || monthEnd < month || month < 1 || monthEnd < 1
       || (month == monthEnd && day > dayEnd) || day < 1 || dayEnd < 1 || (month == monthEnd && day == dayEnd)){
       return false; 
    }
    //checks day in validity
    if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            return false;
        }
    }else if(month == 2) {
        if(day > daysInFebruary){
            return false;
        }
    }else{
        if(day > 31){
            return false;
        }
    }
    //checks day out validity
    if(monthEnd == 4 || monthEnd == 6 || monthEnd == 9 || monthEnd == 11){
        if(dayEnd > 30){
            return false;
        }
    }else if(month == 2) {
        if(dayEnd > daysInFebruary){
            return false;
        }
    }else{
        if(dayEnd > 31){
            return false;
        }
    }
    return true;
}