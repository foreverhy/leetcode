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
#include <stack>
using std::stack;

class Solution{
  public:
    int largestRectangleArea(vector<int> &height){
        int sz = height.size();
        stack<int> st;
        int left[sz + 10], right[sz + 10];
        for(int i = 0; i < sz; ++i){
            while(!st.empty()){
                if(height[st.top()] < height[i]){
                    left[i] = st.top();
                    st.push(i);
                    break;
                }
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
                st.push(i);
            }
        }
        while(!st.empty())st.pop();
        for(int i = sz-1; i >= 0; --i){
            while(!st.empty()){
                if(height[st.top()] < height[i]){
                    right[i] = st.top();
                    st.push(i);
                    break;
                }
                st.pop();
            }
            if(st.empty()){
                right[i] = -1;
                st.push(i);
            }
        }
        int ans = 0;
        for(int i = 0; i < sz; ++i){
            int llen = (-1 == left[i])? i : (i - left[i] - 1);
            int rlen = (-1 == right[i])? (sz - 1 - i) : (right[i] - i - 1);
            ans = std::max(ans, (1 + llen + rlen) * height[i]);
        }
        return ans;

    }

    int maximalRectangle(vector<vector<char> > &matrix){
        if(matrix.empty()){
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if('0' == matrix[i][j]){
                    height[j] = 0;
                }else{
                    height[j]++;
                }
            }
            ans = std::max(ans, largestRectangleArea(height));
        }
        return ans;
    }

};



int main(){
    Solution slu;

    vector<vector<char> > a = {
        {'0','0','1','0','1','1','0','1'},
        {'1','0','1','1','1','1','0','1'},
        {'0','0','0','0','1','1','0','0'},
    };
    //vector<int> a = {1,1};
    cout << slu.maximalRectangle(a) << endl;
    return 0;
}


