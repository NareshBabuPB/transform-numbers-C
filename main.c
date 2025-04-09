#include <stdio.h>
#include <stdlib.h>
#include "transform_number.h"

int main() {
    int num;
    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == 0) {
            printf("Zero\n");
            return 0;
        }

        transform(num);
    } while(num != 0);
    
}