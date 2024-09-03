class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> map;
            for (int i = 0; i < strs.size(); i++) {
                string s = strs[i];
                sort(s.begin(), s.end());   // sort the string
                map[s].push_back(strs[i]);
            }
            vector<vector<string>> res;
            for (auto it = map.begin(); it != map.end(); it++) {
                res.push_back(it->second);  
            }
            return res;    
        }

};