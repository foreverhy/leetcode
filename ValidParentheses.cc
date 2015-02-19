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

constexpr static char leftpar[3] = {'(', '{', '['};
//constexpr static char right[3] = {')', '}', ']'};

inline bool in(char ch, const char* tb){
    return ch == tb[0] || ch == tb[1] || ch == tb[2];
}
inline int ch2i(char ch){
    switch(ch){
        case '(':
        case ')': return 0; break;
        case '{':
        case '}': return 1; break;
        case '[':
        case ']': return 2; break;
        default:return -1;
    }
}

char st[400];
int top = 0;

class Solution{
  public:
    bool isValid(string s){
        top = 0;
        for(auto c: s){
            if(in(c, leftpar)){
                st[++top] = c;
            }else{
                if(!top){
                    return false;
                }
                auto last = st[top]; 
                if(ch2i(last) != ch2i(c)){
                    return false;
                }else{
                    --top;
                }
            }
        }
        return 0 == top;
    }


};



int main(){
    Solution slu;
    using std::cin;


    return 0;
}


