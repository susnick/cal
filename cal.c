#include <stdio.h>
#include <time.h>
#include <windows.h>


#define true 1
#define false 0
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31;1;4m"
#define KGRN  "\x1B[32m"
#define KREDU "\x1B[31;1;4m"

int enable_vt_mode();

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

	//enable colors in cmd.exe
	
	if (enable_vt_mode() == 0)
	{
		printf("Unable to enter VT processing mode\n");
		return -1;
	}
	
    printf("%s Mo Tu We Th Fr Sa Su%s\n", KREDU, KNRM);

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

int enable_vt_mode()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("Error - %d\n", GetLastError());
		return false;
	}
	DWORD dwMode = 0;
	int gotconsolemode = GetConsoleMode(hOut, &dwMode);

	if (!gotconsolemode)
	{
		printf("Error - %d", GetLastError());
		return false;
	}
	dwMode |= 0x0004;
	if (!SetConsoleMode(hOut, dwMode))
	{
		printf("Error - %d", GetLastError());
		return false;
	}
	return true;
}
