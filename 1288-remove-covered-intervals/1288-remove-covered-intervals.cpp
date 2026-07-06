class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        auto comparator=[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];

            }
            else{
                return a[0]<b[0];
            }


        };
        sort( intervals.begin(),intervals.end(),comparator);
        int count=0;
        int maxend=0;

    for( auto & it :intervals){
        if(it[1]>maxend){
            count++;
            maxend=it[1];
        }

    }
    return count;
        
    }
};