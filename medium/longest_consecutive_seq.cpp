class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            // using find() to check if the element is in the set -> O(n)
            unordered_set<int> s(nums.begin(), nums.end());
            int res = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (s.find(nums[i]) == s.end()) {
                    continue;
                }
                s.erase(nums[i]);
                int prev = nums[i] - 1;
                int next = nums[i] + 1;
                while (s.find(prev) != s.end()) {
                    s.erase(prev--);
                }
                while (s.find(next) != s.end()) {
                    s.erase(next++);
                }
                res = max(res, next - prev - 1);
            }
            return res;
        }
};
