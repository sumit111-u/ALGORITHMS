class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentsum =0;
        int maxans= INT_MIN;
        for( int i=0;i<n;i++){
            currentsum=currentsum+nums[i];
          
            maxans= max(currentsum,maxans);
            if(currentsum<0){
                currentsum=0;
            }
            
        }
        return maxans;
    }
};