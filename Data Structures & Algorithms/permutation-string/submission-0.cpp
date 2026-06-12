class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = (int)s1.size();
        int n = (int)s2.size();
        if (k > n) return false;

        for (int i = 0; i <= n - k; i++) {
            string temp = s2.substr(i, k);  // FIX: use s2, length = k

            unordered_map<char,int> f;      // FIX: need counts, not set
            for (char c : temp) f[c]++;

            bool flag = true;
            for (int j = 0; j < k; j++) {   // FIX: don't reuse i
                char c = s1[j];
                if (f[c] == 0) {            // FIX: count check
                    flag = false;
                    break;
                }
                f[c]--;
            }

            if (flag) return true;
        }
        return false;
    }
};
