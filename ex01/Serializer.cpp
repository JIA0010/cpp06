#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(t_data* ptr) {
    // t_data型ポインタをuintptr_t型に変換して返す
    return reinterpret_cast<uintptr_t>(ptr);
}

t_data* Serializer::deserialize(uintptr_t raw) {
    // uintptr_t型をt_data型のポインタに戻す
    return reinterpret_cast<t_data*>(raw);
}
