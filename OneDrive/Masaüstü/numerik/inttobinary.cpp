#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: "; // Prompt the user to enter a number
    cin >> num; // Read the number entered by the user

    int binary[32]; // Create an array to store the binary representation, assuming a 32-bit integer

    int index = 0;
    while (num > 0) { // Convert decimal to binary
        binary[index] = num % 2; // Store the remainder in the array
        num /= 2; // Update the number by dividing it by 2
        index++; // Move to the next index in the array
    }

    cout << "Binary representation of the number is: ";
    for (int i = index - 1; i >= 0; i--) { // Print the binary representation in reverse order
        cout << binary[i]; // Print each digit of the binary representation
    }
    cout << endl;

    return 0;
}

