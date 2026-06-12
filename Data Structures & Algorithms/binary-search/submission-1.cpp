class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid = (l+r)/2;

        while(l<=r){
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]){
                r = mid-1;
                mid = (r+l)/2;
            }
            else{
                l = mid+1;
                mid = (r+l)/2;
            }
        }
        return -1;
    }
};
