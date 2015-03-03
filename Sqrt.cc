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
	int sqrt(int x){
		if (1 == x)return 1;
		int l = 0, r = x / 2 + 1;
		while (l < r){
			long long mid = (l + r) >> 1;
			long long tmp = mid * mid;
			if (x == tmp){
				return mid;
			}else if (x < tmp){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		return l - 1;
	}

};



int main(){
	Solution slu;
	using std::cin;
	int x;
	while (cin >> x){
		cout << slu.sqrt(x) << endl;
	}

	return 0;
}


