class Solution {
public:
        int helper(vector<int>& nums,vector<int>& dp,int i,int n){
           if (i > n)
            return 0;

        if (i == n)
            return nums[i];

            if(dp[i]!= -1){return dp[i];}
            dp[i]=max(nums[i]+helper(nums,dp,i+2,n),helper(nums,dp,i+1,n));
            return dp[i];
        }


    int rob(vector<int>& nums) {
        int n=nums.size(); if(n==1){return nums[0];}
        vector<int> dp(n+1,-1);

            vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        
        int ans=max(helper(nums,dp1,0,n-2),helper(nums,dp2,1,n-1));
        return ans;


    }
};