class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //max heap 
        std::priority_queue<std::pair<double, vector<int>>> dis;
        vector<vector<int>> ans;
        int i = 0;
        for(auto & x : points){
            double euc = sqrt(x[0]*x[0] + x[1]*x[1]);
            if(i<k){
                dis.push({euc, x});
                i++;
            }
            else{
                auto & top = dis.top();
                if(euc < top.first) {
                    dis.pop();
                    dis.push({euc, x});
                }
            }
        }

        while(!dis.empty()){
            ans.push_back(dis.top().second);
            dis.pop();
        }

        return ans;
    }
};
