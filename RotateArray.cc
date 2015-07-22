#include "leet.h"



#include <algorithm>
#include <cstring>

class Solution{
  public:
	void rotate(vector<int> &nums, int k) {
		k %= nums.size();
		std::reverse(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.begin() + k);
		std::reverse(nums.begin() + k, nums.end());
	}
};



int main(){
    Solution slu;
    vector<int> a {
        1,2,3,4,5,6
    };
    slu.rotate(a, 2);
    cout << a << endl;


    return 0;
}


