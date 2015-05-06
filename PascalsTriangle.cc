#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<vector<int> > generate(int numRows){
        vector<vector<int> > ans;
        if (!numRows){
            return ans;
        }

        ans.push_back({1});
        for (int i = 1; i < numRows; ++i){
            vector<int> tmp;
            for (int j = 0; j < i + 1; ++j){
                if (0 == j){
                     tmp.push_back(ans[i - 1][j]);
                } else if (i == j){
                    tmp.push_back(ans[i - 1][i - 1]);
                } else {
                    tmp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
            ans.push_back(std::move(tmp));
        }
        return ans;
    }
};



int main(){
    Solution slu;

    auto ans = slu.generate(10);
    for (auto &a : ans){
        cout << a << endl;
    }


    return 0;
}


