#include <iostream>
#include <iomanip>

using namespace std;

void printRussianAlphabet()
{
    for (char ch = 'а'; ch <= 'я'; ++ch)
    {
        cout << ch << " "
            << hex << showbase << static_cast<int>(static_cast<unsigned char>(ch)) << " "
            << oct << showbase << static_cast<int>(static_cast<unsigned char>(ch)) << endl;
    }

    for (char ch = 'А'; ch <= 'Я'; ++ch)
    {
        cout << ch << " "
            << hex << showbase << static_cast<int>(static_cast<unsigned char>(ch)) << " "
            << oct << showbase << static_cast<int>(static_cast<unsigned char>(ch)) << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    cout << uppercase << setw(8) << left << "Символ\t"
        << setw(15) << "Шестн. код\t"
        << "Восьм. код" << std::endl;
    cout << "--------------------------" << endl;
    printRussianAlphabet();
    return 0;
}
