class Solution {
public:
        vector<int> dp;
    int f(vector<int>& coins, int n){
        if(n==0){return 0;}

        if(dp[n]!=-2){return dp[n];}
        int result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(n-coins[i]<0){continue;}
              int x = f(coins, n - coins[i]);

            if (x != -1)
                result = min(result, 1 + x);
        }
            
        dp[n] = result == INT_MAX ? -1 : result;
        return dp[n];
    }
    int coinChange(vector<int>& coins, int n) {
        dp.clear();
        dp.resize(100000,-2);
        return f(coins,n);
    }
};