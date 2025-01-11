class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int n = s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(count>0){
                    result = result+s[i];
                }
                count++;
            }
            else{
                count--;
                if(count>0){
                    result=result+s[i];
                }
            }
        }
        return result;
    }
};