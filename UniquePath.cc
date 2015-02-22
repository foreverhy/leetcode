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



#include<algorithm>
#include<cstdio>
class Solution {
public:
    int d[102][102];
    int dp(int m, int n){
        if(d[m][n] != -1){
            return d[m][n];
        }
        if(m < 1 || n < 1)return 0;
        if(m == 1 && n == 1)return d[m][n] = 1;
        return d[m][n] = dp(m - 1, n) + dp(m, n - 1);
    }
    int uniquePaths(int m, int n) {
        memset(d,-1,sizeof(d));
        return dp(m,n);
    }
};



int main(){
    Solution slu;
    using std::cin;


    return 0;
}


