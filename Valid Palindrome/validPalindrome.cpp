#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool	isPalindrome( string s )
{
	s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string rev = s;
	reverse(rev.begin(), rev.end());
	cout << s << " " << rev << endl;
	if (s.compare(rev) == 0)
		return (true);
	else
		return (false);
}

int	main( void )
{
	cout << isPalindrome( "A man, a plan, a canal: Panala" ) << endl; 
	return (0);
}
