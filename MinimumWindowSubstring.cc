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
    ListNode *nxt;
    ListNode(int x):val(x), nxt(NULL){}
};




#include <algorithm>
#include <cstring>

namespace{

int need[300], cnt[300];

}
class Solution{
    public:
        string minWindow(string S, string T){
            using std::memset;
            memset(need, 0, sizeof need);
            memset(cnt, 0, sizeof cnt);

            int state = 0;

            for(auto &c : T){
                need[c]++;
                --state;
            }
            size_t left = 0, right = 0;
            size_t ansl = left, ansr = 0x3f3f3f3f;
            while(left < S.length() && !need[S[left]])++left;
            right = left;
            if(right < S.length()){
                cnt[S[right]]++;
                ++state;
            }else{
                return "";
            }
            bool ok = false;
            auto mvright = [&state, &S, &right](){
                ++right;
                if(cnt[S[right]]++ < need[S[right]]){
                    ++state;
                }

            };
            while(right < S.length()){
                if(0 == state){
                    ok = true;
                    if(right - left < ansr - ansl){
                        ansl = left;
                        ansr = right;
                    }
                    if(--cnt[S[left]] < need[S[left]])--state;
                    for(++left; left <= right && cnt[S[left]] > need[S[left]]; ++left){
                        --cnt[S[left]];
                    }
                    if(left > right)break;

                }else{
                    mvright();
                }

            }
            --right;
            if(0 == state){
                for(; left <= right; ++left){
                    auto c = S[left];
                    if(need[c]){
                        if(right - left < ansr - ansl){
                            ansl = left;
                            ansr = right;
                        }
                        if(--cnt[c] < need[c])break;
                    }
                }

            }


            if(ok){
                return S.substr(ansl, ansr - ansl + 1);
            }else{
                return "";
            }
        }



};



int main(){
    Solution slu;
    using std::cin;
    string S, T;
    while(cin >> S >> T){
        cout << slu.minWindow(S, T) << endl;
    }


    return 0;
}


