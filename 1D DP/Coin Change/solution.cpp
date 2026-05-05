class Solution {
public:
    int solve(vector<int> &coins, int target, vector<int> &dp){
        if(target == 0){
            return 0; // since target has become 0, we don't need any coin so number of coins requried is 0
        }

        if(dp[target] != -1){
            return dp[target];
        }
        
        int minCoins = INT_MAX;
        for(auto coin : coins){
            if(coin <= target){
                int res = solve(coins, target - coin, dp);
                if(res != INT_MAX){
                    minCoins = min(minCoins, 1 + res);
                }
                // Note : below condition was throughing error because of overflow case 
                // as solve(coins, target - coin, dp) can be INT_MAX and adding 1 to INT_MAX will overlfow 
                // minCoins = min(minCoins, 1 + solve(coins, target - coin, dp));
            }
        }

        return dp[target] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = solve(coins, amount, dp);
        return res != INT_MAX ? res : -1;
    }
};

// TC = O(amount × number_of_coins)


