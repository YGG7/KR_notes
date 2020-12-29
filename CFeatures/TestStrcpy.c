//
// Created by Aurora on 2020/12/19.
//

void testEnd() {
    char zero = '\0';
    if (zero==0) printf("\\0==0");
    else printf("\\0==0");
}

void printCharArray(char* s) {
    while (*s) {
        printf("%c", *s);
        s++;
    }
    if (*s=='\0') printf("\\0");
    printf("|\n");
}

// unsafe, please make sure dst array is large enough
// and both dst and src end with '/0'
void myStrcpy(char* dst, const char* src) {
    while (*dst++ = *src++) ;
}

// unsafe, please make sure both dst and src end with '/0'
int myStrcmp(const char* dst, const char* src) {
    while (*dst++ == *src++) {
        if (*dst == '\0') return 0;
    }
    return *dst-*src;
}

void testCpyCmp() {
    char s1[] = "hello";
    char s1l[6] = "hello";
    char s2[] = "world";
    char s3[] = "language";
    char *s1p = "hello";
    char *s4p = "correction";
    char *s5p = "correction";
//    printf("comparison result (s1, s1l): %d\n", myStrcmp(s1, s3));
    printf("comparison result (s1, s1p): %d\n", strcmp(s1, s1p));
    printf("comparison result (s4p, s5p): %d\n", strcmp(s4p, s5p));

//    myStrcpy(s1, s3);
//    myStrcpy(s1l, s3);
//    printf("reassigned s1: %s|\n", s1);
//    printf("reassigned s1l: %s|\n", s1l);
//    printf("%d\n", sizeof(s1l));
    printCharArray(s1);
    printCharArray(s1p);
}