class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int, int> mp;

        for (auto &seat : rs) {
            int row = seat[0];
            int col = seat[1];

            mp[row] = mp[row] | (1 << col);
        }

        int ans = 2 * (n - mp.size());

        int l  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int m = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int r  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : mp) {

            bool left   = (mask & l) == 0;
            bool middle = (mask & m) == 0;
            bool right  = (mask & r) == 0;

            if (left && right)  ans += 2;

            else if (left || middle || right)  ans += 1;
        }
        return ans;
    }
};
