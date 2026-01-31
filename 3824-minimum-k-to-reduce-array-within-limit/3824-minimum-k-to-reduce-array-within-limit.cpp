class Solution {
public:

    bool check(vector<int>&nums, int k){
        long long op=0;
        for( int i=0;i<nums.size();i++){
            op+=(nums[i]+k-1)/k;
        }
        return op<=1LL*k*k;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
       int l=1;
        int r=*max_element(nums.begin(),nums.end());
        r = max(r, n);

            int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,mid)){
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
            
        }
        return ans;
     
    }
};