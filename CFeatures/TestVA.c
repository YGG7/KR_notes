//
// Created by Aurora on 2020/12/25.
//
#include <stdarg.h>

void testVA(char *s, ...) {
    va_list ap;
    va_start(ap, s);
    int ival = va_arg(ap, int);
    double dval = va_arg(ap, double);
    char cval = va_arg(ap, char);
    printf("%s\n", s);
    printf("%d\n", ival);
    printf("%f\n", dval);
    printf("%c\n", cval);
    va_end(ap);
}

// may lead to numerical overflow
double avgVA(int num_count, ...) {
    va_list ap;
    va_start(ap, num_count);
    int sum = 0;
    for (int i=0; i<num_count; i++) {
        sum += va_arg(ap, int);
    }
    return (double)sum/num_count;
}