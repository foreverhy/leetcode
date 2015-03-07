class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        auto m = matrix.size();
        auto n = matrix[0].size();
        int  p = 0, q = m - 1;
        while(p < q){
            auto mid = (p + q) >> 1; 
            if(target < matrix[mid][0]){
                // upper area
                q = mid ;
            }else if(target < matrix[mid+1][0]){
                break;
                //this area
            }else{
                p = mid + 1;
                // down area
            }
        }

        if(p <= q && q < m && p >= 0){
            auto mid = (p + q) >> 1;
            int l = 0, r = n - 1 ;
            while(l < r){
                auto mlr = (l + r) >> 1;
                if(target == matrix[mid][mlr])return true;
                if(target < matrix[mid][mlr]){
                    r = mlr;
                }else{
                    l = mlr + 1;
                }
            }
            if(l == r)return matrix[mid][l] == target;
        }
        return false;
    }
};
