# include <iostream>
# include <stack>
# include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c =='(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty()) return false;
                if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{')) return false;
                st.pop();
            }
        }
        return st.empty();      
    }
};


int main() {
    Solution sol;
    string s = "()";
    cout << sol.isValid(s) << endl;
    return 0;
}