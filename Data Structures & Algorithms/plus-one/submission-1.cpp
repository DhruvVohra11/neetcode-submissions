class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(digits[len-1] != 9){
            digits[len-1] += 1;
            return digits;
        }
        vector<int> temp(len+1);
        for(int i=len-1; i>=0; i--){
            if(i == 0 and digits[0] == 9){
                temp[0] = 1;
                return temp;
            }
            if(digits[i] == 9){
                digits[i] = 0;
                temp[i+1] = digits[i];
            }
            else{
                digits[i] += 1;
                return digits;
            }
        }

    }
};
