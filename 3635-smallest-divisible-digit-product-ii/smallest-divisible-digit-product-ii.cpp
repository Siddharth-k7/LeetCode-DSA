class Solution {
public:

  typedef long long ll;
   string fill(ll req, int len) {
        string s;
        for (int d = 9; d >= 2; d--)
            while (req % d == 0) { s.push_back('0' + d); req /= d; }
        while ((int)s.size() < len) s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }

    string smallestNumber(string num, long long t) {
        ll tmp = t;
        for (ll p : {2, 3, 5, 7}) while (tmp % p == 0) tmp /= p;
        if (tmp != 1) return "-1";

        int n = num.size();

        // g[i] = factor of t still required after using num[0..i-1] verbatim
        vector<ll> g(n + 1);
        g[0] = t;
        int firstZero = -1;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if (d == 0) { if (firstZero < 0) firstZero = i; g[i + 1] = g[i]; }
            else g[i + 1] = g[i] / gcd(g[i], (ll)d);
        }

        // num itself works only if it has no zero and is already divisible
        if (firstZero < 0 && g[n] == 1) return num;

        // may only change a digit at index <= firstZero (any kept 0 stays illegal)
        int lim = (firstZero < 0 ? n - 1 : firstZero);
        for (int i = lim; i >= 0; i--) {
            ll req = g[i];
            int slots = n - 1 - i;
            for (int d = (num[i] - '0') + 1; d <= 9; d++) {   // strict: result > num
                ll req2 = req / gcd(req, (ll)d);
                string suf = fill(req2, slots);
                if ((int)suf.size() == slots)
                    return num.substr(0, i) + char('0' + d) + suf;
            }
        }

        // no same-length answer -> one more digit (also handles "t needs many digits")
        return fill(t, n + 1);
    }
};