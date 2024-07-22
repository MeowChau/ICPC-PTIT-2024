#include <iostream>
#include <string>

long long extractAndSumNumbers(const std::string& input) {
    long long sum = 0;
    long long currentNumber = 0;
    bool isValid = true;
    size_t digitCount = 0;

    for (char c : input) {
        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
            digitCount++;
            if (digitCount > 19 || currentNumber < 0) {
                isValid = false;
            }
        } else if (c == ' ' || c == '\n') {
            if (isValid && digitCount > 0) {
                if (currentNumber > INT32_MAX && currentNumber <= INT64_MAX) {
                    sum += currentNumber;
                }
            }
            currentNumber = 0;
            isValid = true;
            digitCount = 0;
        } else {
            isValid = false;
            currentNumber = 0;
            digitCount = 0;
        }
    }
    if (isValid && digitCount > 0) {
        if (currentNumber > INT32_MAX && currentNumber <= INT64_MAX) {
            sum += currentNumber;
        }
    }
    return sum;
}

int main() {
    std::string line;
    long long totalSum = 0;
    while (std::getline(std::cin, line)) {
        totalSum += extractAndSumNumbers(line);
    }
    std::cout << totalSum << std::endl;
    return 0;
}