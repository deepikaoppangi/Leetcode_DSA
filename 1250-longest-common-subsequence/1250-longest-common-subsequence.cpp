// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();
//         int count=0;
//         int index=-1;
//         if(m<=n){
//             for(int i=0;i<m;i++){
//                 for(int j=i;j<n;j++){
//                     if(text2[j]==text1[i] && j!=index){
//                         count++;
//                         index = j;
//                         break;
//                     }
//                 }
//             }
//         }
//         else{
//             for(int j=0;j<n;j++){
//                 for(int i=j;i<m;i++){
//                     if(text2[j]==text1[i] && i!=index){
//                         count++;
//                         index =i;
//                         break;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };

///////////top down //time limit
// class Solution {
// public:
//     int fun(int i , int j , string text1,string text2 , vector<vector<int>> &dp){
//         if(i==0 || j==0){  //changed - to equal 
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(text1[i-1]==text2[j-1]){              //changed index
//             return dp[i][j]=1+fun(i-1,j-1,text1,text2,dp);
//         }
//         return dp[i][j]=max(fun(i-1,j,text1,text2,dp),fun(i,j-1,text1,text2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));   //changed length
//         return fun(m,n,text1,text2,dp);  //changed index
//     }
// };



// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));   //changed length
//         for(int i=0;i<=m;i++){
//             dp[i][0]=0;
//         }
//         for(int i=0;i<=n;i++){
//             dp[0][i]=0;
//         }
//         for(int i=1;i<=m;i++){          //changed index
//             for(int j=1;j<=n;j++){
//                 if(text1[i-1]==text2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[m][n]; 
//     }
// };



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n+1,0);   //changed length
        vector<int> curr(n+1,0);
        for(int i=1;i<=m;i++){          //changed index
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n]; 
    }
};