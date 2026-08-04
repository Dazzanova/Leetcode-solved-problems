class Solution {
public:
    long long minInitialStrength(vector<int>& m, vector<vector<int>>& boosts) {
        int n = m.size();
        vector<long long> diff(n + 1, 0);
        for (auto& v : boosts) {
            int i = v[0], j = v[1], k = v[2];
            diff[i] += k;
            diff[j + 1] -= k;
        }

        vector<long long> boost(n);
        long long run = 0;
        for (int x = 0; x < n; x++) {
            run += diff[x];
            boost[x] = run;
        }

        long long s = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s > 0) s = m[i] + s;
            else s = max(0LL, (long long)m[i] - boost[i]);
        }
        return s;
    }
};