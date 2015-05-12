#include "leet.h"




#include <algorithm>
#include <cstring>

#include <unordered_map>
using std::unordered_map;

class Solution{
  public:
    int longestConsecutive(vector<int> &nums){

        unordered_map<int, int> mp;
        int ans = 0;
        for (auto &num : nums){
            if (mp.find(num)!= mp.end()){
                continue;
            }
            mp[num] = 1;
            auto it = mp.find(num - 1);
            int llen = 0, rlen = 0;
            if (it != mp.end()){
                llen = it->second;
                mp[num] += llen;
                mp[num - llen] = mp[num];
            }
            if ((it = mp.find(num + 1)) != mp.end()){
                rlen = it->second;
                mp[num] += rlen;
                mp[num + it->second] = mp[num];
                mp[num - llen] = mp[num];
            }
            ans = std::max(ans, mp[num]);
        }
        
        return ans;
    }
};



int main(){
    Solution slu;
    //vector<int> vec({100,4,200,1,3,2});
    //vector<int> vec({1,2,0,1});
    //vector<int> vec({-2,-3,-3,7,-3,0,5,0,8,-4,-1,2});
    vector<int> vec({0,3,7,2,5,8,4,6,0,1});
    // 0 1 2 3 4 5 6 7 8
    // -2: 1
    // -3: -3 -2 :2
    // -3:
    // 7: 7 : 1
    // -3:
    // 0: 0 : 1
    // 5: 5 : 1
    // 0:
    // 8: 8 : 1
    // -4: -4 -3 -2 :3
    // -1:-4 -3 -2 -1 0: 5

    cout << slu.longestConsecutive(vec) << endl;


    return 0;
}


