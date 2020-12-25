//
// Created by Aurora on 2020/12/19.
//
void testArrayPointer() {
    int arr[] = {1,8,6,1,3};
    int arrLen = sizeof(arr)/sizeof(int);
    int* p = arr;
    for (int i=0; i<arrLen; i++) {
        printf("arr[%d] %d %p\n", i, *(p+i), p+i);
    }
    printf("size of int: %d\n", sizeof(int));
    // arr++; // it is invalid
}

void testMultiD() {
    int arr[4][3][2] = {
            {{0,2},{0,4},{0,6}},
            {{1,2},{1,4},{1,6}},
            {{2,2},{2,4},{2,6}},
            {{3,2},{3,4},{3,6}}
    };
//    int arr2[4][3][2] = arr; // illegal syntax, don't do this
    int* p  = arr; // a pointer to the first element of arr
    int* pa[3] = {7}; // an array of 5 pointers, initialized with address 0
    int (*parr0)[4][3][2] = arr; // a pointer to arr
    int (*parr1)[3][2] = arr[3]; // a pointer to arr[3], which is a 3x2 array

    printf("sizeof(arr): %d\n", sizeof(arr));
    printf("sizeof(p): %d\n", sizeof(p));
    printf("sizeof(pa): %d\n", sizeof(pa));
    printf("sizeof(parr0): %d\n", sizeof(parr0));
    printf("sizeof(parr1): %d\n", sizeof(parr1));
    for (int i=0; i< sizeof(pa)/sizeof(int*); i++) {
        printf("pa[%d]: %p\n", i, pa[i]);
    }
    printf("arr[3][0][0] address: %p\n", arr+3);
    printf("arr[3][1][1] value: %d\n", *(*(*(arr+3)+1)+1));
    printf("arr[3][1][1] value: %d\n", *(*(*(arr+3)+1)+1));
    printf("parr1 value: %p\n", parr1);
    printf("parr1[%d][%d] value: %d\n", 1,1,(*parr1)[1][1]);

    printf("iteration of parr0 pointed array: ");
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<2; k++) {
                printf("%d ", (*parr0)[i][j][k]);
            }
        }
    }
}

void testDiff() {
    int arr[] = {1,8,6,1,3};
    int* p = arr;
    printf("sizeof(arr): %d\n", sizeof(arr));
    printf("sizeof(p): %d\n", sizeof(p));
}

void testLimitDiff() {
    char s1[] = "hello";
    char* s2 = "hello";
    char* s3 = s1;
    for (int i=0; i<15; i++) {
        printf("%c",*(s1+i));
    }
    printf("\n");
    for (int i=0; i<15; i++) {
        printf("%c",*(s2+i));
    }
    printf("\n");
    for (int i=0; i<15; i++) {
        printf("%c",*(s3+i));
    }
    printf("\n");

}
