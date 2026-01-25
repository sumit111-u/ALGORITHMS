class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i <= n - k; i++) {
            bool ok = true;

            // check consecutive
            for(int j = i; j < i + k - 1; j++) {
                if(nums[j] + 1 != nums[j + 1]) {
                    ok = false;
                    break;
                }
            }

            if(ok)
                ans.push_back(nums[i + k - 1]); // last is max
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
