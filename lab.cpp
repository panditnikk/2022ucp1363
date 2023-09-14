
#include <iostream>

struct Complex {
    double real;
    double imaginary;
};

// Function to add two complex numbers
Complex addComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

// Function to subtract two complex numbers
Complex subtractComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return result;
}

int main() {
    Complex num1 = {3.0, 2.0};
    Complex num2 = {1.0, 7.0};

    // Addition
    Complex sum = addComplex(num1, num2);
    std::cout << "Sum: " << sum.real << " + " << sum.imaginary << "i" << std::endl;

    // Subtraction
    Complex diff = subtractComplex(num1, num2);
    std::cout << "Difference: " << diff.real << " + " << diff.imaginary << "i" << std::endl;

    // Multiplication
    Complex product = multiplyComplex(num1, num2);
    std::cout << "Product: " << product.real << " + " << product.imaginary << "i" << std::endl;

    return 0;
    }
