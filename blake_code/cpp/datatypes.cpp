#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    cout << "C++ Data Type Sizes" << endl;
    cout << "-------------------" << endl;
    cout << sizeof(short int) << " short int" << endl;
    cout << sizeof(int) << " int" << endl;
    cout << sizeof(long int) << " long int" << endl;
    cout << sizeof(long long int) << " long long int" << endl;
    cout << sizeof(char) << " char" << endl;
    cout << sizeof(wchar_t) << " wide char" << endl;
    cout << sizeof(float) << " float" << endl;
    cout << sizeof(double) << " double" << endl;
    cout << sizeof(long double) << " long double" << endl;
    cout << sizeof(bool) << " bool" << endl;
    return 0;
}
