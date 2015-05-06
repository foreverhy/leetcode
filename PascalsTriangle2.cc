#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<int> getRow(int numRows){
        ++numRows;
        vector<int> f1(numRows, 0);
        vector<int> f2(numRows, 0);
        if (!numRows){
            return {};
        }

        f1[0] = 1;
        for (int i = 1; i < numRows; ++i){
            for (int j = 0; j < i + 1; ++j){
                if (0 == j){
                    f2[j] = f1[j];
                } else if (i == j){
                    f2[j] = f1[j - 1];
                } else {
                    f2[j] = f1[j - 1] + f1[j];
                }
            }
            std::swap(f1, f2);
        }
        return f1;
    }
};



int main(){
    Solution slu;

    int i;
    while (cin >> i){
        auto ans = slu.getRow(i);
        cout << ans << endl;
    }



    return 0;
}


