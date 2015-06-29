#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int half = nums.size() >> 1;
        for (int i = 0; i < 32; ++i) {
            int cnt1 = 0;
            int cnt0 = 0;
            int mask = 1u << i; 
            for (auto n : nums) {
                if (n & mask){
                    ++cnt1;
                } else {
                    ++cnt0;
                }
                if (cnt1 > half || cnt0 > half) break;
            }
            if (cnt1 > half) {
                ans |= mask;
            } 
        }
        return ans;
    }
};



int main(){
    Solution slu;
    vector<int> a = {4, 5, 4};
    cout << slu.majorityElement(a) << endl;


    return 0;
}


