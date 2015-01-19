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
    vector<string> ans;
    int n;

    void dfs(string &s, int lp, int rp, char ch, int leftopen){
        if(lp > n || rp > n){
            return ;
        }
        if('(' == ch){
            ++lp;
            ++leftopen;
        }else{
            ++rp;
            if(--leftopen < 0)return;
        }
        s += ch;
        //cout << s << " " << lp << " " << rp << " " << leftopen <<endl;
        if(lp == rp && lp == n && !leftopen){
            ans.push_back(s);
            s.pop_back();
            return ;
        }
        dfs(s, lp, rp, '(', leftopen);
        s.pop_back();
        s += ch;
        dfs(s, lp, rp, ')', leftopen);
        s.pop_back();
    }

    vector<string> generateParenthesis(int N){
        ans.clear();
        n = N;
        string s = "";
        dfs(s, 0, 0, '(', 0);
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;

    auto ans = slu.generateParenthesis(8);

    for(auto &a: ans){
        cout << a << endl;
    }

    return 0;
}


