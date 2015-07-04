#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    void push(vector<string> &ans, int expected, int n) {
        if (n == expected + 1) {
            ans.push_back(std::to_string(expected));
        } else {
            ans.push_back(std::to_string(expected) + "->" + std::to_string(n - 1));
        }

    }
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> ans;
        string tmp("");
        int expected = lower;
        for (auto n : nums) {
            if (n > upper) break;
            if (n != expected) {
                push(ans, expected, n);
            }
            expected = n + 1;
        }
        if (expected <= upper) {
            push(ans, expected, upper + 1);
        }
        return ans;
    }
};



int main(){
    Solution slu;

    vector<int> a = {0, 1, 3, 50, 75};
    cout << slu.findMissingRanges(a, 0, 99) << endl;

    return 0;
}


