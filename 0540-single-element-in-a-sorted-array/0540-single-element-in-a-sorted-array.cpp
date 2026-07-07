class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xori=0;
        for( auto & n :nums){
            xori^=n;
        }
        return xori;
        
    }
};