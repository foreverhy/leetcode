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
    static const int inf = 0x3f3f3f3f;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<int> spiralOrder(vector<vector<int> > &matrix){
        int i = 0, x = 0, y = 0;
        int m = matrix.size();
        if(!m)return vector<int>();
        int n = matrix[0].size();
        vector<int> ans;
        for(; ; ){
            if(x < 0 || x >= m || y < 0 || y >= n || 
                inf == matrix[x][y]){
                break;
            }
            ans.push_back(matrix[x][y]);
            matrix[x][y] = inf;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || 
                    inf == matrix[nx][ny] ){
                if(4 == ++i){
                    i = 0;
                }
            }
            x = x + dx[i];
            y = y + dy[i];
        }
        return ans;

    }

};



int main(){
    Solution slu;
    using std::cin;

    vector<vector<int> > matrix ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    auto ans = slu.spiralOrder(matrix);
    ans.clear();
    for(auto a: ans){
        cout << a << " ";
    }
    cout << endl;


    return 0;
}


