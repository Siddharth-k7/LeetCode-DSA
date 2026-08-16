class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
   int cnt[3] = {0};

        // Count remainders 0, 1 and 2
        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If number of remainder-0 stones is EVEN:
        //
        // Alice can win if there is at least one
        // remainder-1 stone AND at least one
        // remainder-2 stone.
        //
        // Example:
        // [2,1]
        // cnt = [0,1,1]
        //
        // Alice takes 2
        // Bob is forced to take 1
        // 2 + 1 = 3
        // Bob loses.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If number of remainder-0 stones is ODD,
        // Alice wins only if the number of 1s and 2s
        // is sufficiently unbalanced.
        return abs(cnt[1] - cnt[2]) > 2;
    
    }
};