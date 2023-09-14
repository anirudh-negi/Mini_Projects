//this programm is for adding dates to a particular date entered by the user for eg-user enters 03 14 2019 and days to add 50 then the output should be 04 23 2019.



#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if (*mm == 2 && is_leap_year(*yy)) {
            days_in_month[*mm] += 1;
        } 
        if(*dd > days_in_month[*mm] ){
            printf("ENTER VALID NUMBER OF DAYS IN RESPECTIVE MONTH/n");
            return;
        }
    while (days_left_to_add > 0) {
    

        int days_left_in_month= days_in_month[*mm] - *dd;

        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= days_left_in_month+1;
            *dd = 1;

            if (*mm == 12) {
                *mm = 1;
                *yy += 1;
            } else {
                *mm += 1;
            }
        } else {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main() {
    int dd, mm, yy, days_left_to_add;
    printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date:\n");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);

    if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yy < 1800 || yy > 10000) {
        printf("Invalid input. Please enter a valid date and year between 1800 and 10000.\n");
    } else {
        add_days_to_date(&mm, &dd, &yy, days_left_to_add);
        printf("%d %d %d\n", mm, dd, yy);
    }

    return 0;
}
