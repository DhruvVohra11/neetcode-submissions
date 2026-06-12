class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //find the bucket of the target binary search here too
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++){
            if(target>matrix[i][n-1]) continue;
            else{
            int l = 0;
            int r = n-1;
            int mid = (l+r)/2;
            while(l<=r){
                if(target == matrix[i][mid]) return true;
                else if(target < matrix[i][mid]){
                    r = mid - 1;
                    mid = (l+r)/2;
                    continue;
                }
                else{
                    l = mid + 1;
                    mid = (l+r)/2;
                    continue;
                }
            }
            break;
            }
        }
        return false;
        
        // do binary search on the bucket 

        
    }
};
