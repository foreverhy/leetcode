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

struct Interval{
    int start;
    int end;
    Interval():start(0), end(0) {}
    Interval(int s, int e): start(s), end(e){}
};




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<Interval> merge(vector<Interval> &intervals){
        vector<Interval> ans;
        auto cmp = [](const Interval &lhs, const Interval &rhs){
            if(lhs.start == rhs.start){
                return lhs.end < rhs.end;
            }
            return lhs.start < rhs.start;

        };
        std::sort(intervals.begin(), intervals.end(), cmp);
        auto iter = intervals.begin();
        if(intervals.end() == iter){
            return ans;
        }
        int start = iter->start, end = iter->end;
        for(++iter; iter != intervals.end(); ++iter){
            if(iter->start > end){
                ans.push_back(std::move(Interval(start, end)));
                start = iter->start;
                end = iter->end;
            }else{
                end = std::max(end, iter->end);
            }
        }
        ans.push_back(std::move(Interval(start, end)));

        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;

    vector<Interval> inters;
    inters.push_back(Interval(1, 3));
    inters.push_back(Interval(2, 6));
    inters.push_back(Interval(8, 10));
    inters.push_back(Interval(15, 18));

    auto ans = slu.merge(inters);
    for(auto &a: ans){
        cout << a.start << " " << a.end << endl;
    }

    return 0;
}


