#include <fstream> // for file input/output operations
#include <iostream>
#include <vector>

// Function to read numbers from a file and return them as a vector
// 'filename' is a reference to a constant string object, & operator takes the address of the filename
// and can access the original string object (numbers.txt) without making a copy of it.
std::vector<int> readNumbersFromFile(const std::string &filename)
{
    std::vector<int> numbers;
    std::ifstream file(filename);

    for (int number; file >> number;)
    {
        numbers.push_back(number);
    }
    file.close();

    return numbers;
}

// Function to calculate the sum of numbers in a vector
// & operator takes the address of the vector numbers
int calculateSum(const std::vector<int> &numbers)
{
    int sum{0};
    // Iterate over each element in the vector
    for (int num : numbers)
    {
        sum += num;
    }
    return sum;
}

// Function to find the minimum value in a vector
int findMinimum(const std::vector<int> &numbers)
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
int findMaximum(const std::vector<int> &numbers)
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
int findMode(const std::vector<int> &numbers)
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

// Function to print the results
void printResults(const std::vector<int> &numbers)
{
    std::cout << "The sum of the integers in the list: " << calculateSum(numbers) << '\n';
    std::cout << "The average of the integers in the list: " << double(calculateSum(numbers)) / numbers.size() << '\n';
    std::cout << "The minimum value in the list: " << findMinimum(numbers) << '\n';
    std::cout << "The maximum value in the list: " << findMaximum(numbers) << '\n';
    std::cout << "The most frequent value in the list: " << findMode(numbers) << '\n';
    std::cout << "Difference between the min and max of the list: " << findMaximum(numbers) - findMinimum(numbers) << '\n';
}

int main()
{
    std::vector<int> numbers{readNumbersFromFile("numbers.txt")};

    printResults(numbers);

    return 0;
}
