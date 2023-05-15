#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream> // for file input/output operations

using namespace std;

int main()
{
    // The size type for a vector of integers
    vector<int>::size_type n{};
    cout << "Enter the number of integers: ";
    cin >> n;

    // Vector to store the numbers from the file
    vector<int> numbers(n);

    // Open the file for reading
    ifstream file("numbers.txt");
    for (vector<int>::size_type i{0}; i < n; i++)
    {
        file >> numbers[i];
    }
    file.close();

    int sum{0};
    int min_value{numbers[0]};
    int max_value{numbers[0]};
    int mode_value{numbers[0]};
    int mode_count{1};
    for (vector<int>::size_type i = {0}; i < n; i++)
    {
        sum += numbers[i];

        if (numbers[i] < min_value)
        {
            min_value = numbers[i];
        }

        if (numbers[i] > max_value)
        {
            max_value = numbers[i];
        }

        // Variable to store the count of the current number
        int numberCount{0};
        for (vector<int>::size_type j{0}; j < n; j++)
        {
            if (numbers[j] == numbers[i])
            {
                numberCount++;
            }
        }

        if (numberCount > mode_count)
        {
            mode_count = numberCount;
            mode_value = numbers[i];
        }
    }

    cout << "The sum of the integers in the list: " << sum << '\n';
    cout << "The average of the integers in the list: " << double(sum) / (double)n << '\n';
    cout << "The minimum value in the list: " << min_value << '\n';
    cout << "The maximum value in the list: " << max_value << '\n';
    cout << "The most frequent value in the list: " << mode_value << '\n';
    cout << "Difference between the min and max of the list: " << max_value - min_value << '\n';

    return 0;
}
