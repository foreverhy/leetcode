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

const int MAXN = 300;
int dp[MAXN][MAXN][MAXN];

class Solution{
  public:

    string S1, S2;

    bool isSame(int begin1, int begin2, int len){
        if(dp[begin1][begin2][len] != -1){
            return dp[begin1][begin2][len] ;
        }
        //if(begin1 >= end1 || begin2 >= end2){
            //return dp[begin1][end1][begin2][end2] = false;
        //}
        //if(end1 - begin1 != end2 - begin2){
            //return dp[begin1][end1][begin2][end2] = false;
        //}
        if (0 == len){
            return dp[begin1][begin2][len] = true;
        }
        if(1 == len){
            return dp[begin1][begin2][len] = (S1[begin1] == S2[begin2]);
        }

        int mid = len >> 1;
        for(int i = 1; i < len; ++i){
            if(isSame(begin1, begin2, i) && isSame(begin1 +i, begin2 + i, len - i)){
                return dp[begin1][begin2][len] = true;
            }
            int j = len - i;
            if ((isSame(begin1, begin2 + j, i) && isSame(begin1 + i, begin2, j))){
                return dp[begin1][begin2][len] = true;
            }
        }
        return false;
        //int mid1 = begin1 + mid;
        //int mid2 = begin2 + mid;

    }


    bool isScramble(string s1, string s2){
        std::memset(dp, -1, sizeof dp);
        S1 = std::move(s1);
        S2 = std::move(s2);
        return isSame(0, 0, S1.length());

    }

};



int main(){
    Solution slu;

    string s1, s2;
    while (cin >> s1 >> s2){
        cout << slu.isScramble(s1, s2) << endl;
    }


    return 0;
}


