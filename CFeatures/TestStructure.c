//
// Created by Aurora on 2020/12/22.
//

struct Point {
    double x;
    double y;
    void (*incrementX)(struct Point *p, double i);
    void (*incrementY)(struct Point *p, double i);
};

void incrementPointX(struct Point *p, double i) {
//    (*p).x += i;
    p->x += i;
}

void incrementPointY(struct Point *p, double i) {
//    (*p).y += i;
    p->y += i;
}

void testStructure() {
    struct Point p1 = {.x=1.0, .y=2.0, .incrementX=incrementPointX, .incrementY=incrementPointY};
    (*p1.incrementX)(&p1, 2.5);
    printf("p1.x = %f\n", p1.x);
    printf("p1.y = %f\n", p1.y);
}