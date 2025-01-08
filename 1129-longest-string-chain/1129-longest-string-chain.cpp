// class Solution {
// public:
//     bool check(string &s1,string &s2){ 
//         if(s1.size() != s2.size()+1){       //s1>s2
//             return false;
//         }
//         int first=0;
//         int second=0;
//         while(first<s1.size()){
//             if(s1[first]==s2[second] && second<s2.size()){
//                 first++;
//                 second++;
//             }
//             else{
//                 first++;
//             }
//         }
//         if(first==s1.size() && second==s2.size()){
//             return true;
//         }
//         return false;

//     }
//     int longestStrChain(vector<string>& words) {
//         int n = words.size();
//         int maxi=1;


//         // Sort words by their lengths
//         sort(words.begin(), words.end(), [](string &a, string &b) {
//             return a.size() < b.size();
//         });


//         vector<int> dp(n, 1);
//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (check(words[i],words[j]) && dp[j]+1>dp[i]) {
//                     dp[i]=dp[j]+1;
//                 }
//             }
//             if(dp[i]>maxi){
//                 maxi = dp[i];
//             }
//         }
//         return maxi;
//     }
// };





















class Solution {
public:
    int subseqlen(string s,string t){
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=0;    //not required
        for(int i=1;i<=m;i++){
            dp[i][0]=0;      //not required
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi=1;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()-words[j].size()==1 && subseqlen(words[j],words[i])==words[j].size() && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};