#include "Base.hpp"
#include <cstdlib>  // rand()とsrand()のために必要
#include <ctime>    // 時間をシードに使うために必要

Base* generate() {
    srand(time(0));
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}