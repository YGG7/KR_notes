//
// Created by Aurora on 2020/12/23.
//

typedef struct S1 {
    int i;
    // can only declare one flexible array member
    // and the declaration must be at the end of the structure
    char s[];
} S1;

typedef struct S2 {
    int i;
} S2;

typedef struct S3 {
    int i;
    char s[10];
} S3;

typedef struct S4 {
    int i;
    char *s;
} S4;

typedef struct S5 {
    int i;
    int j;
    char s[];
} S5;

void testFAM() {
    int lchar = sizeof(char);
    int lcharp = sizeof(char*);
    int l1 = sizeof(S1);
    int l2 = sizeof(S2);
    int l3 = sizeof(S3);
    int l4 = sizeof(S4);
    int l5 = sizeof(S5);
    printf("test over");
}

