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
    vector<vector<int> > fourSum(vector<int> &num, int target){
        std::multimap<int, std::pair<sz, sz> > mp;
        std::sort(num.begin(), num.end());
        for(vector<int>::size_type i = 0; i < num.size(); ++i){
            for(auto j = i + 1; j < num.size(); ++j){
                //if(j != i + 1 && num[j] == num[j - 1])continue;
                auto tmp = num[i] + num[j];
                mp.insert({tmp, {i, j}});
            }
        }
        vector<vector<int> > ans;
        for(vector<int>::size_type i = 0; i < num.size(); ++i){
            if(i && num[i] == num[i-1])continue;
            for(auto j = i + 1; j < num.size(); ++j){
                if(j != i + 1 && num[j] == num[j - 1])continue;
                    auto tmp = num[i] + num[j] ;
                    auto rest = target - tmp;
                    auto fit = mp.equal_range(rest);
                    for(auto it = fit.first; it != fit.second; ++it){
                        auto k1 = it->second.first;
                        auto k2 = it->second.second;
                        if(k1 > j){
                            if(k1 != j + 1 && num[k1] == num[k1 - 1])continue;
                            if(k2 != k1 + 1 && num[k2] == num[k2 - 1])continue;
                            ans.push_back({num[i], num[j], num[k1], num[k2]});
                        }
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
    vector<int> num = {1, 0, -1, 0, -2, 2};
    auto ans = slu.fourSum(num, 0);

    for(auto &v: ans){
        for(auto &a: v){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}


