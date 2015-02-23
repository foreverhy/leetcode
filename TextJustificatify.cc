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


class Solution{
  public:
    vector<string> fullJustify(vector<string> &words, int L){
        vector<string> ans;
        int wdlen = 0;
        int wds = 0;
        auto siter = words.begin();
        auto eiter = siter;
        for(;;){
            int usd = wds + wdlen;
            if(eiter == words.end() || usd + eiter->length() > L){
                if(eiter == words.end()){
                    string tmp = "";
                    for(auto iter = siter; iter != eiter; ++iter){
                        if(iter != siter){
                            tmp += " ";
                        }
                        tmp += *iter;
                    }
                    for(int i = wdlen + (wds?wds-1:0); i < L ; ++i)tmp += " ";
                    ans.push_back(std::move(tmp));
                    break;

                }else if(wds > 1){
                    int spaces = L - wdlen;
                    int basesp = spaces / (wds - 1);
                    int extra = spaces % (wds - 1);
                    string tmp = "";
                    for(auto iter = siter; iter != eiter - 1; ++iter){
                        tmp += *iter;
                        for(int i = 0; i < basesp; ++i)tmp += " ";
                        if(extra-- > 0)tmp += " ";
                    }
                    tmp += *(eiter - 1);
                    ans.push_back(std::move(tmp));
                }else{
                    string tmp = *siter;
                    for(int i = wdlen; i < L; ++i){
                        tmp += " ";
                    }
                    ans.push_back(std::move(tmp));

                }
                siter = eiter;
                wdlen = wds = 0;
            }else{
                if(!eiter->empty()){
                    wdlen += eiter->length();
                    wds++;
                }
                ++eiter;
            }
        }
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;
    vector<string> s = {
        "This", "is", "an",
        "example", "of", "test",
        "justification.",
    };

    s.clear();
    s.push_back("a");

    auto ans = slu.fullJustify(s, 1);
    for(auto &a: ans){
        for(auto &c: a){
            if(c == ' ')c = 'x';
        }
        cout << a << endl;
    }

    return 0;
}


