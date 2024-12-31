// ////////////////recursion , 26/70 
// class Solution {
// public:
//     int fun(int i,vector<int> &days , vector<int> &costs){
//         int n = days.size();
//         if(i>=n){
//             return 0;
//         }
//         int day1 = costs[0]+fun(i+1,days,costs);

//         int ind7=i;
//         while(ind7<=n-1 && days[ind7]-days[i]<=6){
//             ind7++;
//         }
//         int day7 = costs[1]+fun(ind7 ,days,costs);

//         int ind30=i;
//         while(ind30<=n-1 && days[ind30]-days[i]<=29){
//             ind30++;
//         }
//         int day30 = costs[2]+fun(ind30,days,costs);

//         return min({day1,day7,day30});
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         return fun(0,days , costs);
//     }
// };

///////////memoization
// class Solution {
// public:
//     int fun(int i,vector<int> &days , vector<int> &costs,vector<int> &dp){
//         int n = days.size();
//         if(i>=n){
//             return 0;
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int day1 = costs[0]+fun(i+1,days,costs,dp);

//         int ind7=i;
//         while(ind7<=n-1 && days[ind7]-days[i]<=6){
//             ind7++;
//         }
//         int day7 = costs[1]+fun(ind7 ,days,costs,dp);

//         int ind30=i;
//         while(ind30<=n-1 && days[ind30]-days[i]<=29){
//             ind30++;
//         }
//         int day30 = costs[2]+fun(ind30,days,costs,dp);

//         return dp[i]=min({day1,day7,day30});
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.size();
//         vector<int>dp(n,-1);
//         return fun(0,days , costs,dp);
//     }
// };

//////tabulation
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int day1 = costs[0]+dp[i+1];

            int ind7=i;
            while(ind7<=n-1 && days[ind7]-days[i]<=6){
                ind7++;
            }
            int day7 = costs[1]+dp[ind7];

            int ind30=i;
            while(ind30<=n-1 && days[ind30]-days[i]<=29){
                ind30++;
            }
            int day30 = costs[2]+dp[ind30];

            dp[i]=min({day1,day7,day30});
        }
        return dp[0];
    }
};