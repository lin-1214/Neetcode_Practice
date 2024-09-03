class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {
            return false;
        }
        unordered_map<char, int> map;
        for (int i = 0; i < n1; i++) {
            map[s1[i]]++;
        }
        int left = 0, right = 0;
        int count = 0;
        while (right < n2) {
            char c = s2[right];
            if (map.find(c) != map.end()) {
                map[c]--;
                if (map[c] == 0) {
                    count++;
                }
            }
            if (right - left + 1 > n1) {
                char d = s2[left];
                if (map.find(d) != map.end()) {
                    if (map[d] == 0) {
                        count--;
                    }
                    map[d]++;
                }
                left++;
            }
            if (count == map.size()) {
                return true;
            }
            right++;
        }
        
        return false;
    }
};
