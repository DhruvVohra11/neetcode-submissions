class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> rocks;
        for(auto & x : stones) rocks.push(x);
        

        while(rocks.size()>1){
            if(rocks.size() == 1) return rocks.top();
            if(rocks.size() == 0) return 0;

            auto r1 = rocks.top();
            rocks.pop();
            auto r2 = rocks.top();
            rocks.pop();

            if(r2 == r1){
                if(rocks.size() == 0) return 0;
            }
            else {
                auto r3 = abs(r2-r1);
                rocks.push(r3);
            }

            
            
        }

        return rocks.top();
        
    }
};
