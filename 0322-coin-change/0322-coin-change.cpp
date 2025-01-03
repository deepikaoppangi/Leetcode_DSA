// class Solution {
// public:
//     int fun(int i, int target, vector<int>& coins){
//         if(i==0){
//             if(target%coins[0]==0){
//                 return target/coins[0];
//             }
//             return INT_MAX;
//         }
//         int nonpick = fun(i-1, target, coins);
//         int pick = INT_MAX;
//         if(target >= coins[i]) {
//             pick = 1+fun(i, target - coins[i], coins); 
//         }
//         return min(pick, nonpick);

//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         int result = fun(n-1, amount, coins);
//         if(result==INT_MAX){
//             return -1;
//         }
//         return result;
//     }
// };

//top-down
// class Solution {
// public:
//     int fun(int i, int target, vector<int>& coins,vector<vector<int>> &dp){
//         if(target==0){
//             return 0;
//         }
//         if(i==0){
//             if(target%coins[0]==0){
//                 return target/coins[0];
//             }
//             return 1e9;
//         }
//         if(dp[i][target]!=-1){
//             return dp[i][target];
//         }
//         int nonpick = fun(i-1, target, coins,dp);
//         int pick = INT_MAX;
//         if(target >= coins[i]) {
//             pick = 1+fun(i, target - coins[i], coins,dp); 
//         }
//         return dp[i][target]=min(pick, nonpick);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         int result = fun(n-1, amount, coins,dp);
//         if(result>=1e9){
//             return -1;
//         }
//         return result;
//     }
// };



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[0][target]=target/coins[0];
            }
            else{
                dp[0][target]=1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=amount;target++){
                int nonpick = dp[i-1][target];
                int pick = INT_MAX;
                if(target>=coins[i]){
                    pick = 1+dp[i][target-coins[i]];
                }
                dp[i][target]=min(pick,nonpick);
            }
        }
        int result = dp[n-1][amount];
        if(result>=1e9){
            return -1;
        }
        return result;
    }
};