class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int diff = INT_MAX;

       
        for(int i = 0; i < n-1; i++) {
            diff = min(diff, nums[i+1] - nums[i]);
        }

        vector<vector<int>> ans;

      
        for(int i = 0; i < n-1; i++) {
            if(nums[i+1] - nums[i] == diff) {
                ans.push_back({nums[i], nums[i+1]});
            }
        }

        return ans;
    }
};
