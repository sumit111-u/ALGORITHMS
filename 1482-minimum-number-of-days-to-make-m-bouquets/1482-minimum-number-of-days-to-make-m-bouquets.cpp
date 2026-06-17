class Solution {
public:
//bloo or not fn
bool bloom(vector<int>& bloomDay,int day, int m ,int k){
    int count=0 ;
    int b=0;
    int n=bloomDay.size();
    for( int i=0;i<n;i++){
    if(bloomDay[i]<=day){
        count++;

    }
    else{
        b+=count/k;
        count=0;
    }

    }
    b+=count/k;
    cout<<"b"<<b<<endl;
    return b>=m ;
}



// bs
int bs(vector<int>& bloomDay, int m ,int k){
    long long val=m*1ll*k*1ll;
    if(val>bloomDay.size()) return -1;
    int low =*min_element(bloomDay.begin(),bloomDay.end());
 int high=*max_element(bloomDay.begin(),bloomDay.end());
 while(low<=high){
    int mid=(low+high)/2;
    if(bloom(bloomDay,mid,m,k)==true){
        high=mid-1;


    }// ethe else nahi c paya 
    else{
    low=mid+1;
 }
 }
 return low;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        // bs
       return bs(bloomDay,m,k);
    }
};