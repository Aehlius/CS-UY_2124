#include "std_lib_facilities.h"
#include "date.h"

vector<int> last_day{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> last_leap_day{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> month_name{"", "January", "February", "March", "April". "May",
    "June", "July", "August", "September", "October", "November", "December"}

bool Date::is_valid(){
    if (y<0) return false;
    if (m>12) return false;
    //if (isleapyear()) return leapyear();
    if (d > last_day[m]) return false;
    return true;
/*
    if (y < 0) return false;
    switch (int(m)){
    case 2:
        return d <= 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return d <= 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return d <= 30;
    default:
        return false;
    }*/
}


Date::Date(int yy, Month mm, int dd)     // constructor
:y{yy}, m{mm}, d{dd}                    // note: member initializers
{
if (not is_valid()){
    throw Invalid{};
    }
}
void Date::add_day(int n){
    while (n > last_day[m]){
        //loop thru vector of days and subtract


        }
    }

void Date::add_month(int n){
    m = (m==Month::dec) ? jan : Month(int(m)+1);   // “wrap around”
    if (m == Month::jan) ++y;
    }

void Date::add_year(int n){
    ++y;
    }

int Date::year(){
    return y;
    }

Month Date::month(){
    return m;
    }

int Date::day(){
    return d;
    }
