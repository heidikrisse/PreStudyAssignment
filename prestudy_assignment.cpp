#include <fstream> // for file input/output operations
#include <iostream>
#include <vector>

// Function to read numbers from a file and return them as a vector
std::vector<int> readNumbersFromFile()
{
    while (true)
    {
        std::vector<int> numbers;

        std::cout << "Enter the name of the file: ";
        std::string filename{};
        std::cin >> filename;

        if (filename.empty())
        {
            std::cerr << "Empty filename. Please enter a valid filename.\n";
            continue;
        }

        std::fstream file{filename};
        if (!file)
        {
            std::cerr << "Error opening the file. Make sure the file " << filename << " exists.\n";
            return numbers;
        }
        for (int number; file >> number;)
        {
            numbers.push_back(number);
        }
        file.close();

        if (numbers.empty())
        {
            std::cerr << "There are no numbers to read from the file. Exiting...\n";
            break;
        }

        return numbers;
    }
    return {};
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
std::vector<int> findMode(const std::vector<int> &numbers)
{
    std::vector<int> mode_values;
    int mode_count = 0;

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        int numberCount = 0;
        for (unsigned int j = 0; j < numbers.size(); j++)
        {
            if (numbers[j] == numbers[i])
            {
                numberCount++;
            }
        }

        if (numberCount > mode_count)
        {
            mode_count = numberCount;
            mode_values.clear();               // Clear the existing modes
            mode_values.push_back(numbers[i]); // Add the new mode
        }
        else if (numberCount == mode_count && numbers[i] != mode_values[0])
        {
            mode_values.push_back(numbers[i]); // Add another mode with the same frequency, only if it's different from the existing mode
        }
    }

    return mode_values;
}

// Function to print the results
void printResults(const std::vector<int> &numbers)
{
    std::cout << "The sum of the integers in the list: " << calculateSum(numbers) << "\n";
    std::cout << "The average of the integers in the list: " << double(calculateSum(numbers)) / numbers.size() << "\n";
    std::cout << "The minimum value in the list: " << findMinimum(numbers) << "\n";
    std::cout << "The maximum value in the list: " << findMaximum(numbers) << "\n";
    std::vector<int> mode_values = findMode(numbers);
    std::cout << "The most frequent value(s) in the list: ";
    for (const int mode : mode_values)
    {
        std::cout << mode << " ";
    }
    std::cout << "\n";
    std::cout << "Difference between the min and max of the list: " << findMaximum(numbers) - findMinimum(numbers) << "\n";
}

int main()
{
    std::vector<int> numbers{readNumbersFromFile()};

    printResults(numbers);

    return 0;
}
