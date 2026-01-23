class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
     long long  l=0;
    long long  ans =1;
   for(int r=0;r<n;r++){
    sum+=nums[r];
    long long cost=nums[r]*(r-l+1)-sum;
    while(cost>k){
sum-=nums[l];
l++;
 cost = nums[r] * (r - l + 1) - sum;

    }
    ans = max(ans, r - l + 1);
   }
   return ans;
    }
};