#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int majorityElement(vector<int>& nums) {
        int last = 0x3f3f3f3f;
        int cnt = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int n = nums[i];
            if (!cnt) {
                last = n;
                ++cnt;
            } else if (last == n) {
                ++cnt;
            } else if (cnt) {
                --cnt;
            } else {
                cnt = 1;
                last = n;
            }
            if (cnt > len - i) {
                break;
            }
        }
        return last;
    }
};



int main(){
    Solution slu;


    return 0;
}


