class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int p = pref.size();
        int len=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(words[i].size()<p){
                    break;
                }
                if(pref[j]!=words[i][j]){
                    break;
                }
                len++;
                if(len==p){
                    ans++;
                }
            }
            len=0;
        }
        return ans;
    }
};