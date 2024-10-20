#include "Serializer.hpp"
#include <iostream>

int main() {
    // Data構造体を作成
    t_data originalData = {"Test", 123};
    
    // Data構造体のアドレスをuintptr_tにシリアライズ
    uintptr_t serialized = Serializer::serialize(&originalData);
    
    // uintptr_tを再度Data構造体のポインタにデシリアライズ
    t_data* deserializedData = Serializer::deserialize(serialized);
    
    // シリアライズとデシリアライズの結果を確認
    std::cout << "Original Data Address: " << &originalData << std::endl;
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
    
    // デシリアライズ後のデータが元のデータと同じか確認
    std::cout << "Deserialized Data - Name: " << deserializedData->name << std::endl;
    std::cout << "Deserialized Data - Value: " << deserializedData->value << std::endl;

    return 0;
}
