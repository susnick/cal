#include <stdio.h>
#include <time.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dayofmonth = tm.tm_mday;
	tm.tm_mday = 1;
	mktime(&tm);

    int days_in_month = 0;
	int year = 1900 + tm.tm_year;
    int i, x;
	int february_days = ((year % 400) == 0 || ((year % 100) != 0 && (year % 4) == 0)) ? 29 : 28;
	int month[] = {31, february_days, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	days_in_month = month[tm.tm_mon];


	//struct tm first = {0, 0, 0,  1, tm.tm_mon, tm.tm_year};
	//mktime(&first);

//	printf("First day of month falls on: %d\n",first.tm_wday);
//	printf("Current day is : %d\n", tm.tm_mday);
    printf("%s Mo Tu We Th Fr Sa Su%s\n", KRED, KNRM);

	for (x = 1; x < tm.tm_wday;x++)
	{
		printf("   ");
	}

    for (i = 1;i <= days_in_month;i++)
    {

        if (dayofmonth == i)
        {
            printf("%s%3d%s", KGRN, i, KNRM);
        }
        else
        {
            printf("%3d", i);
        }
		if ((i + tm.tm_wday - 1) % 7 == 0)
		{
			printf("\n");
		}


    }
    return 0;
}
