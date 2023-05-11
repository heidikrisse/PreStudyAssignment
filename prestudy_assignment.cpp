#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream> // for file input/output operations

using namespace std;

int main() {
    // variable for the number of integers (from the file)
    int n{};
    cout << "Enter the number of integers: ";
    cin >> n;

    // vector to hold the numbers (size n)
    // vector is chosen because the size of the list is not known beforehand before the users' input
    vector<int> numbers(n);

    // open the file
    ifstream file("numbers.txt");
    for (int i {0}; i < n; i++) {
        file >> numbers[i];
    }
    file.close();

    int sum {0};
    int min_value {numbers[0]};
    int max_value {numbers[0]};
    int mode_value {numbers[0]};
    int mode_count {1};
    for (int i = {0}; i < n; i++) {
        sum += numbers[i];
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        // initialize (copy list initialization) a count for the number of times the value appears in the array
        int count {0};
        for (int j {0}; j < n; j++) {
            if (numbers[j] == numbers[i]) {
                count++;
            }
        }
        if (count > mode_count) {
            mode_count = count;
            mode_value = numbers[i];
        }
    }
    double average = {double(sum) / double(n)};
    int difference = {max_value - min_value};

    cout << "The sum of the integers in the list: " << sum << endl;
    cout << "The average of the integers in the list: " << average << endl;
    cout << "The minimum value in the list: " << min_value << endl;
    cout << "The maximum value in the list: " << max_value << endl;
    cout << "The most frequent value in the list: " << mode_value << endl;
    cout << "Difference between the min and max of the list: " << difference << endl;

    return 0;
}
