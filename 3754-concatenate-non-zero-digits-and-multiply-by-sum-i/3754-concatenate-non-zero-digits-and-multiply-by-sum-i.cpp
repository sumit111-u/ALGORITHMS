class Solution {
public:
    long long sumAndMultiply(int n) {
      long long sum=0;
      long long newnum=0;
      int i=1;
    //   if(n==0) return 0;
        while(n){
            int digit=n%10;
            if(digit!=0){
                newnum+=digit*i;
               i= i*10;
               sum+=digit;

            }
            n=n/10;
        }
        return 1ll*newnum*sum;
        
    }
};