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
    ListNode(int x):val(x), next(NULL){}
};




#include <algorithm>
#include <cstring>
#include <map>


class Solution{
  public:
    typedef vector<int>::size_type sz;

    int bsearch(vector<int> &num, sz low, sz high, int target){
        if(low > high){
            return 0x3f3f3f3f;
        }
        while(low <= high){
            auto mid = (low + high) >> 1;
            if(target == num[mid]){
                return target;
            }else if(target < num[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return num[low];
    }

    int abs(int x){
        return x > 0? x: -x;
    }

    int threeSumClosest(vector<int> &num, int target){
        std::sort(num.begin(), num.end());
        int ans = 0x3f3f3f3f;
        for(vector<int>::size_type i = 0; i < num.size(); ++i){
            for(auto j = i + 1; j < num.size(); ++j){
                auto tmp = num[i] + num[j];
                auto rest = target - tmp;
                auto fit = bsearch(num, j + 1, num.size() - 1, rest);
                tmp += fit;
                if(abs(target-tmp) < abs(target-ans)){
                    //cout << num[i] << " " << num[j] << " " << fit << endl;
                    ans = tmp;
                }
            }
        }
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;

    //vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<int> num = {-1, 2, 1, -4};
    cout <<  slu.threeSumClosest(num, 1) << endl;


    return 0;
}


