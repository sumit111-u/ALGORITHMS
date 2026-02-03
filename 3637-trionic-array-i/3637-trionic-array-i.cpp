class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n = nums.size();
        int p = 0;

        // Find the strictly increasing part from the beginning
        while (p < n - 2 && nums[p] < nums[p + 1]) {
            p++;
        }

        // There must be at least one increasing element
        if (p == 0) {
            return false;
        }

        int q = p;

        // Find the strictly decreasing part
        while (q < n - 1 && nums[q] > nums[q + 1]) {
            q++;
        }

        // There must be at least one decreasing element
        // Check: did we decrease at all, and did we reach the end?
        if (q == p || q == n - 1) {
            return false;
        }

        // Check for strictly increasing sequence after the peak
        while (q < n - 1 && nums[q] < nums[q + 1]) {
            q++;
        }

        // If we have reached the last element, the pattern matches
        return q == n - 1;
    }
};

 