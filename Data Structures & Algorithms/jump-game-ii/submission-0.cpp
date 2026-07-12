class Solution {
public:
int jump(vector<int>& nums) {
    // If the array has 0 or 1 element, we are already at the end.
    if (nums.size() <= 1) return 0; 

    int jumps = 0;
    int currentJumpEnd = 0;
    int farthest = 0;

    
    for (int i = 0; i < nums.size() - 1; i++) {
        
        
        farthest = max(farthest, i + nums[i]);

        if (i == currentJumpEnd) {
            jumps++;                    
            currentJumpEnd = farthest;  

            // Minor optimization: If our new boundary reaches the end, stop early
            if (currentJumpEnd >= nums.size() - 1) {
                break;
            }
        }
    }
    
    return jumps;
}
};
