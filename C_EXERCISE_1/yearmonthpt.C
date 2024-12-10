#include <stdio.h>

static int days[2][3] ={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

day_of_year(year, month, day)
int year, month, day;
{
    int leap;
    int *point;
    int i;
    i = 0;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    point = *(days + leap); /* points to the first element of days array */
    for (i = 1; i < month, i++){
        day += *(p+i);
    }
    return day;

}