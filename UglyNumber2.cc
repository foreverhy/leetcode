#include "leet.h"




#include <algorithm>
#include <cstring>
#include <queue>



class Solution{
    static std::priority_queue<long, std::vector<long>, std::greater<long> > pq;
    static std::vector<long> ans;
  public:
    Solution() {
        if (ans.empty()) {
            pq.push(1);
        }
    }
    int nthUglyNumber(int n) {
        while (static_cast<int>(ans.size()) < n) {
            auto now = pq.top();
            pq.pop();
            if (ans.empty() || now != ans.back()) {
                ans.push_back(now);
            } else {
                continue;
            }
            pq.push(now << 1);
            pq.push((now << 1) + now);
            pq.push((now << 2) + now);
        }
        return ans[n - 1];
    }
};

std::priority_queue<long, vector<long>, std::greater<long> > Solution::pq;
std::vector<long> Solution::ans;

int main(){
    Solution slu;
    int x;
    while (cin >> x) {
        cout << slu.nthUglyNumber(x) << endl;
    }
    //for (int i = 1; i <= 10; ++i) {
        //cout << slu.nthUglyNumber(i) << " ";
    //}


    return 0;
}


