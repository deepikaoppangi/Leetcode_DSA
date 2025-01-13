class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(n==1 || n==2){
            return n;
        }
        map<char,int>mpp;
        int cnt=0;
        for(int i=0;i<=n-1;i++){
            mpp[s[i]]++;
            if(mpp[s[i]]==3){
                mpp[s[i]]=mpp[s[i]]-2;
                cnt=cnt+2;
            }   
        }
        return n-cnt;
    }
};
