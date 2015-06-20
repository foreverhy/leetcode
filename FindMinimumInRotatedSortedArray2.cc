#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};




#include <algorithm>
#include <cstring>

class Solution{
public:
	int findMin(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		int low = 0, high = nums.size() - 1;
		while (low < high) {
			auto mid = (low + high) >> 1;
			if (nums[mid] > nums[high]) {
				low = mid + 1;
			}
			else if (nums[mid] < nums[high]) {
				high = mid;
			}
			else if (nums[mid] != nums[low]){
				high = mid;
			}
			else {
				int last = -0x3f3f3f3f;
				for (int i = low; i <= high; ++i) {
					if (nums[i] < last) {
						return nums[i];
					}
					last = nums[i];
				}
				return nums[low];
			}
		}
		return nums[low];
	}
};



int main(){
	Solution slu;
	using std::cin;
	int x;

	vector<int> a = {4,1,4,4,4};
	std::cout << slu.findMin(a) << endl;

	return 0;
}


