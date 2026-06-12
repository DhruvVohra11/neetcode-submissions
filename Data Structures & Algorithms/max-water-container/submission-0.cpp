class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int i = 0;
        int j = heights.size() - 1;

        while(i<j){
            int area = (j-i)*min(heights[i],heights[j]);
            if(area >= max){
                max = area;
            }
            if(heights[i]<=heights[j]){
                i++;
            }
            else j--;
        }
        return max;
    }
};
