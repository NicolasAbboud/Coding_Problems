#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void generate_subsets(int index, vector<int> current, vector<int>& original, vector<vector<int>>& subsets)
{
    if(index == original.size())
    {
        subsets.push_back(current);
    }
    else
    {
        current.push_back(original[index]);
        generate_subsets(index+1, current, original, subsets);
        current.pop_back();
        generate_subsets(index+1, current, original, subsets);
    }
}

void solve(vector<int>& original)
{
    vector<vector<int>> solution;
    vector<int> curr;
    generate_subsets(0, curr, original, solution);

    cout << "[";
    for (int i = 0; i < solution.size(); i++)
    {
        if (i == solution.size() - 1)
        {
            cout << "[";
            for (int j = 0; j < solution[i].size(); j++)
            {
                if(j == solution[i].size() - 1)
                    cout << solution[i][j];
                else
                    cout << solution[i][j] << ", ";
            }
            cout << "]";
        }
        else
        {
            cout << "[";
            for (int j = 0; j < solution[i].size(); j++)
            {
                if(j == solution[i].size() - 1)
                    cout << solution[i][j];
                else
                    cout << solution[i][j] << ", ";
            }
            cout << "], ";
        }
    }
    cout << "]";
}


int main()
{
    vector<int> v = {1, 2, 3};
    solve(v);

    return 0;
}
// Solution by Nicolas Abboud
