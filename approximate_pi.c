#include <stdio.h>

// pi approximator in c to 5th decimal 

// caclulate pi from Gregory-Leibniz Series en.wikipedia.org/wiki/Leibniz_formula_for_π
// 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/15
// - + - + odd numbers denominator from 3 to infinity
// equates to pi/4 multiply by 4 to get pi

int main()          
{
    int iter;
    printf("enter iterations: "); scanf("%d", &iter);

    float divis, pi = 1; // denominator
    for(int i = 1; i <= iter; i++){
        // 1 + 1 = 2 + 1 = 3 2 + 2 = 4 + 1 + 5
        divis = 1.0/(i + i + 1); // to get odd number for denominator then dvide by 1

        // alternate - then +
        if(i % 2 == 0){
            pi += divis;
        }
        else{
            pi -= divis;
        }

    }

    printf("\npi = %.10f", pi*4); // *4 as it return p1/4



    return 0;
}
