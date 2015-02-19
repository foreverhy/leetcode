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

        bool isMatch(const char *s, const char *p){
            const char *star = nullptr;
            const char *ss = s;

            while(*s){
                if('?' == *p || *s == *p){
                    ++s;
                    ++p;
                }else if('*' == *p){
                    star = p++;
                    ss = s;
                }else if(star){
                    p = star + 1;
                    s = ++ss;
                }else{
                    return false;
                }
            }
            while('*' == *p)++p;
            return !(*p);
        }

};



int main(){
    Solution slu;
    using std::cin;
    //char s[1010], p[1010];
    string s, p;
    while(cin >> s >> p){
        cout << slu.isMatch(s.data(), p.data()) << endl;
    }

    return 0;
}
