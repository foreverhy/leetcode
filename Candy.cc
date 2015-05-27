#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int candy(vector<int> &ratings){
        if (ratings.empty()){
            return 0;
        }
        int len = ratings.size();
        int top = 1;
        int heap = 0;
        int last = 1;
        int sum = 1;
        int tpos = 0;
        for (int i = 1; i < len; ++i){
            if (ratings[i] < ratings[i - 1]) {
                if (last > 1){
                    last = 1;
                    heap = 1;
                } else{
                    if (heap + 1 == top){
                        sum += i - tpos; 
                        ++top;
                        ++heap;
                    } else {
                        sum += i - tpos - 1;
                        ++heap;
                    }
                }

            } else if (ratings[i] > ratings[i - 1]) {
                ++last;
                top = last;
                heap = 0;
                tpos = i;
            } else {
                tpos = i;
                top = 1;
                heap = 0;
                last = 1;
            }
            sum += last;
        }
        return sum;
    }
};



int main(){
    Solution slu;
    vector<int> a = {7, 4, 5, 2, 8, 1};
    a = { 2, 1};
    //a = {2, 3, 2};
    cout << slu.candy(a) << endl;


    return 0;
}


