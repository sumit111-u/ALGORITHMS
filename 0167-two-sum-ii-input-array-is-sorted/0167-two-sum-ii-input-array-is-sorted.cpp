class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        
       int j=0;
        int k=n-1;
        while(j<k){
        
            if(nums[j]+nums[k]==target){
                return{j+1,k+1};

            }
            else if(nums[j]+nums[k]<target){
                j++;
            }
            else if(nums[j]+nums[k]>target){
                k--;
              
            }
         
        
       

    }
    return{-1};
    }
};