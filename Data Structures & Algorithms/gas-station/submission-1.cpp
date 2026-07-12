class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c = 0;
        int g = 0;
        int mx = 0;
        
        for(int i = 0; i<gas.size(); i++){
            g += gas[i];
            c += cost[i];
            if((gas[i]-cost[i])>mx) mx = i;
        } 

        if(c>g) return -1;
        return mx;

        
    }
};
