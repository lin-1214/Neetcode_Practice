class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < n) {
            char c = s[right];
            // find the last position of the duplicate character
            if (map.find(c) != map.end()) {
                left = max(left, map[c] + 1);
            }
            map[c] = right;
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};
