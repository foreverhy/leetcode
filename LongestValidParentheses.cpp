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
#include <stack>

class Solution{
  public:
    int longestValidParentheses(string s){
        std::stack<std::pair<char,int> > st;
        int ans = 0;
        vector<int> dp(s.length() + 10, 0);
        dp[0] = 0;
        int pos = 1;
        for(auto &c: s){

            if('(' == c){
                st.push({c, pos});
                dp[pos] = 0;
            }else{
                if(!st.empty()){
                    auto p = st.top();
                    if('(' == p.first){
                        dp[pos] = dp[p.second - 1] + pos - p.second + 1;
                    }else{
                        dp[pos] = 0;
                    }
                    st.pop();
                }else{
                    dp[pos] = 0;
                }
            }
            ans = std::max(ans, dp[pos++]);
        }
        return ans;

    }


};



int main(){
    Solution slu;
    using std::cin;

    string s;
    while(cin >> s){
        cout << slu.longestValidParentheses(s) << endl;
    }


    return 0;
}


