#include <iostream>

// Function to calculate the GCD of two numbers using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    for (int i = 2; i < n; i++) {
        int j = n - i;
        if (gcd(i, j) > 1) {
            std::cout << "The numbers are: " << i << " and " << j << std::endl;
            return 0;
        }
    }

    std::cout << "-1" << std::endl;
    return 0;
}
