
///////this is brute force 
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs.size();
//         int ans=strs[0].size();
//         for(int i=0;i<n;i++){
//             for(int j = i+1;j<n;j++){
//                 int start=0;
//                 int mini = min(strs[i].size(),strs[j].size());
//                 while(start<mini){
//                     if(strs[i][start]!=strs[j][start]){
//                         break;
//                     }
//                     start++;
//                 }
//                 ans =min(ans,start);
//             }
//         }
//         return strs[0].substr(0,ans);
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string result="";
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i]!=strs[n-1][i]){
                break;
            }
            result=result+strs[0][i];
        }
        return result;
    }
};