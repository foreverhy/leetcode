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
    vector<int> plusOne(vector<int> &digits){
        int c = 1;
        vector<int> ans;
        for(auto p = digits.crbegin(); p != digits.crend(); ++p){
            auto tmp = *p + c;
            if(tmp >= 10){
                tmp -= 10;
                c = 1;
            }else{
                c = 0;
            }
            ans.push_back(tmp);
        }
        if(c){
            ans.push_back(c);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }


};



int main(){
    Solution slu;
    using std::cin;


    return 0;
}


