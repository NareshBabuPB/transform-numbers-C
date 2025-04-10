#include <stdio.h>
#include <assert.h>
#include "transform_number.h"
#include "transform_number_test.h"
#include <string.h>

void test_appendWithSpace_valid_suffix() {
    char srcString[] = "twenty ";
    
    appendWithSpace(srcString, "hundred");
    
    assert(strcmp(srcString, "twenty hundred ") == 0);
}

void test_appendWithSpace_empty_suffix() {
    char srcString[] = "twenty ";
    
    appendWithSpace(srcString, "");
    
    assert(strcmp(srcString, "twenty ") == 0);
}

void test_appendWithSpace_null_suffix() {
    char srcString[] = "twenty ";
    
    appendWithSpace(srcString, NULL);
    
    assert(strcmp(srcString, "twenty ") == 0);
}

void test_transformNumber_zero() {
    char numInWords[] = "";
    
    transformNumber(0,0,numInWords);
    
    assert(strcmp(numInWords, "") == 0);
}

void test_transformNumber_negative() {
    char numInWords[] = "";
    
    transformNumber(-123,0,numInWords);
    
    assert(strcmp(numInWords, "Negative One Hundred And Twenty Three") == 0);
}

void test_transformNumber_single_digit() {
    char numInWords[] = "";
    
    transformNumber(1,0,numInWords);
    
    assert(strcmp(numInWords, "One") == 0);
}

void test_transformNumber_thousands() {
    char numInWords[] = "";
    
    transformNumber(23493,0,numInWords);
    
    assert(strcmp(numInWords, "Twenty Three Thousand Four Hundred And Ninety Three") == 0);
}

void run_appendWithSpace_tests() {
    test_appendWithSpace_valid_suffix();
    test_appendWithSpace_empty_suffix();
    test_appendWithSpace_null_suffix();
}

void run_transformNumber_tests() {
    test_transformNumber_zero();
    test_transformNumber_negative();
    test_transformNumber_single_digit();
    test_transformNumber_thousands();
}

int main() {
    run_appendWithSpace_tests();
    run_transformNumber_tests();

    printf("All tests passed.\n");
    return 0;
}