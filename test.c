#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#define UNIQUE_SIZE 1000



int make_unique_number();
int main()
{
    int my_unique;
    my_unique = make_unique_number();

    printf("%d", my_unique);
    return 0;
}

int make_unique_number()
{    
    // int rotto[SIZE];
    int r_number;
    int flag;
    int unique_number_list[UNIQUE_SIZE];
  
    srand((unsigned)time(NULL));

    r_number = (rand()% UNIQUE_SIZE) +1; 

    // is_in 을 호출해야함 
    for (int i=0; i<=sizeof(unique_number_list)/sizeof(int) ;i++)
    {
        if (r_number!= unique_number_list[i])
        {    
            unique_number_list[i] = r_number;            
        }
        
    }
    return r_number;
}
    
