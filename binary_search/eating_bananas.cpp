# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long tmp = 0;

            for (int i = 0; i < piles.size(); i++) {
                tmp += ceil(static_cast< float >(piles[i]) / mid);
            }

            if (tmp <= h) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> piles = {1, 4, 3, 2};
    int h = 5;
    cout << s.minEatingSpeed(piles, h) << endl;
    return 0;
}