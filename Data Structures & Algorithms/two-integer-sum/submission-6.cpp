class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos; // value -> index

        for (int i = 0; i < (int)nums.size(); i++) {
            int need = target - nums[i];

            auto it = pos.find(need);
            if (it != pos.end()) {
                return {it->second, i};
            }

            // store AFTER checking so we don't use the same element twice
            pos[nums[i]] = i;
        }

        return {}; // in LeetCode, it's guaranteed to exist, but keep it safe
    }
};