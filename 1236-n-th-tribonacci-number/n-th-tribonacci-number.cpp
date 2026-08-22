class Solution {
public:

        int helper(int i,vector<int> & dp){
            if(i==0){return 0;}
            if(i==1 || i==2){return 1;}

            if(dp[i]!=-1){return dp[i];}
            dp[i]=helper(i-1,dp)+helper(i-2,dp)+helper(i-3,dp);
            return dp[i];
        }

    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        int ans=helper(n,dp);
        return ans;


    }
};