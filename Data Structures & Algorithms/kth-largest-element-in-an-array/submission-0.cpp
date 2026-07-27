class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // max heap and pop twice
        priority_queue<int> q;
        for(auto x : nums){
            q.push(x);
        }
        for(int i = 0; i<k-1; i++){
            q.pop();
        }
        int ans = q.top();
        return ans;

    }
};
