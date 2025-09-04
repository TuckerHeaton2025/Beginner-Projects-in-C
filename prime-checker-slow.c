#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
*   READ ME
*   
*   What are primes?
*       Primes are numbers that are only divisible by 1 and themselves.
*       The number 17 is a prime because it not evenly divisible.
*
*   How to check if a number is prime?
*       Using the modulus operator along with a for loop is the most practical way.
*       With the modulus operator we can find the remainder of any divison.
*       If this returns 0 and the number is not 1 or itself the number is not prime.
*       
*       For numbers under 25 you could simply check if its divisible by 2 or 3 if it is its
*       not a prime.
*       Past that we will need to use a for loop to go through every number below x and
*       see if x is divisble by that number.
*
*       Below I wrote some sample code you can try in order to understand this better
*       To test it simply run the code and follow the prompt.                 
*/

int main()
{
    char move_on = '\0';
    printf("Test the code? (y/n): "); scanf("%c", &move_on);
    move_on = tolower(move_on);
    if(move_on == 'y')
    // What the code is doing 👇
    {   
        printf("\n");

        int num = 20;

        for (int i = num; i > 1; i--)  // We decrement the i (the number) but exclude 1 becuase its not a prime.
        {
            printf("%d ", i); // We list the current value of i we are checking here

            for (int k = i; k > 1; k--) // We list every number under the current value of (i)
            {
                if (i % k == 0 && i != k) // If (i) is divisible by (k) ie modulus returns 0 
                {                         // AND (k) is not the same number as (i) we will print(k)

                    printf("%d ", k); // This will now list what numbers (i) is divisible by, check it out!;
                }
            }
            printf("\n"); // New line for readiblity
        }

        /*
        *   As you can see it lists the numbers (i) is divisible by, however we just need to know that (i)-
        *   is divisible by one other number besides itself and 1. What could we add that would fix this? 
        *   👇
        */
    }
    else
    {
        // Main progam
        printf("  ___     _              ___              _           \n"
                " | _ \\_ _(_)_ __  ___   / __|___ _  _ _ _| |_ ___ _ _ \n"
                " |  _/ '_| | '  \\/ -_) | (__/ _ \\ || | ' \\  _/ -_) '_|\n"
                " |_| |_| |_|_|_|_\\___|  \\___\\___/\\_,_|_||_\\__\\___|_|\n\n\n");

        int num = 0;
        int prime_count = 0;
        char list = '\0';
        char desc_or_asc = '\0';

        printf("Enter a number\n\n");
        printf(">> "); scanf("%d", &num);
        printf("\n");
        printf("List the primes (y/n): "); scanf(" %c", &list);
        list = tolower(list);

        if(list == 'y')
        {
            printf("\n(a) for ascending, any other key for desceding\n\n"); printf(">> "); scanf(" %c", &desc_or_asc);
            printf("\n");
        }
        

        if(desc_or_asc == 'a')
        {
            for(int i = 2; i <= num; i++) // We start from 2 and go up so we can list the numbers in ascending order
            {
                bool is_prime = true; // We assume the number is a prime and below we check if thats wrong

                for(int k = i; k > 1; k--)
                {
                    if(i % k == 0 && i != k) // if this is true its not a prime
                    {
                        is_prime = false;
                        break; // Thats right a break statement, this will make the program a lot faster
                    }
                }

                if(is_prime)
                {
                    prime_count++;
                    printf("%d\n", i);
                }
            }
        }
        else
        {
            for(int i = num; i > 1; i--) // Now we start at that given number and go down from it
            {
                bool is_prime = true;

                for(int k = i; k > 1; k--)
                {
                    if(i % k == 0 && i != k)
                    {
                        is_prime = false;
                        break;
                    }
                }

                if(is_prime)
                {
                    prime_count++;
                    if(list == 'y')
                    {
                        printf("%d\n", i);
                    }
                }
            }
        }
        if(list == 'y')
        {
            printf("\n%d primes were listed\n", prime_count);
        }
        else
        {
            printf("\n%d primes found\n", prime_count);
        }
    }

    return 0;

}
