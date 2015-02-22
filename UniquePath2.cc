#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int s[m + 1][n + 1];
        std::memset(s, 0, sizeof s);
        s[m][n - 1] = 1;
        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                if(obstacleGrid[i][j]){
                    s[i][j] = 0;
                }else{
                    s[i][j] = s[i + 1][j] + s[i][j + 1];
                }
            }
        }
        return s[0][0];
    }

};



int main(){
    Solution slu;
    using std::cin;
    vector<vector<int> > obs = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    
    auto ans = slu.uniquePathsWithObstacles(obs);
    cout << ans << endl;


    return 0;
}


