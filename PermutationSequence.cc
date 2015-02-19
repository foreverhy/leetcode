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
    string getPermutation(int n, int k){
        --k;
        int mod = 1;
        for(int i = 1; i <= n; ++i){
            mod *= i;
        }
        k %= mod;
        mod /= n;
        string ans = "";
        vector<int> vec(9, 0);
        for(size_t i = 0; i < vec.size(); ++i){
            vec[i] = i;
        }
        for(int i = n - 1; i >= 1; --i){
            int a = k / mod;    
            ans += vec[a] + '1';
            vec.erase(vec.begin() + a);
            k %= mod;
            mod /= i;
        }
        ans += vec[k] + '1';
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;
    int n, k;
    while(cin >> n >> k){
        cout << slu.getPermutation(n, k) << endl;
    }


    return 0;
}


