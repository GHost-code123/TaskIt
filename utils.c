#include <time.h>

static int	isleap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int	isvalid_date(struct tm *date)
{
	int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date->tm_year <= 0)
        return 0;

    if (date->tm_mon < 1 || date->tm_mon > 12)
        return 0;

    if (date->tm_mon == 2 && isleap(date->tm_year)) {
        if (date->tm_mday < 1 || date->tm_mday > 29)
            return 0;
    }
    else {
        if (date->tm_mday < 1 || date->tm_mday > month_day[date->tm_mon - 1])
            return 0;
    }

    return 1;
}
