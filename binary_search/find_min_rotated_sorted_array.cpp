class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int res = nums[0];

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
                res = nums[mid];
            }
        }

        return res;
    }
};