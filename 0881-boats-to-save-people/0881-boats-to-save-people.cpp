
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j){
            if(people[i]+people[j]==limit ||people[i]+people[j]<limit){
                count+=1;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit){
                j--;
              

            }
 
           

        }
          count+=n-2*count;
        return count;
    }
};