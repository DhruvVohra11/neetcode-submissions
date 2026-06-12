class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value}); // timestamps come in non-decreasing order in LeetCode
    }

    // return index of largest timestamp <= tar, or -1 if none
    int bsearch(vector<pair<int,string>> &x, int l, int r, int tar) {
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (x[mid].first <= tar) {
                ans = mid;        // mid is a valid candidate
                l = mid + 1;      // try to find a larger one still <= tar
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        auto &vec = mp[key];
        if (vec.empty()) return "";

        int idx = bsearch(vec, 0, (int)vec.size() - 1, timestamp);
        if (idx == -1) return "";
        return vec[idx].second;
    }
};