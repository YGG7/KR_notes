//
// Created by Aurora on 2020/12/18.
//

#define paste(front, back) front ## back

int myStrlen(char *s) {
    int len = 0;
    while (*s++) {
        len++;
    }
    return len;
}

void testString() {
    char s1[6] = "hello";
    char s2[6] = {'h','e','l','l','o','\0'};
    char s3[6] = "olleh";
    char* s4 = "hello";
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",s3);
    printf("%s\n\n",s4);

    printf("len_s1=%d\n", myStrlen(s1));
    printf("len_s4=%d\n", myStrlen(s4));
//    printf("%s\n",paste(s,3));
//    strncpy(s3, "hello", 6);
//    printf("%s\n",s3);
}

