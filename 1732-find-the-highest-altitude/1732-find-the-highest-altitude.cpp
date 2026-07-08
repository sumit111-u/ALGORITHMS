class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0;
        int mx=0;
    for( auto &g :gain){
    curr+=g;
    mx=max(curr,mx);
    
}
    return mx;
    }
};