class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto &[_,count] : mpp){
                    maxi=max(maxi,count);
                    mini=min(mini,count);
                }
                sum=sum+(maxi-mini);
            }
        }
        return sum;
    }
};