class Solution {
public:
int solve(int index, vector<int>&nums,vector<int>&dp){
    if(index==0) return nums[index];
   else if(index<1) return 0;
   if(dp[index]!=-1) return dp[index];
   else {
        int pick=nums[index]+solve(index-2,nums,dp);
        int notpick=0+solve(index-1,nums,dp);
        return dp[index]= max(pick,notpick);
   }
    
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
         return solve(n-1,nums,dp);
        
        
    }
};
//  isko memoize bhi karna padega 