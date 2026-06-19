class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> hs;
        while(n>0){
            hs.insert(n);
                int x = n;
                int sum = 0;
                while(x>0){

                    int d = x%10;
                    sum += d*d;
                    x /= 10;

                }
            n = sum;
            
            if(n==1) return true;
            if(hs.contains(n)){
                return false;
            }
        }
        return true;
    }
};
