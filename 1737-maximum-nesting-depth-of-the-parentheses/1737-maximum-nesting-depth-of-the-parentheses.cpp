class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        if(n==1){
            return 0;
        }
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};