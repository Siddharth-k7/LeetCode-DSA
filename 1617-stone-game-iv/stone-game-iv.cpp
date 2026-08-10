class Solution {
public:
     vector<int> dp;
    bool solve(int n){

        if(n==0){return false;}
        if(dp[n]!=-1){
            return dp[n]==1 ? true:false;
        }

        for(int k=1;k*k<=n;k++){
            if(solve(n-k*k)==false) { // this is the call for BOB
            // this means Alice won the game 
             dp[n]=1;
                return true;
            }
        }

        // this means Alice did not win the game 
        return dp[n]=false;
    }


    bool winnerSquareGame(int n) {
      dp.assign(n+1,-1);
      return solve(n); 

        
        
    }
};