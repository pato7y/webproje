#include <iostream>
#include <bitset>
#include <cmath>

// Function to get the binary representation of the integer part
std::string getBinaryIntegerPart(float num) {
    int integerPart = static_cast<int>(num);
    std::string binaryIntegerPart = "";
    while (integerPart > 0) {
        binaryIntegerPart = std::to_string(integerPart % 2) + binaryIntegerPart;
        integerPart /= 2;
    }
    return binaryIntegerPart;
}

// Function to get the binary representation of the fractional part
std::string getBinaryFractionalPart(float num, int& shiftCount) {
    std::string binaryFractionalPart = "";
    float fractionalPart = num - static_cast<int>(num);
    while (fractionalPart > 0) {
        fractionalPart *= 2;
        if (fractionalPart >= 1) {
            binaryFractionalPart += '1';
            fractionalPart -= 1;
        } else {
            binaryFractionalPart += '0';
        }
    }

    // Count leading zeros to determine shift count
    shiftCount = 0;
    for (char bit : binaryFractionalPart) {
        if (bit == '0') {
            shiftCount++;
        } else {
            break;
        }
    }

    return binaryFractionalPart;
}

// Function to shift the number to the left for n times
float shiftLeft(float num, int n) {
    return num * std::pow(2, n);
}

// Function to get the sign, exponent, and fractional part
void getFloatingPointRepresentation(float num) {
    std::bitset<32> binaryRepresentation;
    
    // Sign bit
    binaryRepresentation[31] = (num < 0) ? 1 : 0;
    
    // Exponent calculation
    int exponent = 0;
    if (num != 0) {
        exponent = std::log2(std::abs(num)) + 127;
    }
    std::bitset<8> exponentBits(exponent);
    for (int i = 0; i < 8; ++i) {
        binaryRepresentation[30 - i] = exponentBits[7 - i];
    }
    
    // Fractional part
    float shiftedNum = std::abs(num);
    if (exponent != 127) {
        shiftedNum *= std::pow(2, -std::log2(std::abs(num)));
    }
    int shiftCount = 0;
    std::string binaryFractionalPart = getBinaryFractionalPart(shiftedNum, shiftCount);
    for (int i = 0; i < 23; ++i) {
        if (i < binaryFractionalPart.length()) {
            binaryRepresentation[22 - i] = (binaryFractionalPart[i] == '1') ? 1 : 0;
        } else {
            binaryRepresentation[22 - i] = 0;
        }
    }
    
    // Output
    std::cout << "Binary representation: " << binaryRepresentation << std::endl;
}

int main() {
    float input;
    std::cout << "Enter a float number: ";
    std::cin >> input;

    std::cout << "Binary representation of integer part: " << getBinaryIntegerPart(input) << std::endl;
    int shiftCount;
    std::string binaryFractionalPart = getBinaryFractionalPart(input, shiftCount);
    std::cout << "Binary representation of fractional part: " << binaryFractionalPart << std::endl;

    std::cout << "Result after shifting left " << shiftCount << " times: " << shiftLeft(input, shiftCount) << std::endl;

    std::cout << "Floating point representation:" << std::endl;
    getFloatingPointRepresentation(input);

    return 0;
}