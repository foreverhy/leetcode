#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size();
        while (low < high) {
            auto mid = (low + high) >> 1;
            if (nums[mid] > nums[high - 1]) {
                low = mid + 1;
            } else if (0 == mid || nums[mid] )
        }
    }
};



int main(){
    Solution slu;


    return 0;
}


