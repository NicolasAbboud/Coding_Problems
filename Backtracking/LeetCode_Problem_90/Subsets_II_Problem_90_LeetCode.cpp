#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void erase_duplicates(vector<vector<int>>& subsets, vector<vector<int>>& solution)
{
    for (int i = 0; i < subsets.size() - 1; i++)
    {
        if (subsets[i] != subsets[i+1])
            solution.push_back(subsets[i]);
    }
    solution.push_back(subsets[subsets.size()-1]);
}

void generate_subsets(vector<int>& original, vector<int> current, vector<vector<int>>& subsets, int tracker = 0)
{
    if (tracker == original.size())
    {
        subsets.push_back(current);
        return;
    }
    else
    {
            current.push_back(original[tracker]);
            generate_subsets(original, current, subsets, tracker + 1);
            current.pop_back();
            generate_subsets(original, current, subsets, tracker + 1);
    }
}

void solve(vector<int>& ori, vector<vector<int>>& container, vector<vector<int>>& solution)
{
    vector<int> current;
    generate_subsets(ori, current, container, 0);
    erase_duplicates(container, solution);
    
    cout << "[";
    for (int i = 0; i < solution.size(); i++)
    {
        if (i == solution.size() - 1)
        {
            cout << "[";
            for (int j = 0; j < solution[i].size(); j++)
            {
                if (j == solution[i].size() - 1)
                {
                    cout << solution[i][j];
                }
                else
                {
                    cout << solution[i][j] << ", ";
                }
            }
            cout << "]";
        }
        else
        {
            cout << "[";
            for (int j = 0; j < solution[i].size(); j++)
            {
                if (j == solution[i].size() - 1)
                {
                    cout << solution[i][j];
                }
                else
                {
                    cout << solution[i][j] << ", ";
                }
            }
            cout << "], ";
        }
    }
    cout << "]";
}

int main()
{
    int n;
    cin >> n;
    int b;
    vector<int> o;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        o.push_back(b);
    }
    vector<vector<int>> subsets, solution;
    solve(o, subsets, solution);
    

    return 0;
}
// Solution by Nicolas Abboud
