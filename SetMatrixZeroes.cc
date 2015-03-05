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
    void setZeroes(vector<vector<int> > &matrix){
        int m = matrix.size(), n = matrix[0].size();
        bool first_row = true;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(0 == matrix[i][j]){
                    if(0 == i){
                        first_row = false;
                    }else{
                        matrix[i][0] = 0;
                    }
                     matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            if(!matrix[i][0]){
                for(int j = 0; j < n; ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < n; ++j){
            if(!matrix[0][j]){
                for(int i = 0; i < m; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        if(!first_row){
            for(int j = 0; j < n; ++j){
                matrix[0][j] = 0;
            }
        }

    }

};



int main(){
    Solution slu;
    using std::cin;


    return 0;
}


