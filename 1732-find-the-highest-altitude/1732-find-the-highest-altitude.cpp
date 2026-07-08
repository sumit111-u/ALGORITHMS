class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int maxi=0;
        vector<int>res;
        res.push_back(0);
        int n=gain.size();
         for ( int i =0;i<n;i++){
        alt+=gain[i];
res.push_back(alt);

         }
         return *max_element(res.begin(),res.end());
        
    }
};