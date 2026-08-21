class Solution {
public:
        int helper(vector<int>& cost,int i,vector<int>& dp){
         if(i==0 || i==1){return cost[i];}
         if(dp[i]!=-1){return dp[i];}


          int c1=helper(cost,i-1,dp);
          int c2=helper(cost,i-2,dp);

            dp[i]=cost[i]+min(c1,c2);           
          
            return dp[i];          
        }    
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
     vector<int> dp(n+1,-1); 
        int ans=min(helper(cost,n-1,dp),helper(cost,n-2,dp));
        return ans;          
        
    }
};