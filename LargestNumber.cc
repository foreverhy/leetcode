#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    static bool cmp(const string &a, const string &b) {
        return (a + b) > (b + a);
    }
    string largestNumber(vector<int> &nums) {
        vector<string> vs;
        for (auto n : nums) {
            vs.push_back(std::to_string(n));
        }
        std::sort(vs.begin(), vs.end(), cmp);
        string ans("");
        for (auto &s : vs) {
            if (ans.empty() && s == "0") continue;
            ans += s;
        }
        if (ans.empty()) ans = "0";
        return ans;
    }
};



int main(){
    Solution slu;
    vector<int> a = {128, 12};
    cout << slu.largestNumber(a) << endl;
    vector<int> b = {121, 12};
    cout << slu.largestNumber(b) << endl;
    vector<int> c = {1440,7548,4240,6616,733,4712,883,8,9576};
    cout << slu.largestNumber(c) << endl;

    return 0;
}


