class Solution {
public:
    int romanToInt(string s) {
        int i=0;
        int ans=0;
        while(i<s.size()){
            if(s[i]=='I' && s[i+1]=='V'){
                ans=ans+4;
                i=i+2;
            }
            else if(s[i]=='I' && s[i+1]=='X'){
                ans=ans+9;
                i=i+2;
            }
            else if(s[i]=='X' && s[i+1]=='L'){
                ans=ans+40;
                i=i+2;
            }
            else if(s[i]=='X' && s[i+1]=='C'){
                ans=ans+90;
                i=i+2;
            }
            else if(s[i]=='C' && s[i+1]=='D'){
                ans=ans+400;
                i=i+2;
            }
            else if(s[i]=='C' && s[i+1]=='M'){
                ans=ans+900;
                i=i+2;
            }
            else if(s[i]=='I'){
                ans=ans+1;
                i=i+1;
            }
            else if(s[i]=='V'){
                ans=ans+5;
                i=i+1;
            }
            else if(s[i]=='X'){
                ans=ans+10;
                i=i+1;
            }
            else if(s[i]=='L'){
                ans=ans+50;
                i=i+1;

            }
            else if(s[i]=='C'){
                ans=ans+100;
                i=i+1;
            }
            else if(s[i]=='D'){
                ans=ans+500;
                i=i+1;
            }
            else if(s[i]=='M'){
                ans=ans+1000;
                i=i+1;
            }
        }
        return ans;
    }
};