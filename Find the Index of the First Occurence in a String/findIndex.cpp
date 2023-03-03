#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for ( size_t i = 0; i < haystack.length(); i++ )
        {
            if ( haystack.compare( i, needle.length(), needle.c_str()) == 0 )
                return (i);
        }
        return (-1);
    }
};