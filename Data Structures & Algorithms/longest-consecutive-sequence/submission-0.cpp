class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            // only start counting from the beginning of a sequence
            if (s.find(x - 1) == s.end()) {
                int cur = x;
                int len = 1;
                while (s.find(cur + 1) != s.end()) {
                    cur++;
                    len++;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};