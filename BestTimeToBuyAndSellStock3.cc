#include "leet.h"




#include <algorithm>
#include <cstring>

const int INF =0x7FFFffff;

class Solution{
  public:
    int maxProfit(vector<int> &prices){
        if (prices.empty()){
            return 0;
        }
        int len = prices.size();
        int profit[len + 5];
        profit[len] = profit[len + 1] = 0;
        int min = INF;

        profit[0] = 0;
        min = prices[0];

        for (int i = 1; i < len; ++i){
            auto a = prices[i];
            auto tmp = a  - min;
            min = std::min(min, a);
            profit[i] = std::max(profit[i - 1], tmp);
        }

        int max = -INF;
        int ans = 0;
        int ret = profit[len - 1];
        for (int i = len - 1; i > 0; --i){
            auto a = prices[i];
            int diff = 0;
            if (a < max){
                diff = max - a;
            }
            max = std::max(max, a);
            ans = std::max(ans, diff);
            ret = std::max(ret, ans + profit[i - 1]);
        }


        return ret;
    }
};



int main(){
    Solution slu;

    //vector<int> a = {3,1,4,2,5,7,2,4,9,0};
    vector<int> a = {1,2};
    cout << slu.maxProfit(a) << endl;


    return 0;
}


