#include <stdio.h>
#include <stdlib.h>

void min_max(char *array, char *max, char *max_p)
{
    __asm__
    (
        "movl $9, %%ecx\n\t"            
        "movq %0, %%r8\n\t"             
        "movb (%%r8), %%bl\n\t"         
        "movb $0, %%dl\n\t"             
    "maximum:\n\t"
        "addq $1, %%r8\n\t"             
        "addb $1, %%dl\n\t"             
        "cmpb %%bl, (%%r8)\n\t"         
        "jna lower\n\t"                 
        "movb (%%r8), %%bl\n\t"         
        "movb %%dl, (%%rdi)\n\t"        
    "lower:\n\t"
        "loop maximum\n\t"              
        "movb %%bl, (%%rsi)\n\t"        
    :
    :"arr"(array), "S"(max), "D"(max_p) 
    :"cc", "memory"                     
    );
}

int main()
{
    char array[] = {1, 6, 2, 3, 9, 5, 6, 7, 8};
    char *max, *max_p;
    max = (char *)malloc(1);
    max_p = (char *)malloc(1);
    min_max(array, max, max_p);
    printf("%d, %d\n", (int)*max, (int)*max_p);
    
    return 0;
}

