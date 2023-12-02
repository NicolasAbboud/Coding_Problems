#include <iostream>

using namespace std;

void even_odd(int n)
{
    if (n & 1)
        cout << "odd";
    else
        cout << "even";
}

int main()
{
    int n;
    cin >> n;
    even_odd(n);
   
    return 0;
}
// Solution by Nicolas Abboud
