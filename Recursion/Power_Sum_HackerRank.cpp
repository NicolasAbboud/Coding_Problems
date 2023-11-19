#include <iostream>
#include <cmath>

using namespace std;

void calculate_ways(int x, int n, int& counter, int itr = 1, int sum = 0)
{
    // Base Case
    if (sum == x)
    {
        counter++;
        return;
    }
    else if ( sum > x)
        return;

    // Statements
    for (int i = itr; i <= pow(x, 1.0/n); i++)
    {
        calculate_ways(x, n, counter, ++itr, sum + pow(i, n));
    }
}

int main()
{
    // Initialization and getting input from user
    int counter = 0;
    int x, n;
    cin >> x;
    cin >> n;
    
    // The process
    calculate_ways(x, n, counter);

    // Output
    cout << counter << endl;

    return 0;
}
// Solution by Nicolas Abboud
