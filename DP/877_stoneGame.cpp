class Solution {
public:
int solve(vector<int> &p,  vector<vector<int>> &dp,int l, int r){
        if( l == r) return p[l];

        if(dp[l][r] != -1) return dp[l][r];

        int leftPick = p[l] - solve(p, dp, l+1, r);
        int rightPick = p[r] - solve(p, dp, l, r-1);

        return dp[l][r] = max(leftPick, rightPick);
    }
    bool stoneGame(vector<int>& piles) {
         int s1=0,s2=0;
        int n = piles.size();
        int l=0,r=n - 1;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int res = solve(piles, dp, l,r);
        return res >= 0;
    }
};