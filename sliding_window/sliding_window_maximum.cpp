class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // store the index of the elements in the window
        for (int i = 0; i < nums.size(); i++) {
            // remove the element that is out of the window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // remove the elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;      
    }
};