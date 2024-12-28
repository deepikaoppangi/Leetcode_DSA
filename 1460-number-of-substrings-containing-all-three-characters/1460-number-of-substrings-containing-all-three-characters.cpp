// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt=0;
//         map<char,int>mpp;
//         for(int i=0;i<n;i++){
//             if(mpp.find(char)==mpp.end()){
//                 mpp[char]=i;
//             }
//             else if(mpp.find(char)!=mpp.end()){
//                 mpp.erase(char);
//                 mpp[char]=i;
//             }
//             if(mpp.size()>=3){
//                 cnt++;
//             }
//         }
//     }
// };


//brute force // 46/54 
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt=0;
//         map<char,int>mpp;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(mpp.find(s[j])==mpp.end()){
//                     mpp[s[j]]++;
//                 }
//                 if(mpp.size()==3){
//                     cnt++;
//                 }
//             }
//             mpp.clear();
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt=0;
//         int hash[3]={-1,-1,-1};
//         for(int i=0;i<n;i++){
//             hash[s[i]-'a']=i;
//             cnt = cnt + min(hash[0] , min(hash[1],hash[2]) ) + 1; 
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0;
        int n = s.size();
        int hash[3] = {0};
        int k = 0;
        long long cnt = 0;
//we need k = 3 types , so (k<=3 types) - (k<=2 types) => k=3 types.
//here k<=3 types means , everytime we will have <=3 times only  = total= n*(n+1)/2
        for(int end=0;end<n;end++){
            if(hash[s[end]-'a'] == 0){
                k++;
            }
            hash[s[end]-'a']++;
            while(k>2){
                hash[s[start]-'a']--;
                if(hash[s[start]-'a'] == 0){
                    k--;
                }
                start++;
            }

            cnt = cnt+ (end-start+1);
        }
        return (long long)(n)*(n + 1) / 2 - cnt;
    }
};