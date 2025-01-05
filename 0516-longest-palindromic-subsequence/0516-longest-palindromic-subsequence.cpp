//top down // memory limit exceeded

// class Solution {
// public:
//     int fun(int i ,int j,string s,vector<vector<int>> &dp){
//         if(i>j){
//             return 0;
//         }
//         if(i==j){
//             return 1;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s[i]==s[j]){
//             return dp[i][j]=2+fun(i+1,j-1,s,dp);
//         }
//         return dp[i][j]=max(fun(i+1,j,s,dp),fun(i,j-1,s,dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         int m = s.size();
//         vector<vector<int>> dp(m,(vector<int>(m,-1)));
//         return fun(0,m-1,s,dp);
//     }
// };


///////////////////just reverse the string , and find longest common subsequence
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int m = s.size();
//         string s2 = s;
//         reverse(s2.begin(),s2.end());
//         vector<vector<int>> dp(m+1,vector<int>(m+1,0));
//         for(int i=0;i<=m;i++){
//             dp[i][0]=0;
//         }
//         for(int i=0;i<=m;i++){
//             dp[0][i]=0;
//         }
//         for(int i=1;i<=m;i++){          //changed index
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==s2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[m][m]; 
//     }
// };


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=1;i<=m;i++){          //changed index
            for(int j=1;j<=m;j++){
                if(s[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m]; 
    }
};