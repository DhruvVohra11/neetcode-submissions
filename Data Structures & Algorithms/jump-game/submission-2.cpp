class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        int m = nums[0];
        int s = nums.size();
        if(s == 1 || s==0 ) return true;
        for(int i = 0; i<s;){
            m = max(nums[i], m);
            if(m == 0) return false;
            if(m>0){
                i++;
                m--;
            }
            if(i == nums.size()-1) return true;
            
        }

        return false;

    }
};
