#include <gtest/gtest.h>
#include "ScalarConverter.hpp"

// Test for special literal "nan"
TEST(ScalarConverterTest, TestNan) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("nan");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
}

// Test for special literal "+inf"
TEST(ScalarConverterTest, TestPositiveInf) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("+inf");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n");
}

// Test for special literal "-inf"
TEST(ScalarConverterTest, TestNegativeInf) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("-inf");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");
}

// Test for float literal with 'f'
TEST(ScalarConverterTest, TestFloatLiteral) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("42.0f");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
}

// Test for double literal
TEST(ScalarConverterTest, TestDoubleLiteral) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("42.0");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
}

// Test for integer literal
TEST(ScalarConverterTest, TestIntLiteral) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("42");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
}

// Test for invalid input
TEST(ScalarConverterTest, TestInvalidInput) {
    testing::internal::CaptureStdout();
    ScalarConverter::convert("abc");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Invalid input\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
