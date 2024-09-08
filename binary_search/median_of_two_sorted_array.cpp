# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // partition the smaller array
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = nums1.size();

        while (l <= r) {
            int partition1 = l + (r - l) / 2;
            int partition2 = (nums1.size() + nums2.size() + 1) / 2 - partition1;
            
            double maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            double minRight1 = partition1 == nums1.size() ? INT_MAX : nums1[partition1];
            double maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
            double minRight2 = partition2 == nums2.size() ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
               
                double ans;
                if ((nums1.size() + nums2.size()) % 2 == 0) ans = ((double)max(maxLeft1, maxLeft2) + (double)min(minRight1, minRight2)) / 2.0;
                else ans = double(max(maxLeft1, maxLeft2));
                cout << ans << endl;

                return ans;
            }       // modify the partition of the smaller array
            else if (maxLeft1 > minRight2) r = partition1 - 1;
            else l = partition1 + 1;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}