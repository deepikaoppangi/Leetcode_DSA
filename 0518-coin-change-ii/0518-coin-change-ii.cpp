// class Solution {
// public:
//     int fun(int i , int target ,vector<int>& coins ){
//         if(i==0){
//             if(target%coins[0]==0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(target==0){
//             return 1;
//         }
//         if(target<0){
//             return 0;
//         }
//         int nonpick = fun(i-1,target,coins);
//         int pick =0;
//         if(target>=coins[i]){
//             pick = fun(i,target-coins[i],coins);
//         }
//         return pick+nonpick;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return fun(n-1,amount,coins);
//     }
// };

//top down
class Solution {
public:
    int fun(int i , int target ,vector<int>& coins ,vector<vector<int>> &dp){
        if(i==0){
            if(target%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(target==0){
            return 1;
        }
        // if(target<0){
        //     return 0;
        // }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int nonpick = fun(i-1,target,coins,dp);
        int pick =0;
        if(target>=coins[i]){
            pick = fun(i,target-coins[i],coins,dp);
        }
        return dp[i][target]=pick+nonpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return fun(n-1,amount,coins,dp);
    }
};


// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int> (amount+1,0));
//         for(int target=0;target<=amount;target++){
//             if(target%coins[0]==0){
//                 dp[0][target]=1;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             dp[i][0] = 1;
//         }
//         for(int i=1;i<n;i++){
//             for(int target=1;target<=amount;target++){
//                 long nonpick = dp[i-1][target];
//                 long pick =0;
//                 if(target>=coins[i]){
//                     pick = dp[i][target-coins[i]];
//                 }
//                 dp[i][target]=(int)(pick+nonpick);
//             }
//         }
//         return dp[n-1][amount];
//     }
// };


