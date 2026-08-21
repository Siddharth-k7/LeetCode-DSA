class Solution {
public:
        long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto check = [&](long long x) {
            long long s = 0;
            for (int m = 1; m < (1 << n); m++) {
                long long l = 1;
                int b = 0;
                for (int i = 0; i < n; i++) {
                    if (m & (1 << i)) {
                        b++;
                        l = lcm(l, coins[i]);
               if (l > x)
                            break;
                    }
                }
                if (l > x)
                    continue;
                if (b % 2)
                    s += x / l;
                else
                    s -= x / l;
            }
            return s >= k;
        };
        long long l = 1;
        long long r = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (l < r) {
            long long m = l + (r - l) / 2;

            if (check(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
     }
};