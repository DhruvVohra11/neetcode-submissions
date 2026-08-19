class Solution {
public:
    int fact(int n){
            int f = 1;
            for(int i = n; i>=1; i--){
                f *= i;
            }
            return f;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while(std::next_permutation(nums.begin(), nums.end())){
            ans.push_back(nums);
        }
        return ans;
    }
};
