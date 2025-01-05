
//tabulation
// class Solution {
// public:
//     int minInsertions(string s) {
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
//         for(int i=1;i<=m;i++){ 
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==s2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return m-dp[m][m]; 
//     }
// };

//more space optimized 
class Solution {
public:
    int minInsertions(string s) {
        int m = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=1;i<=m;i++){ 
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
        return m-prev[m]; 
    }
};