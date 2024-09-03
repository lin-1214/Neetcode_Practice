class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;    // map element to frequency
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;  // sort by frequency
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }

        vector<int> res;    // store the top k frequent elements
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};