#include <iostream>
#include <vector>

using namespace std;


void string_creator(string str, int desired_length, string set, vector<string>& v)
{
    // Base Case (Stop at this point)
    if (str.length() == desired_length)
    {
        v.push_back(str);
        return;
    }

    // Statements (The process)
    for (int i = 0; i < set.size() ; i++)
    {
        string_creator(str + set[i], desired_length, set, v);
    }
}


int main()
{
    string set = "ab";
    int k = 3;
    vector<string> container;
    string s = "";

    string_creator(s , k, set, container);
    
    for (int i = 0; i < container.size(); i++)
        cout << container.at(i) << endl;

    return 0;
}
// Solution by Nicolas Abboud
