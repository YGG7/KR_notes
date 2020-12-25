//
// Created by Aurora on 2020/12/15.
//

void testSwitch() {
    int testArr[] = {1,6,6,9,3,4,7,4};
    const int arrLen = 8;
    int countLess5 = 0, countMore5 = 0;

    for (int i = 0; i<arrLen; i++) {
        switch (testArr[i]) {
            case 0: case 1: case 2: case 3: case 4:
                countLess5++;
                break;
            case 5: case 6: case 7: case 8: case 9:
                countMore5++;
                break;
        }
    }
    printf("number of values less than 5: %d\n", countLess5);
    printf("number of values equal or more than 5: %d\n", countMore5);
}
