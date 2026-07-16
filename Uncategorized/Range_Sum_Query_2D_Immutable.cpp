#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    prefix[i][j] = matrix[i][j];
                }
                else if (i == 0 && j != 0)
                {
                    prefix[i][j] = matrix[i][j] + prefix[i][j - 1];
                }
                else if (i != 0 && j == 0)
                {
                    prefix[i][j] = matrix[i][j] + prefix[i - 1][j];
                }
                else
                {
                    prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] -prefix[i -1][j -1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix[row2][col2];
        int top = (row1 > 0) ? prefix[row1 - 1][col2] : 0;
        int left = (col1 > 0) ? prefix[row2][col1 - 1] : 0;
        int topLeft = (row1 > 0 && col1 > 0) ? prefix[row1 - 1][col1 - 1] : 0;
        
        ans = ans - top - left + topLeft;
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */