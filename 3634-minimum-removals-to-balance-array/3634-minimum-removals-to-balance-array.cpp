class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0;
        int best = 1;

        for(int j = 0; j < n; j++) {
            while(i < j && (long long)nums[i] * k < nums[j]) {
                i++;
            }
            best = max(best, j - i + 1);
        }

        return n - best;
    }
};