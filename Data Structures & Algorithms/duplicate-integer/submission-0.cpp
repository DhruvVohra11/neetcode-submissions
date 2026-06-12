class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dups(nums.begin(), nums.end());
        if(dups.size() != nums.size()) return true;

        return false;
    }
};