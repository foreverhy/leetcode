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

using std::unordered_map;
using std::map;


class Solution{
  public:
    typedef vector<string>::size_type sz;
    vector<int> findSubstring(string S, vector<string> &L){
        unordered_map<string, sz> m;
        //map<string, sz> m;
        auto step = L[0].length();
        //for(auto &l: L){
            //mp[l] = 0;
        //}
        int cnt[L.size()];
        std::memset(cnt, 0, sizeof cnt);
        for(sz i = 0; i < L.size(); ++i){
            auto fid = m.find(L[i]);
            if(fid == m.end()){
                ++cnt[i];
                m[L[i]] = i;
            }else{
                ++cnt[fid->second]; 
            }
        }
        vector<int> stat(S.length(), -1);
        int vst[L.size()];
        vector<int> ans;
        for(sz i = 0; i < S.length(); ++i){
            sz j = 0;
            std::memset(vst, 0, sizeof vst);
            for(sz k = i; k < S.length() && j < L.size(); ++j, k += step){
                sz idx = 0;
                if(stat[k] == -2){
                    break;
                }else if(stat[k] == -1){
                    auto fid = m.find(S.substr(k, step));
                    if(fid != m.end()){
                        idx = stat[k] = fid->second;
                        if(vst[idx] >= cnt[idx]){
                            break;
                        }
                        ++vst[idx];
                    }else{
                        stat[k] = -2;
                        break;
                    }
                }else{
                    idx = stat[k];
                    if(vst[idx] >= cnt[idx])break;
                    ++vst[idx];
                }
                    
            }
            if(j >= L.size()){
                ans.push_back(i);
            }
        }

        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;

    //string S = "barfoothefoobarman";
    //vector<string> L = {"foo", "bar"};
    string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> L = {"fooo","barr","wing","ding","wing"};

    auto ans = slu.findSubstring(S, L);

    for(auto &a: ans){
        cout << a << " ";
    }
    cout << endl;

    return 0;
}


