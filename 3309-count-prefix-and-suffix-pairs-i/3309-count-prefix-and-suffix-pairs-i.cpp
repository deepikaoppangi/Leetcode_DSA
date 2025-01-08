class Solution {
public:
    bool fun(string s , string t){
        if(s.size()>t.size()){
            return false;
        }
        //s,t substring length = s.size() and s,t1 substring length = s.size() then return true;
        bool temp1 = true;
        for (int i = 0;i<s.size();i++) {
            if (s[i] != t[i]) {
                temp1 = false;
                break;
            }
        }
        bool temp2=true;
        for (int i = 0;i<s.size();i++) {
            if (s[i] != t[t.size()+i-s.size()]) {
                temp2 = false;
                break;
            }
        }
        if(temp1==true && temp2==true){
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int len=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if( fun(words[j],words[i]) ){
                    len++;
                }
            }
        }
        return len;
    }
};