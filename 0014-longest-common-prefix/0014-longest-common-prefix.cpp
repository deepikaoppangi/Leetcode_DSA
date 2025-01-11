class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int ans=strs[0].size();
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int start=0;
                int mini = min(strs[i].size(),strs[j].size());
                while(start<mini){
                    if(strs[i][start]!=strs[j][start]){
                        break;
                    }
                    start++;
                }
                ans =min(ans,start);
            }
        }
        return strs[0].substr(0,ans);
    }
};