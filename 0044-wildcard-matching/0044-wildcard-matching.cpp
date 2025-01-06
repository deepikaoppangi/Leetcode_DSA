// class Solution {
// public:
//     bool fun(int i,int j,string s , string p){
//         if(i<0 && j<0){
//             return true;
//         }
//         if (i<0) { 
//             while(j>= 0) {
//                 if(p[j]!='*') {
//                     return false;
//                 }
//                 j--;
//             }
//             return true;
//         }
//         if(j<0){
//             return false;
//         }
//         if(s[i]==p[j] || p[j]=='?') {
//             return fun(i-1,j-1,s,p);
//         }
//         if(p[j]=='*'){
//             return fun(i-1,j,s,p)|| fun(i,j-1,s,p);
//         }
//         return false;

//     }
//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         return fun(m-1,n-1,s,p);
//     }
// };


// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         vector<vector<bool>> dp(m+1,(vector<bool>(n+1,false)));
//         dp[0][0]=true;
//         for(int i=1;i<=m;i++){
//             dp[i][0]=false;
//         }
//         for(int j=1;j<=n;j++){
//             int flag=true;
//             for(int k =1;k<=j;k++){
//                 if(p[k-1]!='*'){
//                     flag=false;
//                     break;
//                 }
//             }
//             dp[0][j]=flag;
//         }
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 if(s[i-1]==p[j-1] || p[j-1]=='?') {
//                     dp[i][j]=dp[i-1][j-1];
//                 }
//                 else if(p[j-1]=='*'){
//                     dp[i][j]=dp[i-1][j] || dp[i][j-1];
//                 }
//                 else{
//                     dp[i][j]=false;
//                 }
//             }
//         }
//         return dp[m][n];

//     }
// };



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<bool>prev(n+1,false);
        vector<bool>curr(n+1,false);
        prev[0]=true;
        curr[0]=false;
        for(int j=1;j<=n;j++){
            int flag=true;
            for(int k =1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            prev[j]=flag;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') {
                    curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j]=prev[j] || curr[j-1];
                }
                else{
                    curr[j]=false;
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};