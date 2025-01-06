
////top down

// class Solution {
// public:
//     int fun(int i , int buy , vector<int> &prices , vector<vector<int>> &dp){
//         int n = prices.size();
//         if(i>=n){          //only change , bcz , if i=n-1 then i+2 = n+1, so i>=n
//             return 0;  //no profit
//         }
//         if(dp[i][buy]!=-1){
//             return dp[i][buy];
//         }
//         int profit = 0;
//         if(buy){
//             profit = max(-prices[i] + fun(i+1,0,prices,dp) , fun(i+1,1,prices,dp));
//         }
//         else{
//             profit = max(prices[i] + fun(i+2,1,prices,dp) , fun(i+1,0,prices,dp));
//         }
//         return dp[i][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return fun(0,1 ,prices , dp);
//     }
// };


//////bottom up 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    dp[i][buy] = max(-prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
                else{
                    dp[i][buy]=max(prices[i]+dp[i+2][0] , dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};