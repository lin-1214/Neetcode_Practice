class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<char, int> map;
        int left = 0, right = 0;    
        int max_len = 0;
        int max_count = 0;
        while (right < n) {
            char c = s[right];
            map[c]++;
            max_count = max(max_count, map[c]); // find the most frequent character in the window
            if (right - left + 1 - max_count > k) {     // sliding window tech.
                map[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;      
    }
};