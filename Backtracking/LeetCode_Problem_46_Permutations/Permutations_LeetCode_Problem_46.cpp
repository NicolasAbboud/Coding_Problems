#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& original, vector<bool> used, vector<int> cur, vector<vector<int>>& solutions)
{
    // base case
    if (cur.size() == original.size())
    {
        solutions.push_back(cur);
    }
    // statements (backtracking)
    {
        for (int i = 0; i < original.size(); i++)
        {
            if (!used[i])
            {
                cur.push_back(original[i]);
                used[i] = true;
                backtrack(original, used, cur, solutions);

                cur.pop_back();
                used[i] = false;
            }
        }
    }
}

void print(vector<vector<int>>& solutions)
{
    cout << "[";
    for (int i = 0; i < solutions.size(); i++)
    {
        if (i == solutions.size() - 1)
        {
            cout << "[";
            for (int j = 0; j < solutions[i].size(); j++)
            {
                if (j == solutions[i].size() - 1)
                    cout << solutions[i][j];
                else
                    cout << solutions[i][j] << ", ";
            }
            cout << "]";
        }
        else
        {
            cout << "[";
            for (int j = 0; j < solutions[i].size(); j++)
            {
                if (j == solutions[i].size() - 1)
                    cout << solutions[i][j];
                else
                    cout << solutions[i][j] << ", ";
            }
            cout << "], ";
        }
        
    }
    cout << "]";
}


void generate_permutations(vector<int>& original)
{
    vector<vector<int>> solutions;
    vector<bool> used(original.size(), false);
    vector<int> cur;
    backtrack(original, used, cur, solutions);

    print(solutions);
}

int main()
{
    int n;
    cin >> n;
    vector<int> original(n, 0);
    for (int i = 0; i < original.size(); i++)
    {
        cin >> n;
        original[i] = n;
    }
    generate_permutations(original);
    

    return 0;
}
// Time Complexity: O(N!)
// Solution by Nicolas Abboud
