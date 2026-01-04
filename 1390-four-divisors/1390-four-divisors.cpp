class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for(int num : nums){
            int count = 0;
            int currSum = 0;

            for(int i = 1; i * i <= num; i++){
                if(num % i == 0){
                    int d1 = i;
                    int d2 = num / i;

                    if(d1 == d2){
                        count += 1;
                        currSum += d1;
                    } else {
                        count += 2;
                        currSum += d1 + d2;
                    }

                    if(count > 4) break;
                }
            }

            if(count == 4){
                totalSum += currSum;
            }
        }

        return totalSum;
    }
};

