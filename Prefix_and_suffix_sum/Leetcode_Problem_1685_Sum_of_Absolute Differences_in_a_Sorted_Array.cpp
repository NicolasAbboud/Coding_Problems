#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<int> v; // the array
    int n;  // size of array
    cin >> n; // get size of array
    int b;

    for (int i = 0; i < n; i++)
    {
        cin >> b;
        v.push_back(b);
    }

    // Prefix Sum
    vector<long long> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i < n + 1; i++ )
    {
        prefix_sum[i] = prefix_sum[i-1] + v[i - 1];
    }

    vector<int> result(n);
    
    cout << "[";
    for(int i = 1; i < n + 1; i++)
    {
        result[i - 1] = abs(prefix_sum[i - 1] - ((i-1)*v[i - 1])) + abs(prefix_sum[n] - prefix_sum[i] - ((n - i)*v[i - 1]) );
        if (i == n)
            cout << result[i - 1];
        else
            cout << result[i - 1] << ", ";
    }
    cout << "]";

    return 0;
}
// Solution by Nicolas Abboud
