#include <iostream>
#include <vector>
#include <fstream> // for file input/output operations

using namespace std;

// Function to read numbers from a file and return them as a vector
// 'filename' is a reference to a constant string object, & operator takes the address of the filename
// and can access the original string object (numbers.txt) without making a copy of it.
vector<int> readNumbersFromFile(const string &filename, unsigned int n)
{
    vector<int> numbers(n);

    ifstream file(filename);
    for (unsigned int i{0}; i < n; i++)
    {
        file >> numbers[i];
    }
    file.close();

    return numbers;
}

// Function to calculate the sum of numbers in a vector
// & operator takes the address of the vector numbers
int calculateSum(const vector<int> &numbers)
{
    int sum{0};
    // // Iterate over each element in the vector
    for (int num : numbers)
    {
        sum += num;
    }
    return sum;
}

// Function to find the minimum value in a vector
int findMinimum(const vector<int> &numbers)
{
    int min_value{numbers[0]};
    for (unsigned int i{1}; i < numbers.size(); i++)
    {
        if (numbers[i] < min_value)
        {
            min_value = numbers[i];
        }
    }
    return min_value;
}

// Function to find the maximum value in a vector
int findMaximum(const vector<int> &numbers)
{
    int max_value{numbers[0]};
    for (size_t i{1}; i < numbers.size(); i++)
    {
        if (numbers[i] > max_value)
        {
            max_value = numbers[i];
        }
    }
    return max_value;
}

// Function to find the mode value in a vector
int findMode(const vector<int> &numbers)
{
    int mode_value{numbers[0]};
    int mode_count{1};

    for (unsigned int i{0}; i < numbers.size(); i++)
    {
        int numberCount{0};
        for (unsigned int j{0}; j < numbers.size(); j++)
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

    return mode_value;
}

int main()
{
    cout << "Enter the number of integers: ";
    unsigned int n;
    cin >> n;

    vector<int> numbers{readNumbersFromFile("numbers.txt", n)};

    int sum{calculateSum(numbers)};
    int min_value{findMinimum(numbers)};
    int max_value{findMaximum(numbers)};
    int mode{findMode(numbers)};

    cout << "The sum of the integers in the list: " << sum << '\n';
    cout << "The average of the integers in the list: " << double(sum) / numbers.size() << '\n';
    cout << "The minimum value in the list: " << min_value << '\n';
    cout << "The maximum value in the list: " << max_value << '\n';
    cout << "The most frequent value in the list: " << mode << '\n';
    cout << "Difference between the min and max of the list: " << max_value - min_value << '\n';

    return 0;
}
