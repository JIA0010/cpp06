#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base() {}  // 仮想デストラクタ
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate();

#endif
