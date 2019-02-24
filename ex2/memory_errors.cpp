#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void fn() {
    int* x = new int[10];
    printf("%d", *x);
    x[10] = 0;
}

int main() {
    fn();
    return 0;
}
