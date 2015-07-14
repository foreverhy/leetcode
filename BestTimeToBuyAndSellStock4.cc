#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int profit[prices.size() + 1][k + 1];
        const int inf = 0x3f3f3f3f;
        int ret = 0;
        std::memset(profit, 0, sizeof profit);
        int len = prices.size();
        for (int day = 1; day < len; ++day) {
            
        }

        return ret;
    }
};



int main(){
    Solution slu;


    return 0;
}


