class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> exi;
        int ret = 0;
        int l = 0; // left pointer

        for (int i = 0; i < (int)s.size(); i++) {
            // if s[i] already in window, shrink from left until it isn't
            while (exi.count(s[i])) {
                exi.erase(s[l]);
                l++;
            }
            exi.insert(s[i]);
            ret = max(ret, i - l + 1);
        }
        return ret;
    }
};
