class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        map<char,int>mpp;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            cnt++;
        }
        for(int i=0;i<t.size();i++){
            if(mpp[t[i]]!=0){
                mpp[t[i]]--;
                cnt--;
            }    
        }
        if(cnt==0){
            return true;
        }
        return false;
    }
};