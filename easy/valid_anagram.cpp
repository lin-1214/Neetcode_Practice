class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if (sLen != tLen) {
            return false;
        } else {
            unordered_map<char, int> sMap;
            unordered_map<char, int> tMap;
            for (int i = 0; i < sLen; i++) {
                sMap[s[i]]++;
                tMap[t[i]]++;
            }
            for (int i = 0; i < sLen; i++) {
                if (sMap[s[i]] != tMap[s[i]]) {
                    return false;
                }
            }
            return true;
        }
    }
};
