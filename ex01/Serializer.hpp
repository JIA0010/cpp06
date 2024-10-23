#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>
#include <iostream>

typedef struct s_data {
    std::string name;
    int value;
}t_data;
class Serializer {
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
public:
    // オブジェクトをuintptr_tにシリアライズする
    static uintptr_t serialize(t_data* ptr);

    // uintptr_tをオブジェクトのポインタにデシリアライズする
    static t_data* deserialize(uintptr_t raw);
};

#endif
