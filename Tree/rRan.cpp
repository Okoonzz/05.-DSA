#include <bits/stdc++.h>

using namespace std;

void generateRandomNumbers(unordered_set<int>& numbers, int count, int minVal, int maxVal) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(minVal, maxVal);

    while (numbers.size() < count) {
        int num = distribution(generator);
        numbers.insert(num);
    }
}

int main() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 10; i++) {
            unordered_set<int> numbers;
            generateRandomNumbers(numbers, 1000000, -10000000, 10000000);
            for (int num : numbers) {
                file << num << " ";
            }
            file << endl;
        }
        file.close();
    }
    return 0;
}
