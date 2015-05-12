#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
    bool isalph(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    char lower(char a){
        if (a >= 'A' && a <= 'Z'){
            return a + 'a' - 'A';
        }
        return a;
    }
  public:

    bool isPalindrome(string &s){
        auto it1 = s.begin(), it2 = s.end() - 1;

        while (it1 < it2){
            if (!isalph(*it1)){
                ++it1;
            } else if (!isalph(*it2)){
                --it2;
            } else if (lower(*it1) != lower(*it2)){
                return false;
            } else {
                ++it1;
                --it2;
            }
        }

        return true;
    }
};



int main(){
    Solution slu;

    string s;
    while (cin >> s){
        cout << slu.isPalindrome(s) << endl;
    }


    return 0;
}


