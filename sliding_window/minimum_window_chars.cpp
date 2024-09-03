# define INT_MAX 2147483647

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n == 0 || m == 0) {
            return "";
        }
        unordered_map<char, int> map;
        for (int i = 0; i < m; i++) {
            map[t[i]]++;
        }
        int left = 0, right = 0;
        int count = 0;
        int min_len = INT_MAX;
        int min_left = 0;
        while (right < n) {
            char c = s[right];
            if (map.find(c) != map.end()) {
                map[c]--;
                if (map[c] >= 0) {
                    count++;
                }
            }

            // find the window that contains all the characters in t
            while (count == m) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }
                char d = s[left];
                if (map.find(d) != map.end()) {
                    map[d]++;
                    if (map[d] > 0) {
                        count--;
                    }
                }
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
        


    }
};