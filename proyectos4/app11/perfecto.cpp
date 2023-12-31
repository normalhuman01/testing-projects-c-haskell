#include <iostream>
#include "perfecto.h"

bool perfect(int n) {
    return n == sumdiv(1, n);
}

int sumdiv(int divi, int n) {
    if (divi == n) {
        return 0;
    }
    if (n % divi == 0) {
        return divi + sumdiv(divi + 1, n);
    }
    return sumdiv(divi + 1, n);
}
