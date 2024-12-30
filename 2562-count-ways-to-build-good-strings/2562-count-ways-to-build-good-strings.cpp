
//Time Limit Exceeded 14 / 36 testcases passed 
//recursion
// class Solution {
// public:
//     int fun(int len , int low,int high , int zero, int one ){
//         if(len>high){
//             return 0;
//         }
//         if(len>=low && len<=high){
//             return 1+fun(len+zero,low,high,zero,one)+fun(len+one,low,high,zero,one);
//         }
//         return fun(len+zero,low,high,zero,one)+fun(len+one,low,high,zero,one);
//     }
//     int countGoodStrings(int low, int high, int zero, int one) {
//         return fun(0,low,high,zero,one);
//     }
// };

//top down //memoization //own
class Solution {
public:
    long long fun(int len , int low,int high , int zero, int one , vector<long long> &dp){
        if(len>high){
            return 0;
        }
        if(dp[len]!=-1){
            return dp[len];
        }
        dp[len]=(fun(len+zero,low,high,zero,one,dp)%1000000007+fun(len+one,low,high,zero,one,dp)%1000000007)%1000000007;
        if(len>=low && len<=high){
            return dp[len]=(1+dp[len])%1000000007;
        }
        return dp[len];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1,-1);
        return fun(0,low,high,zero,one,dp)%1000000007;
    }
};