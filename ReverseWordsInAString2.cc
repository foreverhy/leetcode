#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    void reverseWords(string &s) {
        std::reverse(s.begin(), s.end());
        auto start = s.begin();
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == ' ') {
                std::reverse(start, iter); 
                start = iter + 1;
            }
        }
        std::reverse(start, s.end());
    }
};



int main(){
    Solution slu;

    string s = "the sky is blue";
    slu.reverseWords(s);
    cout << s << endl;

    return 0;
}


