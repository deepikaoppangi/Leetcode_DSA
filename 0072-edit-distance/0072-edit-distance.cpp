// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m  = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m+1,(vector<int>(n+1,0)));
//         for(int i=0;i<=m;i++){
//             dp[i][0]=i;         //j==0
//         }
//         for(int j=0;j<=n;j++){
//             dp[0][j]=j;      //i==0
//         }
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 if(word1[i-1]==word2[j-1]){
//                     dp[i][j]=dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=min( min(1+dp[i][j-1], 1+dp[i-1][j]) , 1+dp[i-1][j-1]); //insert , delete , replace
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m  = word1.size();
        int n = word2.size();
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i]=i;
        }
        for(int i=1;i<=m;i++){
            curr[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else{
                    curr[j]=min( min(1+curr[j-1], 1+prev[j]) , 1+prev[j-1]); //insert , delete , replace
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};