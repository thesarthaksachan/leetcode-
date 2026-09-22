class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    ll solve(int t, int n, int k, vector<vector<ll>>& dp)
    {
        if(n == 0 && t == 0) return 1;
        if(((n == 0) && t != 0) || (n < 0)) return 0;
        if(dp[t][n] != -1) return dp[t][n];

        ll count = 0;
        for(int i = 1; i <= min(k, t); i++)
        {
            count = (count + solve(t - i, n - 1, k, dp)) % mod;
        }
        return dp[t][n] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> memo(target + 1, vector<ll>(n + 1, -1));
        return solve(target, n, k, memo);
    }
};