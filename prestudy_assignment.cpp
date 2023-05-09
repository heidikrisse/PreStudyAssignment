#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    // vector to hold the numbers (size n)
    // vector is chosen because the size of the list is not known beforehand before the userś input
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << ". integer: ";
        cin >> numbers[i];
    }

    int sum = 0;
    int min_value = numbers[0];
    int max_value = numbers[0];
    int mode_value = numbers[0];
    int mode_count = 1;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (numbers[j] == numbers[i]) {
                count++;
            }
        }
        if (count > mode_count) {
            mode_count = count;
            mode_value = numbers[i];
        }
    }
    double average = sum / n;
    int difference = max_value - min_value;

    cout << "The sum of the integers in the list: " << sum << endl;
    cout << "The average of the integers in the list: " << average << endl;
    cout << "The minimum value in the list: " << min_value << endl;
    cout << "The maximum value in the list: " << max_value << endl;
    cout << "The most frequent value in the list: " << mode_value << endl;
    cout << "Difference between the min and max of the list: " << difference << endl;

    return 0;
}
