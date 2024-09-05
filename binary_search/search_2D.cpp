class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int row = l + (r - l) / 2;
        int n = matrix[0].size();
        
        while ((target > matrix[row][n - 1] || target < matrix[row][0])) {
            if (target > matrix[row][n - 1]) {
                l = row + 1;
            } else {
                r = row - 1;
            }

            if (l > r) break;
            else row = l + (r - l) / 2;
        }

        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return false;
    }
};