//////////////////////time limit exceeded 42/45 //////////this complete que by my own


// class Solution {
// public:
//     int fun(int i , int j , vector<vector<int>> &triangle){
//         int n = triangle.size();
//         if(i==n-1){
//             return triangle[i][j];
//         }
//         return triangle[i][j]+min(fun(i+1,j,triangle),fun(i+1,j+1,triangle));
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return fun(0,0,triangle);
//     }
// };

/////////////////top down

// class Solution {
// public:
//     int fun(int i , int j , vector<vector<int>> &triangle,vector<vector<int>> &dp){
//         int n = triangle.size();
//         if(i==n-1){
//             dp[i][j]=triangle[i][j];
//             return dp[i][j];
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         dp[i][j]=triangle[i][j]+min(fun(i+1,j,triangle,dp),fun(i+1,j+1,triangle,dp));
//         return dp[i][j];
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>>dp(n,vector<int>(triangle[n-1].size(),-1));
//         return fun(0,0,triangle,dp);
//     }
// };


///////////////bottom up         ////////////////very good idea 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            dp[i][0]=triangle[i][0]+dp[i-1][0];
        }
        for(int i = 1 ;i<n;i++){
            for(int j = 1;j<triangle[i].size();j++){
                if(i==j){
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                    break;
                } 
                else{
                    dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        int mini= INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini , dp[n-1][i]);
        }
        return mini;
    }
};

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         dp[0][0]=triangle[0][0];
//         for(int i = 1 ;i<n;i++){
//             for(int j = 0;j<triangle[i].size();j++){
//                 if(j==0){
//                     dp[i][j]=triangle[i][j]+dp[i-1][j];
//                 }
//                 else if(j==triangle[i].size()-1){
//                     dp[i][j]=triangle[i][j]+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
//                 } 
//             }
//         }
//         int mini= INT_MAX;
//         for(int i=0;i<n;i++){
//             mini = min(mini , dp[n-1][i]);
//         }
//         return mini;
//     }
// };