#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "CFeatures/TestVA.c"

int main() {
    testVA("This is a test for va", 18613, 18.613, 'c');
    double avg = avgVA(5, 1,8,6,1,3);
    printf("avg of {1,8,6,1,3}: %f\n", avg);
    return 0;
}