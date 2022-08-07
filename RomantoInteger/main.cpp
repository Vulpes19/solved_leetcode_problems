#include <iostream>

using namespace std;

int romanToInt(string s) 
    {
        int number;
        int i;
        
        number = 0;
        i = 0;
        while(s[i])
        {
            if (s[i] == 'I' && s[i+1] != 'V' && s[i+1] != 'X' )
                number += 1;
            if (s[i] == 'V' )
                number += 5;
            else if (s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C' )
                number += 10;
            else if (s[i] == 'L' )
                number += 50;
            else if (s[i] == 'C' && s[i+1] != 'D' && s[i+1] != 'M' )
                number += 100;
            else if (s[i] == 'D' )
                number += 500;
            else if (s[i] == 'M' )
                number += 1000;
            else if (s[i] == 'X' && s[i+1] == 'C' )
            {
                number += 90;
                i += 1;
            }
            else if (s[i] == 'X' && s[i+1] == 'L' )
            {
                number += 40;
                i += 1;
            }
            else if (s[i] == 'I' && s[i+1] == 'V' )
            {
                number += 4;
                i += 1;
            }
            else if (s[i] == 'I' && s[i+1] == 'X' )
            {
                number += 9;
                i += 1;
            }
            else if (s[i] == 'C' && s[i+1] == 'D' )
            {
                number += 400;
                i += 1;
            }
            else if (s[i] == 'C' && s[i+1] == 'M' )
            {
                number += 900;
                i += 1;
            }
            i++;
        }
        return (number);
    }
int main()
{
    string s;

    cout << "Enter a roman number" << endl;
    cin >> s;
    cout << romanToInt(s) << endl;
}