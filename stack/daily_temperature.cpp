class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int> res(temperatures.size(), 0);
       stack<int> st;
       for (int i = 0; i < temperatures.size(); i++) {
            // compare the next element with the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();   // pop the top element and remember the index
                res[idx] = i - idx;
            }
            st.push(i);
       }

       return res;
    }
};