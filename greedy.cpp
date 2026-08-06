#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Greedy{
    public:
        int greedy_algo(vector<int> &coins, int total){
            int n = coins.size();
            sort(coins.begin(), coins.end());
            int tot_coin = 0;
            for(int i = n - 1 ; i >= 0; i--){
                if(coins[i] <= total){
                    int x = total / coins[i];
                    tot_coin += x;
                    total -= x * coins[i];
                }
                if(total == 0){
                    return tot_coin;
                }
            }
            return tot_coin;
        }
};
int main(){
    int total = 0;
    cout << "Enter the amount of change needed : ";
    cin >> total;
    vector<int> coins = {1, 2, 5, 10};
    Greedy coin;
    cout << "The minimum number of coins needed : "  << coin.greedy_algo(coins, total);
    cout << endl;
    return 0;
}