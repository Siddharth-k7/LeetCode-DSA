class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
         unordered_map<int, int> mp;

        for (auto &v : reservedSeats){
            mp[v[0]] |= (1 << (v[1] - 1));
    }
        int ans = 2 * (n - mp.size());

        int l = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        int m = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
        int r = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);

        for (auto &[row, x] : mp) {
            if ((x & l) == 0 && (x & r) == 0)
                ans += 2;
         else if ((x & l) == 0 || (x & m) == 0 || (x & r) == 0)
                ans += 1;
        }
        return ans;
    }
};