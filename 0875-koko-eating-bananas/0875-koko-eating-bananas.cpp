class Solution {
public:
int maxelement(vector<int>&piles){
    int ans=piles[0];
    int n=piles.size();
    for( int i=0;i<n;i++){
       ans=max(ans,piles[i]);
    }
    return ans;
}
 
double totalhours(vector<int>&piles, int hourly){
    int n=piles.size();
       double totalhours=0;
    for( int i=0;i<n;i++){
      totalhours +=ceil(double(piles[i])/double(hourly));
    }
    return totalhours;
}
  int bs(vector<int>&piles, int h ){
 int n=piles.size();
 int low=1;
 int high=maxelement(piles);
 cout << "low = " << low << endl;
cout << "high = " << high << endl;
 
 while(low<=high){
 int mid=(low+high)/2;

   double totalhourss=totalhours(piles,mid);
   if(totalhourss<=h){
    high=mid-1;
   }
   else{
    low=mid+1;
   }
   
 }
 return low;

  }
    int minEatingSpeed(vector<int>& piles, int h) {
        return bs(piles,h);
        
    }
};