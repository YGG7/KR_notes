#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "CFeatures/TestString.c"
#include "CFeatures/TestStrcpy.c"

int main(int argc, char *argv[]) {
    testCpyCmp();
    return 0;
}