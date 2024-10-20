#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        printChar(literal);
    } else if (isInt(literal)) {
        printInt(literal);
    } else if (isFloat(literal)) {
        printFloat(literal);
    } else if (isDouble(literal)) {
        printDouble(literal);
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';  // すべてが数字である場合
}

bool ScalarConverter::isFloat(const std::string& literal) {
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';  // f で終わる場合
}

bool ScalarConverter::isDouble(const std::string& literal) {
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';  // 最後まで正しい double 形式
}

void ScalarConverter::printChar(const std::string& literal) {
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(const std::string& literal) {
    int i = std::strtol(literal.c_str(), NULL, 10);
    std::cout << "char: ";
    if (i >= 32 && i <= 126)
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::printFloat(const std::string& literal) {
    float f = std::strtof(literal.c_str(), NULL);
    std::cout << "char: ";
    if (f >= 32 && f <= 126 && static_cast<int>(f) == f)
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(const std::string& literal) {
    double d = std::strtod(literal.c_str(), NULL);
    std::cout << "char: ";
    if (d >= 32 && d <= 126 && static_cast<int>(d) == d)
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
