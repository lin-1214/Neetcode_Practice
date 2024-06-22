class Solution {
    public:

        string encode(vector<string>& strs) {
            string res = "";
            for (int i = 0; i < strs.size(); i++) {
                res += to_string(strs[i].length()) + " " + strs[i];
            }
            return res;
        }

        vector<string> decode(string s) {
            vector<string> res;
            int i = 0;
            while (i < s.length()) {
                int j = s.find(" ", i);
                int len = stoi(s.substr(i, j-i));
                res.push_back(s.substr(j+1, len));
                i = j+1+len;
            }
            return res;
        }
};