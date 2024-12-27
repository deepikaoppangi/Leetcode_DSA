//time limit exceeded , 49/55
// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int n = values.size();
//         int maxi = INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 maxi = max(maxi ,values[i]+values[j]+i-j);
//             }
//         }
//         return maxi;
//     }
// };

//optimal
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = INT_MIN;
        vector<int>arr(n-1);
        for(int i=0;i<n-1;i++){
            arr[i]=values[i+1]-(i+1);
        }
        int insmaxi=INT_MIN;
        for(int i=n-2;i>=0;i--){
            insmaxi=max(insmaxi,arr[i]);
            maxi=max(maxi,values[i]+i+insmaxi);
        }
        return maxi;
    }
};