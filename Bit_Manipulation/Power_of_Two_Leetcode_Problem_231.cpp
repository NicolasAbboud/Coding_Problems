#include <iostream>

using namespace std;

void powerOf2(int n)
{
    if (n & (n - 1))
    {
        cout << "False";
    }
    else
    {
        cout << "True";
    }
}

int main()
{
    int n;
    cin >> n;
    powerOf2(n);
   
    return 0;
}
// Solution by Nicolas Abboud
