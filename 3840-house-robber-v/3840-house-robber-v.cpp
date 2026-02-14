class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        long long pm=nums[0];
        long long pc=colors[0];
        long long ppm=0;
        long long result=nums[0];
        for( int i =1;i<n;i++){
            long long take=nums[i];
            if(colors[i]==pc){
                take+=ppm;
            }
            else{
                take+=pm;
            }
            long long skip=pm;
            if(take>skip){
                ppm=pm;
                pm=take;
                pc=colors[i];
            }
            else{
                ppm=pm;
            }
            result=max(result,max(take,skip));
        }
        return result;
 
        }
     
};