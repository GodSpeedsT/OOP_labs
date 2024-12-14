#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h> 

using namespace std;

int getRandomNumber()
{
    return rand() % 101 - 50;
}

void prepareInputFile(const string& filename)
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 100; ++i)
    {
        outFile << getRandomNumber() << endl;
    }

    outFile.close();
}

void processFiles(const string& inputFilename, const string& outputFilename)
{
    ifstream inFile(inputFilename);
    ofstream outFile(outputFilename);

    if (!inFile.is_open() || !outFile.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }

    vector<int> numbers;
    int number;
    int firstNegative = 0;
    int fiftiethNumber = 0;

    cout << "Числа из входного файла:" << endl;

    for (int i = 0; i < 100 && inFile >> number; ++i)
    {
        cout << number << endl;
        numbers.push_back(number);
        if (number < 0 && firstNegative == 0)
        {
            firstNegative = number;
        }
        if (i == 49)
        {
            fiftiethNumber = number;
        }
    }
    cout << "\nПервое отрицательное число: " << firstNegative << endl; 
    cout << "50-е число: " << fiftiethNumber << endl;

    double halfSum = (firstNegative + fiftiethNumber) / 2.0;
    cout << "\nЧисла после обработки:" << endl;
    for (const int& num : numbers)
    {
        double processedNumber = num / halfSum; 
        cout << processedNumber << endl;
        outFile << num / halfSum << endl;
    }

    inFile.close();
    outFile.close();
}

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    prepareInputFile(inputFilename);
    processFiles(inputFilename, outputFilename);

    cout << "Файлы успешно обработаны!" << endl;

    return 0;
}
