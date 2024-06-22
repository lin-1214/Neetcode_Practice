class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            unordered_set<string> s;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    char num = board[i][j];
                    if (num != '.') {
                        string row = "row" + to_string(i) + num;
                        string col = "col" + to_string(j) + num;
                        string box = "box" + to_string(i/3) + to_string(j/3) + num;
                        if (s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end()) {
                            return false;
                        }
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    }
                }
            }
            return true;
        }
};