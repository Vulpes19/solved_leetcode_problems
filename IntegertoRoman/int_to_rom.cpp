#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

static char	*cal(char *num, int ndigits, int len, int n)
{
	int	ifneg;

	ifneg = 0;
	while (ndigits >= 0)
	{
		if (n < 0)
		{
			n *= -1;
			ifneg = 1;
		}
		num[ndigits] = n % 10 + '0';
		n /= 10;
		ndigits--;
	}
	if (ifneg)
		num[0] = '-';
	num[len] = '\0';
	return (num);
}

static int	ndigits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nd;
	int		len;

	nd = ndigits(n);
	len = nd;
	if (n < 0)
	{
		nd++;
		len++;
	}
	num = (char *)malloc(sizeof(char) * nd + 1);
	if (!num)
		return (NULL);
	nd -= 1;
	return (cal(num, nd, len, n));
}

string  intToRoman(int num)
{
    char *str;
    int len;
    int i = 0;
    // vector<char> ret;
    str = ft_itoa(num);
    while (str[i])
    {
        
    }
    // while (num > 0)
    // {
    //     ret.push_back(num % 10);
    //     num /= 10;
    // }
    // string str(ret.begin(), ret.end());
    return (str);
}
int main()
{
    cout << intToRoman(12345);
}