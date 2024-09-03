# include <iostream>
# include <vector>

using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> min_stack;
    
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        // store the minimum value at the top of the min_stack
        if (min_stack.empty() || val <= min_stack.back()) {
            min_stack.push_back(val);
        }
    }

    void pop() {
        if (stack.back() == min_stack.back()) {
            min_stack.pop_back();
        }
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min_stack.back();
    }
};