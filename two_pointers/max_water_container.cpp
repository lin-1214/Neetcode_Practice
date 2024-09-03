class Solution {
    public:
        // from outer to inner
        int maxArea(vector<int>& heights) {
            int left = 0, right = heights.size()-1;
            int max_area = 0;
            while (left < right) {
                int area = min(heights[left], heights[right]) * (right - left);
                max_area = max(max_area, area);
                if (heights[left] < heights[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            return max_area;            
        }
};