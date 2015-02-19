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
    vector<vector<int> > threeSum(vector<int> &num){
        std::map<int, vector<int>::size_type> mp;
        std::sort(num.begin(), num.end());
        for(vector<int>::size_type i = 0; i < num.size(); ++i){
            mp[num[i]] = i;
        }
        vector<vector<int> > ans;
        for(vector<int>::size_type i = 0; i < num.size(); ++i){
            if(i && num[i] == num[i-1])continue;
            for(auto j = i + 1; j < num.size(); ++j){
                if(j != i + 1 && num[j] == num[j - 1])continue;
                auto tmp = num[i] + num[j];
                auto rest = 0 - tmp;
                auto fit = mp.find(rest);
                if(fit != mp.end() && fit->second > j){
                    ans.push_back({num[i], num[j], fit->first});
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
    vector<int> num = {1,0,1,2,-1,-4, -1, -1, -2, -3, -4};
    auto ans = slu.threeSum(num);

    for(auto &v: ans){
        for(auto &a: v){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}


