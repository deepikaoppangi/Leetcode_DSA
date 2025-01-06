///bottom up

// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2 , vector<int>(k+1,0)));
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int cap=1;cap<=k;cap++){   //cap=0 , runtime error 
//                     if(buy==0){
//                         dp[i][buy][cap] = max(-prices[i]+dp[i+1][1][cap] , dp[i+1][0][cap]);
//                     }
//                     else{
//                         dp[i][buy][cap]=max(prices[i]+dp[i+1][0][cap-1] , dp[i+1][1][cap]);
//                     }
//                 }
//             }
//         }
//         return dp[0][0][k];
//     }
// };

//space optimized 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2 , vector<int>(k+1,0));
        vector<vector<int>> after(2 , vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){ 
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
        return after[0][k];
    }
};