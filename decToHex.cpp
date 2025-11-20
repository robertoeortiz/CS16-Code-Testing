#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

char hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string decToHex(int n)
{
    if(n < 16)
    {
        return string(1, hexa[n]);
    }
    else
    {
        return decToHex(n / 16) + hexa[n % 16];
    }
}

int main(int argc, char** argv)
{
    int num = atoi(argv[1]);
    cout << decToHex(num) << endl;
}