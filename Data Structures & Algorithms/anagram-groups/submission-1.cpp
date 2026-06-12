class Solution {
public:
    int h_sum(const std::string& s) {
    uint64_t sum = 0, sumsq = 0;
    for (unsigned char c : s) {
        sum   += c;
        sumsq += uint64_t(c) * uint64_t(c);
    }
    // mix in length too
    uint64_t len = s.size();

    // cheap mixing (order-independent inputs, order-dependent mixing)
    uint64_t h = sum ^ (sumsq + 0x9e3779b97f4a7c15ULL) ^ (len * 0xBF58476D1CE4E5B9ULL);
    h ^= (h >> 30);
    h *= 0xBF58476D1CE4E5B9ULL;
    h ^= (h >> 27);
    h *= 0x94D049BB133111EBULL;
    h ^= (h >> 31);
    return (int)h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> ana;
        int i = 0;
        for(auto & x : strs){
            auto hash = h_sum(x);
            if(ana.find(hash) == ana.end()){
                ana[hash] = vector<string>();
                ana[hash].push_back(x);
            }
            else ana[hash].push_back(x);
        }
        vector<vector<string>> res;

        for(auto & rand : ana){
            res.push_back(rand.second);
        }
        return res;

    }
};
