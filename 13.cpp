/*
Dynamic Programming Cheat Sheet in C++

1. When to think DP
- Overlapping subproblems
- Optimal substructure
- Questions asking for max/min/count/ways/feasibility

2. Core recipe
- Define the state
- Write the transition
- Set base cases
- Choose memoization or tabulation
- Check complexity

3. Memoization vs tabulation
- Memoization: top-down recursion + cache
- Tabulation: bottom-up iteration

4. State design patterns
- dp[i]   : answer for prefix up to i
- dp[i][j]: answer for two parameters, like index and capacity
- dp[l][r]: interval or substring DP
- dp[mask]: subset DP

5. Transition patterns
- take / skip
- min / max over previous states
- sum of all valid previous states
- diagonal / top / left moves in grids or strings

6. Common pitfalls
- Wrong state definition
- Missing base cases
- Wrong iteration order
- Off-by-one errors
- Overwriting values needed later

7. Complexity rule
- Time = number of states x transitions per state
- Space = number of stored states

-----------------------------------------------------------------
MEMOIZATION TEMPLATE
-----------------------------------------------------------------

// Example: Frog jump / Fibonacci style recurrence
/*
int solve(int i, vector<int>& dp) {
	if (i <= 1) return i;
	if (dp[i] != -1) return dp[i];
	return dp[i] = solve(i - 1, dp) + solve(i - 2, dp);
}
*/

-----------------------------------------------------------------
TABULATION TEMPLATE
-----------------------------------------------------------------

/*
vector<int> dp(n + 1, 0);
dp[0] = base_case;
for (int i = 1; i <= n; ++i) {
	dp[i] = transition_from_previous_states;
}
return dp[n];
*/

-----------------------------------------------------------------
1D DP EXAMPLE: CLIMBING STAIRS
-----------------------------------------------------------------

/*
int climbStairs(int n) {
	if (n <= 1) return 1;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
*/

-----------------------------------------------------------------
SPACE-OPTIMIZED 1D DP
-----------------------------------------------------------------

/*
int climbStairs(int n) {
	if (n <= 1) return 1;
	int prev2 = 1;
	int prev1 = 1;
	for (int i = 2; i <= n; ++i) {
		int cur = prev1 + prev2;
		prev2 = prev1;
		prev1 = cur;
	}
	return prev1;
}
*/

-----------------------------------------------------------------
0/1 KNAPSACK TEMPLATE
-----------------------------------------------------------------

/*
int knapsack(vector<int>& wt, vector<int>& val, int W) {
	int n = wt.size();
	vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int w = 0; w <= W; ++w) {
			dp[i][w] = dp[i - 1][w];
			if (wt[i - 1] <= w) {
				dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
			}
		}
	}
	return dp[n][W];
}
*/

-----------------------------------------------------------------
UNBOUNDED KNAPSACK / COIN CHANGE
-----------------------------------------------------------------

/*
int coinChangeWays(vector<int>& coins, int sum) {
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for (int coin : coins) {
		for (int s = coin; s <= sum; ++s) {
			dp[s] += dp[s - coin];
		}
	}
	return dp[sum];
}
*/

-----------------------------------------------------------------
LCS TEMPLATE
-----------------------------------------------------------------

/*
int lcs(string a, string b) {
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}
*/

-----------------------------------------------------------------
GRID PATH TEMPLATE
-----------------------------------------------------------------

/*
int uniquePaths(int n, int m) {
	vector<vector<int>> dp(n, vector<int>(m, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) dp[i][j] += dp[i - 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];
		}
	}
	return dp[n - 1][m - 1];
}
*/

-----------------------------------------------------------------
HOW TO SOLVE ANY DP PROBLEM
-----------------------------------------------------------------
- Identify what must be remembered
- Define the state in one sentence
- Derive the recurrence from choices
- Write base cases
- Decide the loop order
- Test on small examples
- Optimize memory only after correctness
*/

int main() {
	return 0;
}
