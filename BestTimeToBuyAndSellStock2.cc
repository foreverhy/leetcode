#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int maxProfit(vector<int> &prices){
        int ans = 0;
        int stock = 0;
        int len = prices.size();
        for (int i = 0; i < len; ++i){
            if (i == len - 1){
                ans += stock ? prices[i] : 0;
            } else if (stock){
                if (prices[i + 1] < prices[i]){
                    ans += prices[i];
                    stock = 0;
                }
            } else {
                if (prices[i + 1] > prices[i]){
                    ans -= prices[i];
                    stock = 1;
                }
            }
            
        }
        return ans;
    }
};



int main(){
    Solution slu;


    return 0;
}


