class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        vector<pair<int,int>> temp;
        for(int i = 0; i < (int)position.size(); i++){
            temp.push_back({position[i], speed[i]});
        }
        sort(temp.begin(), temp.end());

        stack<double> st;   // was stack<int>
        int fleet = 0;

        // iterate from closest-to-target to farthest
        for(int i = (int)temp.size() - 1; i >= 0; --i){
            auto &x = temp[i];

            double iter = (double)(target - x.first) / (double)x.second; // was ceil(int/int)

            if(st.empty()){
                st.push(iter);
                fleet += 1;
            } else {
                // if this car takes longer than the fleet ahead, it becomes a new fleet
                if(iter > st.top()){
                    st.push(iter);
                    fleet += 1;
                }
                // else it catches up -> same fleet, do nothing
            }
        }
        return fleet;
    }
};