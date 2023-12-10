#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


void transpose(vector<vector<int>>& vec)
{
    int row = vec.size();
    int column = vec[0].size();
    vector<vector<int>> neo(column, vector<int> (row, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            neo[j][i] = vec[i][j];
        }
    }

    print(neo);
}


  
int main()
{
    int r, c;
    cout << "Enter the dimensions of the matrix:\n";
    cout << "Number of rows: ";
    cin >> r;
    cout << "Number of columns: ";
    cin >> c;

    vector<vector<int>> vec(r, vector<int> (c, 0));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> vec[i][j];
        }

    transpose(vec);


    return 0;
}

// Time Complexity: O(N^2)
// Solution by Nicolas Abboud
