#include "Base.hpp"
#include <iostream>

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {}
}

int main() {
    // ランダムに生成されたオブジェクトを指すBase*型ポインタ
    Base* obj = generate();
    
    // ポインタを使った型の識別
    std::cout << "Identifying with pointer: ";
    identify(obj);
    
    // 参照を使った型の識別
    std::cout << "Identifying with reference: ";
    identify(*obj);
    
    // メモリの解放
    delete obj;

    return 0;
}
