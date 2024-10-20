#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <iomanip> // std::setprecision

class ScalarConverter {
public:
    // Static convert function
    static void convert(const std::string& literal);

private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // Helper functions
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isSpecial(const std::string& literal);

    // Conversion functions
    static void printChar(const std::string& literal);
    static void printInt(const std::string& literal);
    static void printFloat(const std::string& literal);
    static void printDouble(const std::string& literal);
    static void printSpecial(const std::string& literal);
};

#endif
