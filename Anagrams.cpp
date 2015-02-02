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

#include <unordered_map>
#include <map>

template<typename T_>
class my_hash;

template<>
class my_hash<string>{
  public:
    std::size_t operator()(const string &s)const{
        auto ts = s;
        std::sort(ts.begin(), ts.end());
        return std::hash<string>()(ts);
    }

};

class Solution{
  public:
    vector<string> anagrams(vector<string> &strs){
        std::map<std::size_t, int> mp;
        for(auto &s: strs){
            auto k = my_hash<string>()(s);
            auto fd = mp.find(k);
            if(fd != mp.end()){
                fd->second += 1;
            }else{
                mp[k] = 1;
            }
        }

        vector<string> ans;

        for(auto &s: strs){
            auto k = my_hash<string>()(s);
            if(mp[k] > 1){
                ans.push_back(std::move(s));
            }
            //ans.push_back(std::move(s));
        }





        return ans;

    }

};



int main(){
    Solution slu;
    using std::cin;

    vector<string> strs = {
        "dog",
        "cat",
        "god",
        "tac",
        "hello",
        "nice",
        //"nice",


    };

    auto ans = slu.anagrams(strs);
    for(auto &s: ans){
        cout << s << " ";
    }
    cout << endl;


    return 0;
}


