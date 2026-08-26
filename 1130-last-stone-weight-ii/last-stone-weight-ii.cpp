class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // |x-y|
        int sum=0;
        for(int x: stones){
            sum=sum+x;
        }
        int target = sum/2;
        // dp[j] = whether we can make sum j
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : stones) {
            // Go backwards because each stone can be used only once
            for (int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }

    // to Finddd the largest achievable sum <= target
        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }

        return 0;

        
    }
};