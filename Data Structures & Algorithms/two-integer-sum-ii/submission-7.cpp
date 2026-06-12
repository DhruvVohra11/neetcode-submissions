class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idi = 0;
        int idf = (int)numbers.size() - 1;
        vector<int> res;

        while (idi < idf) {
            int sum = numbers[idi] + numbers[idf];
            if (sum == target) {
                res.push_back(idi + 1);
                res.push_back(idf + 1);
                return res;
            } 
            else if (sum < target) {
                idi++;
            } 
            else {
                idf--;
            }
        }
        return res;
    }
};
