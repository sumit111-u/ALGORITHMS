class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum=0;
        map<int,int>mp;
        int m=mp.size();
        for(auto it:nums){
            mp[it]++;}
            for(auto p:mp){
            if(p.second==1){
                sum+=p.first;

            }}
            return sum;

            

        }
    
    
};