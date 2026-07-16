#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m_i = 0;
        int m_j = matrix.size() -1;
        int n_i = 0;
        int n_j = matrix[0].size() - 1;
        while (m_i <= m_j)
        {
            int m_mid = (m_i + m_j) / 2;
            if (matrix[m_mid][0] == target)
            {
                return true;
            }
            else if (matrix[m_mid][0] < target)
            {
                m_i = m_mid + 1;
            }
            else
            {
                m_j = m_mid - 1;
            }
            if (m_i > matrix.size() -1)
            {
                m_i = matrix.size() -1;
                break;
            }
            else if (m_j < 0)
            {
                m_j = 0;
                break;
            }
        }
        while (n_i <= n_j)
        {
            int n_mid = (n_i + n_j) / 2;
            if (matrix[m_j][n_mid] == target)
            {
                return true;
            }
            else if (matrix[m_j][n_mid] < target)
            {
                n_i = n_mid + 1;
            }
            else
            {
                n_j = n_mid - 1;
            }
        }
        return false;
    }
};
