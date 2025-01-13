class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int hash[256];
        int revhash[256];
        fill(hash, hash + 256, -1);
        fill(revhash, revhash + 256, -1);
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==-1){
                hash[s[i]]=t[i];
            }
            else if(hash[s[i]]!=t[i]){
                return false;
            }

            if(revhash[t[i]]==-1){
                revhash[t[i]]=s[i];
            }
            else if(revhash[t[i]]!=s[i]){
                return false;
            }
        }
        
        return true;
    }
};