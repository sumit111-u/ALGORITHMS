class Solution {
public:

//   total karan layi functiom
int totalans(vector<int>& nums,int div){
    int n=nums.size();
    int total =0;
    for( int i=0;i<n;i++){
        total+=ceil((double)(nums[i])/(double)(div));
    }
 return total;
}

int bs(vector<int>& nums, int threshold){
    int ans=0;
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
     while( low<=high){
        int mid=(low+high)/2;
        if(totalans(nums,mid)<=threshold){
            ans=mid;
            high=mid-1;
        
        }
        else{
            low=mid+1;
        }
     }
     return low;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        // bs on ans  
         return bs(nums,threshold);

        
    }
};