#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool    isAnagram( string s, string t )
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s.compare(t) == 0)
        return (true);
    else
        return (false);
}

int main( void )
{
    cout << isAnagram("rat", "car") << endl;
}