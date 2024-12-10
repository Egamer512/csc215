static int days[2][3] ={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

day_of_year(year, month, day)
int year, month, day;
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i = 1; i < month; i++){
        day += days[leap][i];
    }
    return day;
}

month_day(year, yearday, pmonth, pday)
int year, yearday, *pmonth, *pday;
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > days[leap][i]; i++){
        yearday -= days[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
