class Solution {
public:
   
    int helper(int n,vector<int>& dp){
        if(n==0){return 0;}
        if(n==1){return 1;}
        if(n==2){return 2;}
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n]=helper(n-1,dp)+helper(n-2,dp);
        return dp[n];
    }

    int climbStairs(int n) {
         vector<int> dp(n+1,-1);
        int x=helper(n,dp);
        
        return x;
    }
};