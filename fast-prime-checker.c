#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool prime_check(int num)
{

    for (int k = sqrt(num); k > 1; k--)
    {
        if (num % k == 0)
        {
            return false;
        }
    }
    if (num < 2)
    {
        return false;
    }

    return true;
}

int main()
{
    int num = 0;
    int limit_list = 0;
    int count_times = 0;

    printf("Enter a number\n");
    printf(">> ");
    scanf("%d", &num);

    printf("\n\nLimit list to (int) values\n");
    printf(">> ");
    scanf("%d", &limit_list);

    while (limit_list >= num || limit_list <= 0)
    {
        printf("\nInvalid number (%d) try again\n", limit_list);
        printf(">> ");
        scanf("%d", &limit_list);
    }

    printf("\n");

    for (int i = num; i > 1; i--)
    {
        if (prime_check(i))
        {
            printf("%d\n", i);
            count_times++;
        }
        if (count_times == limit_list)
        {
            break;
        }
    }

    return 0;
}
