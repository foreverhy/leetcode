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

std::map<int, string > ROMAN ={
    {1, "IVX"},
    {10, "XLC"},
    {100, "CDM"},
    {1000, "M  "},
};

vector<string> CONVERT = {
    "", "a", "aa", "aaa", "ab", "b", "ba", "baa", "baaa", "ac"
};



class Solution{
  public:
    //typedef string::size_type sz;
    void trans(string &s, int pw){
        string &sub = ROMAN[pw];
        for(auto &c: s){
            switch(c){
                case 'a': c = sub[0]; break;
                case 'b': c = sub[1]; break;
                case 'c': c = sub[2]; break;
                default: break;
            }
        }
    }

    string intToRoman(int num){
        string res = "";
        int pw = 1;
        while(num){
            auto t = num % 10;
            auto sym = CONVERT[t];
            trans(sym, pw);
            res = sym + res;
            pw *= 10;
            num /= 10;
        }
        return res;
    }

};



int main(){
    Solution slu;
    using std::cin;
    int s;
    while(cin >> s){
        cout << slu.intToRoman(s) << endl;
    }

    //cout << slu.romanToInt("X") << endl;

    return 0;
}


