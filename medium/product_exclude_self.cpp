class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(), 1);
            int left = 1;   
            //  product of all the elements to the left of the current element
            for (int i = 0; i < nums.size(); i++) {
                res[i] *= left;
                left *= nums[i];
            }
            
            int right = 1;
            // product of all the elements to the right of the current element
            for (int i = nums.size()-1; i >= 0; i--) {
                res[i] *= right;
                right *= nums[i];
            }

            // time complextity O(n)
            return res;
        }
};