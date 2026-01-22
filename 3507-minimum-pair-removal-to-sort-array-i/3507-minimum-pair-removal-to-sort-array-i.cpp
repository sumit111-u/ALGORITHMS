class Solution {
public:

int minpairsum(vector<int>&nums){
    int minsum=INT_MAX;
    int index=-1;
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        if(nums[i]+nums[i+1]<minsum){
            index=i;
            minsum=nums[i]+nums[i+1];
        }
    }
    return index;
}
    int minimumPairRemoval(vector<int>& nums) {
       int count=0;
       while(!is_sorted(begin(nums),end(nums))){
        int index=minpairsum(nums);
        nums[index]=nums[index]+nums[index+1];
        nums.erase(begin(nums)+index+1);
        count++;
        
       }
       return count;
    } 
};