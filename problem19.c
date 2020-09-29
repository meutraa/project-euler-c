#include <stdio.h>

#define days_feb 28
#define days_feb_leap 29

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int abs_day = 0; /* monday 1 jan 1900 */

int main()
{
    int sundays = 0;      
    
    for(int year = 1900; year <= 2000; year++)
    {
        days[1] = (((year % 4) == 0 && (year % 100) != 0) || (year & 400) == 0) ? days_feb_leap : days_feb;
        for(int month = 0; month < 12; month++)
        {
            for(int day = 0; day < days[month]; day++)
            {
                if(abs_day % 7 == 6 && day == 0 && year != 1900)
                {
                    sundays++;
                }
                abs_day++;
            }
        }
    }
    
    printf("%d\n", sundays);
    return 0;
}
