
// //////////top down
// class Solution {
// public:
//     int fun(int i , int buy , vector<int> &prices , vector<vector<int>> &dp){
//         int n = prices.size();
//         if(i==n){
//             return 0;  //no profit
//         }
//         if(dp[i][buy]!=-1){
//             return dp[i][buy];
//         }
//         int profit = 0;
//         if(buy==0){
//             profit = max(-prices[i] + fun(i+1,1,prices,dp) , fun(i+1,0,prices,dp));
//         }
//         else{
//             profit = max(prices[i] + fun(i+1,0,prices,dp) , fun(i+1,1,prices,dp));
//         }
//         return dp[i][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return fun(0,0,prices , dp);
//     }
// };

// ///bottom up
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1] =0; 
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy==0){
                    profit = max(-prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][0] , dp[i+1][1]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};

/////////////space optimized

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int>ahead(2,0);
//         vector<int>curr(2,0);
//         ahead[0]=ahead[1] =0;
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 int profit = 0;
//                 if(buy){
//                     profit = max(-prices[i]+ahead[0] , ahead[1]);
//                 }
//                 else{
//                     profit=max(prices[i]+ahead[1] , ahead[0]);
//                 }
//                 curr[buy]=profit;
//             }
//             ahead = curr;
//         }
//         return ahead[1];
//     }
// };