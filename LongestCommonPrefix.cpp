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
#include <climits>

class Solution{
  public:
    string longestCommonPrefix(vector<string> &strs){
        vector<string>::size_type pos = 0;
        if(strs.empty()){
            return "";
        }
        auto &fst = strs[0];
        while(true){
            for(auto &str: strs){
                if(pos >= str.length() || pos >= fst.length() || str[pos] != fst[pos]){
                    return fst.substr(0, pos);
                }
            }
            ++pos;
        }
        return "";
    }


};



int main(){
    Solution slu;
    using std::cin;

    vector<string> strs;
    string s;
    while(cin >> s){
        strs.push_back(std::move(s));
    }

    cout << slu.longestCommonPrefix(strs) << endl;



    return 0;
}


