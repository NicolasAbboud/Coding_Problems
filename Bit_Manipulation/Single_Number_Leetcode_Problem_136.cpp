#include <iostream>
#include <vector>

using namespace std;


int solve(vector<int>& v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = ans ^ v[i];
    }
    return ans;
}


int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }
    cout << solve(vec) << endl;
    
    return 0;
}
// Solution by Nicolas Abboud
