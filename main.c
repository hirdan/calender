#include <stdio.h>
#include <stdlib.h>
int get_1st_weekday(int year)
{
   int day;
   day=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
   return day;
}
int main()
{
    system("color 3F");
    int year,month,days,daysinmonth,weekday=0,startingday;
    printf("\nEnter your desired year:");
    scanf("%d",&year);
    char *months[]={"January", "February","March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||(year%400==0))
        monthday[1]=29;
    startingday=get_1st_weekday(year);
    for(month=0;month<12;month++)
    {
        daysinmonth=monthday[month];
        printf("\n\n--------------------%s--------------------",months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");
       for(weekday=0;weekday<startingday;weekday++)
         printf("     ");
        for(days=1;days<=daysinmonth;days++)
        {
            printf("%5d",days);
            if(++weekday>6)
            {
                printf("\n");
                weekday=0;
            }
            startingday=weekday;
        }
    }
    return 0;
}
