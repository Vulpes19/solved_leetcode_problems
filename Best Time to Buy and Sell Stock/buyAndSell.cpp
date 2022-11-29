#include <iostream>
#include <vector>

using namespace std;


 int maxProfit(vector<int>& prices) 
{
    int profit = 0;
    int minim = 10e5;
    
    for ( int i = 0; i < prices.size(); i++ )
    {
        if ( prices[i] < minim)
            minim = prices[i];
        else if ( profit < prices[i] - minim )
            profit = prices[i] - minim;
    }
    return (profit);
}