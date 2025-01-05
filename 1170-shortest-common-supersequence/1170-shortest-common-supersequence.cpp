class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n= str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string result="";  //not " ", there should be no space
        int i= m;
        int j=n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                result = str1[i-1]+result; ///adding to front ,remember.
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                result=str1[i-1]+result;
                i--;
            }
            else{
                result=str2[j-1]+result;
                j--;
            }
        }
        while(i>0){
            result=str1[i-1]+result;
            i--;
        }
        while(j>0){
            result=str2[j-1]+result;
            j--;
        }
        return result;

    }
};

