class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<pair<int, int>> s;    // save index and height

        for (int i = 0; i <= heights.size(); i++) {
            int cur = i;
            
            // handle the last element
            if (i == heights.size()) {
                while (!s.empty()) {
                    pair<int, int> p = s.top();
                    s.pop();
                    max_area = max(max_area, p.second * (i - p.first));
                }
                break;
            }

            while (!s.empty() && s.top().second > heights[i]) {
                pair<int, int> p = s.top();
                s.pop();
                max_area = max(max_area, p.second * (i - p.first));
                cur = p.first;
            }
            s.push({cur, heights[i]});
        }

        return max_area;
    }
};