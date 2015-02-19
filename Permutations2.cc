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

template<typename RAIter, typename Comp = std::less<typename std::iterator_traits<RAIter>::value_type> >
int next_permutaion(RAIter first, RAIter end, Comp cmp = Comp()){
    auto p = end - 1;
    if(first == end || first == p){
        return 0;
    }
    for(; p > first; --p){
        if(cmp(*(p - 1), *p))break;
    }
    if(p > first){
        auto q = p - 1;
        auto e = end - 1;
        for(; e > q; --e){
            if(cmp(*q, *e))break;
        }
        std::swap(*q, *e);
    

        for(auto q = end - 1; p < q; ++p, --q){
            std::swap(*p, *q);
        }
        return 1;
    }
    return 0;

}

class Solution{
  public:
    vector<vector<int> > permuteUnique(vector<int> &num){
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        ans.push_back(num);
        while(next_permutaion(num.begin(), num.end())){
            ans.push_back(num);

        }
        return ans;

    }

};



int main(){
    Solution slu;
    using std::cin;
    vector<int> num = {1,1,2, 2};

    auto ans = slu.permuteUnique(num);
    for(auto &a: ans){
        for(auto &v: a){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}


