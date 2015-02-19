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

class Solution{
  public:
    vector<int> twoSum(vector<int> &numbers, int target){
        int s = 0, e = numbers.size() - 1;
        while(s < e){
            auto tmp = numbers[s] + numbers[e];
            if(tmp > target){
                --e;
            }else if(tmp < target){
                ++s;
            }else{
                return {s + 1, e + 1};
            }
        }
        return {};
    }

};



int main(){
    Solution slu;
    using std::cin;

    vector<int> numbers = {2, 7, 11, 15};
    auto ans = slu.twoSum(numbers, 9);
    std::for_each(ans.begin(), ans.end(), [](const int &x){cout << x << endl;});

    return 0;
}


