#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(4);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    int m = min({(int)g[1].size(), (int)g[2].size(), (int)g[3].size()});
    cout << m << "\n";
    for (int j = 0; j < m; j++) {
        cout << g[1][j] << " " << g[2][j] << " " << g[3][j] << "\n";
    }
    return 0;
}