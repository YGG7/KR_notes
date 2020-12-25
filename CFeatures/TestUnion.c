//
// Created by Aurora on 2020/12/24.
//

typedef union u1 {
    int i;
    long l;
    char s[20];
} u1;

typedef union u2 {
    int i;
    long l;
    char s[24];
} u2;

typedef union u3 {
    int i;
    long l;
    char s[25];
} u3;

void testUnion() {
    int lu1 = sizeof(u1);
    int lu2 = sizeof(u2);
    int lu3 = sizeof(u3);
    printf("sizeof(u1): %d\n", lu1);
    printf("sizeof(u2): %d\n", lu2);
    printf("sizeof(u3): %d\n", lu3);
}