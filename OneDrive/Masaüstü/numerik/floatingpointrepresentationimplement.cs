using System;

class Program {
    static void Main() {
        Console.WriteLine("Enter the value of the number for which you want to see the floating-point representation:");
        float num = float.Parse(Console.ReadLine());
        Console.WriteLine("Your number is: " + num);
       //checking for the sign of input
        char sign;
        if (num >= 0) {
            sign = '0';
        } else {
            sign = '1';
        }

        num = Math.Abs(num);

        // part to Separate integer and fractional parts 
        int integerPart = (int)num;
        float fractionalPart = num - integerPart;

        //part to  Convert integer part to binary 
        string binaryInteger = ConvertToBinary(integerPart);

        // Convert fractional part to binary
        string binaryFractional = ConvertFractionalToBinary(fractionalPart);

        // Calculate exponent and mantissa
        int exponent;
        string mantissa;
        if (!string.IsNullOrEmpty(binaryInteger)) {
            exponent = binaryInteger.Length - 1;
        } else {
            exponent = -1 * (binaryFractional.IndexOf('1') + 1);
        }
        mantissa = (string.IsNullOrEmpty(binaryInteger) ? "" : binaryInteger.Substring(1)) + binaryFractional;
        mantissa = mantissa.PadRight(23, '0');

        // Converting  exponent to biased representation
        string exponentBiased = Convert.ToString(exponent + 127, 2).PadLeft(8, '0');

        // Combine components to get the floating point representation of the input
        string floatingPointRepresentation = sign + exponentBiased + mantissa;

        Console.WriteLine("Floating point representation: " + floatingPointRepresentation);
    }

    static string ConvertToBinary(int num) {
        if (num == 0) return "0";

        string binary = "";
        while (num > 0) {
            binary = (num % 2) + binary;
            num /= 2;
        }
        return binary;
    }

    static string ConvertFractionalToBinary(float num) {
        if (num == 0) return "";

        string binary = ".";
        while (num != 0) {
            num *= 2;
            binary += (int)num;
            num -= (int)num;
        }
        return binary;
    }
}
