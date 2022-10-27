#include <iostream>
#include <vector>

using namespace std;



int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << "max profit: " << endl;
    cout << maxProfit(v);
}