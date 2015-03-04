class Solution {
public:
    int climbStairs(int n) {
        if(1 == n)return 1;
        if(2 == n)return 2;
        int f1 = 1;
        int f2 = 2;
        for(int i = 3; i <= n; ++i){
            int tp = f2;
            f2 = f1 + f2;
            f1 = tp;
        }
        return f2;
    }
};
