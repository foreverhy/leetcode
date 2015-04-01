#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
    
    ListNode(std::initializer_list<int> vals):val(0), next(nullptr){
        if(0 == vals.size()){
            return;
        }
        auto p = vals.begin();
        this->val = *p;
        auto last = this;
        for(++p; p != vals.end(); ++p){
            last->next = new ListNode(*p);
            last = last->next;
        }
    }

};

std::ostream& operator<<(std::ostream& os, ListNode *head){
    for(; head; head = head->next){
        os << head->val << " ";
    }
    return os;
}



#include <algorithm>
#include <cstring>

class Solution{
  public:

    void reverse_bit(unsigned &target, int idx){
        auto mask = 1u << idx;
        if (target & mask){
            target &= (~mask);
        }else{
            target |= mask;
        }
    }
    vector<int> grayCode(int n){

        vector<int> ans;
        if (!n){
            return {};
        }

        unsigned now = 0;
        unsigned mask = 0;
        int cnt = 0;

        for ( ; ; ){
            ans.push_back(now);
            if (cnt & 1){
                int idx = 0;
                for (idx = 0; idx < n; ++idx){
                    mask = 1u << idx;
                    if (mask & now){
                        break;
                    }
                }
                auto mbit = idx + 1;
                if (mbit >= n){
                    break;
                }
                reverse_bit(now, mbit);

            }else {
                reverse_bit(now, 0);       
            }
            ++cnt;
        }

        return ans;
    }
};



int main(){
    Solution slu;

    auto vec = slu.grayCode(0);

    for(auto &item : vec){
        cout << item << endl;
    }


    return 0;
}


