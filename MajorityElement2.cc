#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<int> majorityElement(vector<int>& nums) {
        const int inf = 0x3f3f3f3f;
        int v1 = inf, v2 = inf;
        int c1 = 0, c2 = 0;
        for (auto n : nums) {
            if (n == v1) {
                ++c1;
            } else if (n == v2) {
                ++c2;
            } else if (!c1) {
                ++c1;
                v1 = n;
            } else if (!c2) {
                ++c2;
                v2 = n;
            } else {
                --c1;
                --c2;
            }
        }
        vector<int> ans;
        c1 = c2 = 0;
        for (auto n : nums) {
            if (n == v1) ++c1;
            if (n == v2) ++c1;
        }
        if (c1 > nums.size()/3) ans.push_back(v1);
        if (c2 > nums.size()/3) ans.push_back(v2);
        return ans;
    }
};



int main(){
    Solution slu;


    return 0;
}


