#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Dynamic Programming Cheat Sheet in C++
//
// 1. When to think DP
// - Overlapping subproblems
// - Optimal substructure
// - Questions asking for max/min/count/ways/feasibility
//
// 2. Core recipe
// - Define the state
// - Write the transition
// - Set base cases
// - Choose memoization or tabulation
// - Check complexity
//
// 3. Memoization vs tabulation
// - Memoization: top-down recursion + cache
// - Tabulation: bottom-up iteration
//
// 4. State design patterns
// - dp[i]   : answer for prefix up to i
// - dp[i][j]: answer for two parameters, like index and capacity
// - dp[l][r]: interval or substring DP
// - dp[mask]: subset DP
//
// 5. Transition patterns
// - take / skip
// - min / max over previous states
// - sum of all valid previous states
// - diagonal / top / left moves in grids or strings
//
// 6. Common pitfalls
// - Wrong state definition
// - Missing base cases
// - Wrong iteration order
// - Off-by-one errors
// - Overwriting values needed later
//
// 7. Complexity rule
// - Time = number of states x transitions per state
// - Space = number of stored states

int fibonacci_memo(int n, vector<int>& dp) {
	if (n <= 1) {
		return n;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	return dp[n] = fibonacci_memo(n - 1, dp) + fibonacci_memo(n - 2, dp);
}

int climb_stairs(int n) {
	if (n <= 1) {
		return 1;
	}

	int prev2 = 1;
	int prev1 = 1;

	for (int step = 2; step <= n; ++step) {
		int current = prev1 + prev2;
		prev2 = prev1;
		prev1 = current;
	}

	return prev1;
}

int knapsack_01(const vector<int>& weights, const vector<int>& values, int capacity) {
	int item_count = static_cast<int>(weights.size());
	vector<vector<int>> dp(item_count + 1, vector<int>(capacity + 1, 0));

	for (int item = 1; item <= item_count; ++item) {
		for (int current_capacity = 0; current_capacity <= capacity; ++current_capacity) {
			dp[item][current_capacity] = dp[item - 1][current_capacity];

			if (weights[item - 1] <= current_capacity) {
				dp[item][current_capacity] = max(
					dp[item][current_capacity],
					values[item - 1] + dp[item - 1][current_capacity - weights[item - 1]]);
			}
		}
	}

	return dp[item_count][capacity];
}

int coin_change_ways(const vector<int>& coins, int sum) {
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;

	for (int coin : coins) {
		for (int current_sum = coin; current_sum <= sum; ++current_sum) {
			dp[current_sum] += dp[current_sum - coin];
		}
	}

	return dp[sum];
}

int lcs_length(const string& first, const string& second) {
	int n = static_cast<int>(first.size());
	int m = static_cast<int>(second.size());
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (first[i - 1] == second[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}

int unique_paths(int rows, int cols) {
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	dp[0][0] = 1;

	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			if (row > 0) {
				dp[row][col] += dp[row - 1][col];
			}
			if (col > 0) {
				dp[row][col] += dp[row][col - 1];
			}
		}
	}

	return dp[rows - 1][cols - 1];
}

int main() {
	cout << "========== DYNAMIC PROGRAMMING EXAMPLES ==========" << endl << endl;

	int fibonacci_target = 10;
	vector<int> fibonacci_dp(fibonacci_target + 1, -1);
	cout << "Fibonacci memoization for n = " << fibonacci_target << ": "
		 << fibonacci_memo(fibonacci_target, fibonacci_dp) << endl;

	int stair_count = 5;
	cout << "Climbing stairs for n = " << stair_count << ": "
		 << climb_stairs(stair_count) << endl;

	vector<int> weights{1, 3, 4, 5};
	vector<int> values{1, 4, 5, 7};
	int capacity = 7;
	cout << "0/1 knapsack best value for capacity " << capacity << ": "
		 << knapsack_01(weights, values, capacity) << endl;

	vector<int> coins{1, 2, 5};
	int target_sum = 5;
	cout << "Coin change ways for sum " << target_sum << ": "
		 << coin_change_ways(coins, target_sum) << endl;

	string first = "abcde";
	string second = "ace";
	cout << "LCS length between \"" << first << "\" and \"" << second << "\": "
		 << lcs_length(first, second) << endl;

	int rows = 3;
	int cols = 3;
	cout << "Unique paths in a " << rows << "x" << cols << " grid: "
		 << unique_paths(rows, cols) << endl << endl;

	cout << "HOW TO SOLVE ANY DP PROBLEM" << endl;
	cout << "- Identify what must be remembered" << endl;
	cout << "- Define the state in one sentence" << endl;
	cout << "- Derive the recurrence from choices" << endl;
	cout << "- Write base cases" << endl;
	cout << "- Decide the loop order" << endl;
	cout << "- Test on small examples" << endl;
	cout << "- Optimize memory only after correctness" << endl;

	return 0;
}
