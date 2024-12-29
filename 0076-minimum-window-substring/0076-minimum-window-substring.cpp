class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int start =0;
        int minlen = INT_MAX;
        int cnt=0;
        int sindex=-1;
        for(int end=0;end<s.size();end++){
            if(hash[s[end]]>0){
                cnt++;
            }
            hash[s[end]]--;
            while(cnt==t.size()){
                if(end-start+1<minlen){
                    minlen=end-start+1;
                    sindex=start;
                }
                hash[s[start]]++;
                if(hash[s[start]]>0){
                    cnt--;
                }
                start++;
            }
        }
        if(sindex==-1){
            return "";
        }
        return s.substr(sindex,minlen);
    }
};