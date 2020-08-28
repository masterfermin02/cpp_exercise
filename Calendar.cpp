/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>

using namespace std;

int CalcDayNumFromDate(int y, int m, int d)
{
  m = (m + 9) % 12;
  y -= m / 10;
  int dn = 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1);

  return dn;
}

bool isLeap(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int dayOfWeekIndex(int year, int month, int day) {
    return CalcDayNumFromDate(year, month, day) % 7;
}

void printSpace(int num) {
    for (int i = 0; i < num; i++) {
        cout<<" ";
    }
}

void printdayOfTheWeek(int weekSize) {
    std::string days_of_week[] = {
    "We",
    "Th",
    "Fr",
    "Sa",
    "Su",
    "Mo",
    "Tu"
   };
    for (int i = 0; i < weekSize; i++) {
        int index = (i + 4) % weekSize;
        cout<< days_of_week[index];
        printSpace(1);
    }
}

void drawMonth(int month, string *month_names, int year, int startDayIndex, int column) {
    int days_to_month[2][12] = {
         // non-leap year
         { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 },
         // leap year
         { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 },
    };
    
    int days_of_month[2][12] = {
      // non-leap year
      { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
      // leap-year
      { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    };
    std::string days_of_week[] = {
    "We",
    "Th",
    "Fr",
    "Sa",
    "Su",
    "Mo",
    "Tu"
   };
    
    printSpace(5);
    cout<<month_names[month];
    cout<<"\n";
    printdayOfTheWeek(7);
    cout<<"\n";
    int monthDays = days_of_month[isLeap(year)][month];
    int margin = 9;
    printSpace(column * 3 - 1);
    for (int i = 0; i < monthDays; i++) {
        
        if ( i + 1 < 10) {
            printSpace(1);
        }
        
        if (column > 0 && column % 7 == 0) {
            cout<<"\n";
        }
        
        cout <<i+1 << " ";
        
        
        
        column++;
    }
    cout<<"\n";
}

void drawCalendar(int year) {
   
   std::string month_names[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
   };
   int weekIndex[] = {
       3,
       4,
       5,
       6,
       7,
       1,
       2
   };
    
    for (int month = 0; month < 12; month++) {
        int startDayIndex = dayOfWeekIndex(year, month + 1, 1);
        drawMonth(month, month_names, year, startDayIndex, weekIndex[startDayIndex]);
    }
}

int main()
{
    int year;
    cout<< "Digite el anio del calendario deseado: ";
    cin >> year;
    drawCalendar(year);
    return 0;
}
