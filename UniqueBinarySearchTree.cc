#include "leet.h"




#include <algorithm>
#include <cstring>



static int f[30] = {1, 1};

class Solution{
  public:
    int numTrees(int N){
        f[0] = f[1] = 1;
        if (N <= 1){
            return f[N];
        }
        for (int n = 2; n <= N; ++n){
            int sum = 0;
            for (int i = 0; i < (n>>1); ++i){
                sum += f[i] * f[n - 1 - i];
            }
            sum *= 2;
            if (n & 1){
                sum += f[(n>>1)] * f[(n>>1)];
            }
            f[n] = sum;

        }
        return f[N];
    }

};



int main(){
    Solution slu;

    for(int x = 1; x <20; ++x)
        cout << slu.numTrees(x) << endl;




    return 0;
}


