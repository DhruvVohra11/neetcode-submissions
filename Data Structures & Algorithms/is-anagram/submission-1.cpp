class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq_map;
        for(auto & ch: s){
            if(freq_map.find(ch) == freq_map.end()){
                freq_map[ch] = 1;
            }
            else {
                freq_map[ch]++;
            }
        }
        for(auto & ch: t){
            if(freq_map.find(ch) == freq_map.end() || freq_map[ch]==0){
                return false;
            }
            else {
                freq_map[ch]--;
                if(freq_map[ch]==0) freq_map.erase(ch);
            }
        }
        if(freq_map.size() == 0)
        return true;
        
        return false;
    }
};
