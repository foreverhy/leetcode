
#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<int> plusOne(vector<int> &digits){
        int c = 1;
        vector<int> ans;
        for(auto p = digits.crbegin(); p != digits.crend(); ++p){
            auto tmp = *p + c;
            if(tmp >= 10){
                tmp -= 10;
                c = 1;
            }else{
                c = 0;
            }
            ans.push_back(tmp);
        }
        if(c){
            ans.push_back(c);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }


};
