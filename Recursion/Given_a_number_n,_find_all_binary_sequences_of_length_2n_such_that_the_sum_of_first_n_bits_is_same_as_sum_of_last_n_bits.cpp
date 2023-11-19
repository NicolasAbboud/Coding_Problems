
#include <iostream>

using namespace std;

string reverseHomeMade(string str)
{
    string reverse = str;
    for (int i = 0; i < str.size()/2; i++)
    {
        swap(reverse[i], reverse[(reverse.size() - 1) - i]);
    }
    return reverse;
}

void generate_sequences(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            sum++;
    }
    if(sum == 0 || sum == s.size())
    {
        cout << s + s << endl;
    }
    else
    {
        cout << s + reverseHomeMade(s) << endl;
        cout << s + s << endl;
    }
}


void generate_core(int n, string str = "")
{
    // The base case
    if(str.size() == n)
    {
        generate_sequences(str);
        return;
    }

    // The statements
    for(int i = 0; i < 2; i++)
    {
        generate_core(n, str + to_string(i) );
    }
}

int main()
{
    generate_core(2);
    return 0;
}
// Solution by Nicolas Abboud
