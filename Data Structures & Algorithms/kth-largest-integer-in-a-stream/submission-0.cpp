class KthLargest {
public:

    priority_queue<int> maxh;
    int kl;

    KthLargest(int k, vector<int>& nums) {
        
        for(auto & num: nums){
            maxh.push(num);
        }
        kl = k;
        
    }
    
    int add(int val) {
        maxh.push(val);
        auto x = maxh;
        for(int i = 0; i<kl-1; i++){
            x.pop();
        }
        return x.top();
    }
};
