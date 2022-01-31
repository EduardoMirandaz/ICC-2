#include <stdio.h>
#include <stdlib.h>
#include "dots.h"


int main(void){

    int n;
    float x, y;
    DOT* dots = NULL; 

    if(!scanf("%d", &n)) exit(0);
    dots = create_dots(n);

    for (int i = 0; i < n; i++)
    {
        if(!scanf("%f", &x)) exit(0);
        if(!scanf("%f", &y)) exit(0);
        insert_dots(dots, x, y, i);
    }
    manage_distances(dots, n);
    free(dots);
}

