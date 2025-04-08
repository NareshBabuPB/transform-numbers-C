#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_IN_WORDS_SIZE 1000
const char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char *places[] = {"","","Hundred","Thousand","","","Million","","","Billion","","","Trillion","","","Quadrillion","","","Quintillion"};

void transform(int num);
void transformNumber(int num, int place, char* numInWords);
void appendWithSpace(char* srcString, char* suffix);

int main() {
    int num;
    while(num != 0) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == 0) {
            printf("Zero\n");
            return 0;
        }

        transform(num);
    }
    
}

void transform(int num) {
    char numInWords[NUM_IN_WORDS_SIZE];
    strcpy(numInWords, "");

    if (num < 0) {
        strcat(numInWords, "Negative ");
    }

    transformNumber(abs(num), 0, numInWords);

    printf("%s\n", numInWords);    
}

void transformNumber(int num, int place, char* numInWords) {

    int remainingValue = 0;
    if(num >= 1000) {
        remainingValue = num % 1000;
        transformNumber(num/1000, place+3, numInWords);
    } else if (num >= 100) {
        remainingValue = num % 100;
        transformNumber(num/100, 2, numInWords);
    } else if(num >= 20){
        remainingValue = num % 10;
        appendWithSpace(numInWords, tens[num/10]);
    } else if(num >= 10){
        remainingValue = 0;
        appendWithSpace(numInWords, teens[num%10]);
    } else {        
        appendWithSpace(numInWords, ones[num]);
        appendWithSpace(numInWords, places[place]);
        return;
    }

    if(remainingValue < 100 && remainingValue > 10) {
        appendWithSpace(numInWords, "And");
    }

    if(remainingValue != 0) {
        transformNumber(remainingValue, 0, numInWords);
    } 
    appendWithSpace(numInWords, places[place]);
}

void appendWithSpace(char *srcString, char* suffix)
{
    if(suffix == ""){
        return;
    }

    size_t srcLen = strlen(srcString);
    if (srcLen < NUM_IN_WORDS_SIZE - 1) {
        snprintf(srcString + srcLen, NUM_IN_WORDS_SIZE - srcLen, "%s ", suffix);
    }
}
