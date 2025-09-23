#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// en.wikipedia.org/wiki/Bubble_sort
// more advanced integer bubble sort using pointers and dynamic memory


int comp(int x, int y){
    if(x > y)
        return 0; // left greater (desc)
    else
        return 1; // right gtr (asc)
}

int abs_comp(int x, int y){
    if(abs(x) > abs(y))
        return 0;
    else
        return 1;
}

//                                      🔽 function pointer for sort order        
void bubble_sort(int *A, int num, int (*func)(int, int), char order){
    int flag; // makes < > dynamic

    switch(order){
        case 'a':
            flag = 1;
            break;
        default:
            flag = 0;
    } 

    int temp;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num-1; j++){  
           if(func(A[i], A[j]) == flag){    // bubble sort > or < determines asc or desc           
                temp = A[i];
                A[i] = A[j]; // temp to replc both vars
                A[j] = temp;
            }          
        }
    }
}


int main()          
{
    int size;
    printf("how many items will you list?: "); scanf("%d", &size);
    printf("\n");

    // 🔽 malloc for dynamic size
    int *arr = (int*)malloc(size*sizeof(int)); // sizeof for dynamic use (int size may vary across compilers)

    bool incl_neg = false; // if theres a negative else abs doesn't matter
    for(int i = 0; i < size; i++){
        printf("item %d > ", i+1); scanf("%d", arr+i); // ◀ alternative to arr[i]
        if(arr[i] < 0){
            incl_neg = true;
        }
    }

    printf("\n");
    char order;

    printf("ascending or descending order? (a,d): "); scanf(" %c", &order);
    
    int (*comp_func)(int,int); // holds the function we will use
    comp_func = comp; // defualts to normal not abs func
   
    if(incl_neg){
        char sort_abs_choice;
        printf("sort negative numbers by absolute value (ie. ignore negative sign) (y,n)?: "); scanf(" %c", &sort_abs_choice);
        if(sort_abs_choice == 'y'){
            comp_func = abs_comp; // set the func we will use to abs func
        }
    }

    //                    //🔽 add function name for the func pointer (comp_func same as &comp_func)
    bubble_sort(arr, size, comp_func, order);

    for(int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    
    
    
    printf("\n\nexit code = 0"); // optional exit code
    return 0;
}
