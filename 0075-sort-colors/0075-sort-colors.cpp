class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        int twos=0;
        int zero=0;
        vector<int>freq;
        for( int i=0;i<n;i++){
   if(nums[i]==0) zero++;
 else if( nums[i]==1) ones++;
 else twos++;
        }

int index = 0;

for(int i = 0; i < zero; i++)
{
    nums[index++] = 0;
}

for(int i = 0; i < ones; i++)
{
    nums[index++] = 1;
}

for(int i = 0; i < twos; i++)
{
    nums[index++] = 2;
}

    }
};