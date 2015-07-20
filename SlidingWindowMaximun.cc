#include "leet.h"




#include <algorithm>
#include <cstring>
#include <queue>

class Solution{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty()) return {};
        std::deque<int> q;
        int len = nums.size();
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        vector<int> ret;
        ret.push_back(q.front());
        for (int i = k; i < len; ++i) {
            if (q.front() == nums[i - k]) {
                q.pop_front();
            }
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }
            q.push_back(nums[i]);
            ret.push_back(q.front());
        }
        return ret;
    }
};



int main(){
    Solution slu;
    vector<int> a {1, 3, -1, -3, 5, 3, 6, 7};
    cout << slu.maxSlidingWindow(a, 3) << endl;


    return 0;
}


