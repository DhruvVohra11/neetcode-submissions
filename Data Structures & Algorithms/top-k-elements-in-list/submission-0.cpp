class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        
        for(auto & x: nums){
            if(freq.find(x) == freq.end()){
                freq[x] = 1;
            }
            else{
                freq[x]++;
            }
        }
        
        for (int i = 0; i<k; i++){
        int mn = 0;
        int mi = 0;
        for(auto & x: freq){
            if(x.second>mn){
                mn = x.second;
                mi = x.first;
            } 
        }
        res.push_back(mi);
        freq.erase(mi);
        }

        return res;
        
    }
};
