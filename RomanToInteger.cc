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

std::map<char, int> R ={
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

std::map<char, std::pair<char, char> > SUB ={
    {'I', {'V', 'X'}},
    {'X', {'L', 'C'}},
    {'C', {'D', 'M'}},
};


class Solution{
  public:
    typedef string::size_type sz;
    int romanToInt(string s){
        int ans = 0;
        auto l = s.length();
        sz i = 0;
        while(i < l){
            if((s[i] != 'I' && s[i] != 'X' && s[i] != 'C') || i >= l - 1){
                ans += R[s[i++]];
            }else{
                auto &p = SUB[s[i]];
                if(s[i + 1] == p.first || s[i + 1] == p.second){
                    ans += R[s[i+1]] - R[s[i]];
                    i += 2;
                }else{
                    ans += R[s[i++]];
                }
            }
        }
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;
    string s;
    while(cin >> s){
        cout << slu.romanToInt(s) << endl;
    }

    //cout << slu.romanToInt("X") << endl;

    return 0;
}


