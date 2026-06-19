class Solution {
public:
    int findKthPositive(vector<int>& arr, int s) {
        int n=arr.size();
        for( int i =0;i<n;i++){
            if( s>=arr[i]){
                s++;
            }
        }
        return s ;
    }
};