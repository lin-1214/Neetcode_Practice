class TimeMap {
public:

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &values = mp[key];
        int l = 0, r = values.size() - 1;
        while (l <= r) {
            int mid = l + ( r - l) / 2;
            if (values[mid].first == timestamp) return values[mid].second;
            else if (values[mid].first < timestamp) l = mid + 1;
            else r = mid - 1;
        }

        // no matching timestamp, return the previous value
        return r >= 0 ? values[r].second : "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> mp;
};