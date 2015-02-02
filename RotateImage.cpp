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

    void rotate(vector<vector<int> > &matrix){
        int N = matrix.size();
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                if(i != j){
                    std::swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0, k = N - 1; j < k; ++j, --k){
                std::swap(matrix[i][j], matrix[i][k]);
            }
        }
    }



};



int main(){
    Solution slu;
    using std::cin;

    vector<vector<int> > a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},

    };

    slu.rotate(a);
    for(auto &row: a){
        for(auto &v: row){
            cout << v << " ";
        }
        cout << endl;
    }


    return 0;
}


