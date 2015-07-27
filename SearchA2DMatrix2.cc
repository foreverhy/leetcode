#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (target == matrix[x][y]) {
                return true;
            } else if (target < matrix[x][y]) {
                --y;
            } else {
                ++x;
            }
        }
        return false;
    }
};



int main(){
    Solution slu;


    return 0;
}


