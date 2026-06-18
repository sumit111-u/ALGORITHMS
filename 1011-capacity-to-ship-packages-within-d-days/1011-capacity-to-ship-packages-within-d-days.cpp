class Solution {
public:
// we can reduce the search space  using binary search
int totaldays(vector<int>& weights, int capacity){
    int day=1; int load=0;
    int n =weights.size();
    for( int i =0;i<n;i++){
        if(load+weights[i]>capacity){
            day++;
            load=weights[i];
        }
        else{
            load+=weights[i];

        }
    }
    cout<<"days"<<day<<endl;
    return day;
    
}

 int bs(vector<int>& weights, int days){
    int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while( low<=high){
            int mid=( low+high)/2;
            if(totaldays(weights,mid)<=days){
                 int ans=mid;
                 high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

    


 }
    int shipWithinDays(vector<int>& weights, int days) {
   return  bs(weights,days);
    }
    
};