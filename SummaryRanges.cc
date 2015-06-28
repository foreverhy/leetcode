#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        vector<string> ans;
        string tmp;
        int last = 0x3f3f3f3f;
        int len = 0;
        for (auto n : nums) {
            if (last + 1 == n || 0x3f3f3f3f == last) {
                ++len;
            } else if (len) {
                if (len > 1) {
                    ans.push_back(std::to_string(last - len + 1) + "->" + std::to_string(last));
                } else {
                    ans.push_back(std::to_string(last));
                }
                len = 1;
            }
            last = n;
        }
        if (len) {
            if (len > 1) {
                ans.push_back(std::to_string(last - len + 1) + "->" + std::to_string(last));
            } else {
                ans.push_back(std::to_string(last));
            }
        }
        return ans;

    }

};



int main(){
    Solution slu;
    vector<int> a = {0, 1, 2, 4, 5, 7};
    cout << slu.summaryRanges(a) << endl;


    return 0;
}


