//////////top down  //satisified
// class Solution {
// public:
//     int fun(int i , int buy ,int cap , vector<int> &prices , vector<vector<vector<int>>> &dp){
//         int n = prices.size();
//         if(i==n || cap==0){
//             return 0;
//         }
//         if(dp[i][buy][cap]!=-1){
//             return dp[i][buy][cap];
//         }
//         int profit = 0;
//         if(buy==0){
//             profit = max(-prices[i] + fun(i+1,1,cap,prices,dp) , fun(i+1,0,cap,prices,dp));
//         }
//         else{
//             profit = max(prices[i] + fun(i+1,0,cap-1,prices,dp) , fun(i+1,1,cap,prices,dp));
//         }
//         return dp[i][buy][cap] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2 , vector<int>(3,-1)));
//         return fun(0,0 ,2,prices , dp);
//     }
// };

///////////////bottom up 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2 , vector<int>(3,0)));
//         //cap=0//no need to write bcz , already zeros
//         // for(int i=0;i<=n-1;i++){
//         //     for(int buy=0;buy<=1;buy++){
//         //         dp[i][buy][0]=0;
//         //     }
//         // }
//         //i==n//no need to write bcz , already zeros
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int cap=1;cap<=2;cap++){   //cap=0 , runtime error 
//                     if(buy==0){
//                         dp[i][buy][cap] = max(-prices[i]+dp[i+1][1][cap] , dp[i+1][0][cap]);
//                     }
//                     else{
//                         dp[i][buy][cap]=max(prices[i]+dp[i+1][0][cap-1] , dp[i+1][1][cap]);
//                     }
//                 }
//             }
//         }
//         return dp[0][0][2];
//     }
// };



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2 , vector<int>(3,0));
        vector<vector<int>> curr(2 , vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){ 
                    if(buy==0){
                        curr[buy][cap] = max(-prices[i]+after[1][cap] , after[0][cap]);
                    }
                    else{
                        curr[buy][cap]=max(prices[i]+after[0][cap-1] , after[1][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[0][2];
    }
};