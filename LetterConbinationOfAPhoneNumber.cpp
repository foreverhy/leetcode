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

const vector<string> D = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution{
  public:
    
    vector<string> ans;
    string digits;
    typedef string::size_type sz;

    void dfs(string &buff, sz idx){
        if(idx >= digits.length()){
            ans.push_back(buff);
            return;
        }
        const string &s = D[digits[idx]-'0'];
        for(auto &c: s){
            buff += c;
            dfs(buff, idx + 1);
            buff.pop_back();
        }
    }

    vector<string> letterCombinations(string Digits){
        ans.clear();
        digits = std::move(Digits);
        string s = "";
        dfs(s, 0);
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;

    auto ans = slu.letterCombinations("23");

    for(auto &s: ans){
        cout << s << endl;
    }

    return 0;
}


