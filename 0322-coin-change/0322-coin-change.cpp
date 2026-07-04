class Solution {
public:
int n;
int INF=1e9;
int solve(vector<int>& coins,int i ,int amount,vector<vector<int>>&dp){
   
   if(amount==0){
    return 0;
   }
   if(i>=coins.size()|| amount<0) return INF;
   if( dp[i][amount]!=-1) return dp[i][amount];
   int take=INF;
  if (coins[i] <= amount)
    take=1+solve(coins,i,amount-coins[i],dp);
   int nottake=0+solve(coins,i+1,amount,dp);
 return  dp[i][amount]=min(take,nottake);


}
    int coinChange(vector<int>& coins, int amount) {

int n=coins.size();
vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
int i=0;
          int ans= solve( coins,i,amount,dp);
                  return (ans >= INF ? -1 : ans);
    }
};