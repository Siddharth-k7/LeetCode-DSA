class Solution {
public:
    int stoneGameV(vector<int>& a) {
        
        int n=a.size();
        //ps[i] sum off first i elements 
        vector<int> ps(n+1,0);

        for(int i=0;i<n;i++){
            ps[i+1]=ps[i]+a[i];

        }
       vector<vector<int>> dp(n, vector<int>(n, 0));
                    for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len <= n; l++) {

                int r = l + len - 1;
                // Try every possible split
                for (int k = l; k < r; k++) {

                    // Sum of left part
                    int x = ps[k + 1] - ps[l];

                    // Sum of right part
                    int y = ps[r + 1] - ps[k + 1];
                      if (x < y) {

                        // Right side is thrown away.
                        // Alice keeps left side.
                        dp[l][r] = max(
                            dp[l][r],
                            x + dp[l][k]
                        );

                    }
                    else if (x > y) {

                        // Left side is thrown away.
                        // Alice keeps right side.
                        dp[l][r] = max(
                            dp[l][r],
                            y + dp[k + 1][r]
                        );

                    }
                      else {

                        // Both sides have equal sum.
                        // Alice chooses the better side.
                        dp[l][r] = max(
                            dp[l][r],
                            x + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};