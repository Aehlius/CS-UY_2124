#include "std_lib_facilities.h"
#include "date.h"

int main(){
    Date today{2018, Month::jul, 20}; // a Date variable (a named object)
    int day = today.day();
    int month = today.month();
    int year = today.year();
    cout << "Today is " << day << " day; "
        << month << " month; " << year << " year\n";
    //cout << "Today is " << today.y << '/' << today.m << '/' << today.d << "\n";

    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);
    today.add_day(1);

    int day2 = today.day();
    int month3 = today.month();

    cout << "After adding 12 days, the day is " << day2 << " and month is " << month3 << '\n';
    today.add_month(1);
    int month2 = today.month();
    int year3 = today.year();
    cout << "After adding month, the month is " << month2 << " and year is " << year3 << '\n';
    today.add_year(1);
    int year2 = today.year();
    cout << "After adding year, the year is " << year2 << '\n';

    return 0;
}