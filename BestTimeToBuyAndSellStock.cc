#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int maxProfit(vector<int> &prices){
        int ans = 0;
        int min = 0x7fffffff;
        for (auto &p : prices){
            auto tmp = p - min;
            min = min < p ? min : p;
            ans = ans > tmp ? ans : tmp;
        }
        return ans;
    }
};



int main(){
    Solution slu;


    return 0;
}


