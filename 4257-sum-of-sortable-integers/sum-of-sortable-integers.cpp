class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = INT_MIN;

            for (int i = 0; i < n && ok; i += k) {
                int cnt = 0;
                int mn = INT_MAX, mx = INT_MIN;

                for (int j = 0; j < k; j++) {
                    int a = nums[i + j];
                    int b = nums[i + (j + 1) % k];
                    if (a > b) cnt++;
                    mn = min(mn, a);
                    mx = max(mx, a);
                }

                // more than one cyclic descent -> no rotation sorts this block
                if (cnt > 1) { ok = false; break; }

                // previous block's largest must fit before this block's smallest
                if (prevMax > mn) { ok = false; break; }

                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};