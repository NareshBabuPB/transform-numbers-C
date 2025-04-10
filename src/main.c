#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "transform_number.h"

int main() {
    long num;
    char buffer[100];
    char *endptr;
    printf("Number to word transformer. Enter 0 to exit.\n");

    do {
        printf("Enter a number: ");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            errno = 0;  // Clear errno before conversion
            num = strtol(buffer, &endptr, 10);

            // Error checks:
            if ((endptr == buffer) || (*endptr != '\n' && *endptr != '\0')) {
                printf("Invalid input. Retry...\n");
                continue;
            } else if ((num == LONG_MAX || num == LONG_MIN) && errno == ERANGE) {
                printf("Number out of range for long. Retry...\n");
                continue;
            } 

            transform(num);
        } else {
            printf("Input error. Retry...\n");
        }
    } while(num != 0);
}