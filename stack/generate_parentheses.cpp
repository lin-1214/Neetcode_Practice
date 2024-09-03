# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<char> stack;
    
    void backTrack(int open, int close, int n) {
        if (stack.size() == 2 * n) {
            string s;
            s.append(stack.begin(), stack.end());
            res.push_back(s);
            return;
        } 

        if (open < n) {
            stack.push_back('(');
            backTrack(open + 1, close, n);
            stack.pop_back();
        }

        if (close < open) {
            stack.push_back(')');
            backTrack(open, close + 1, n);
            stack.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        backTrack(0, 0, n);
        return res;

    }
};

int main() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}