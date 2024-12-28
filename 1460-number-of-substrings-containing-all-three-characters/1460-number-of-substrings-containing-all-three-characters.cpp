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

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt=0;
        int hash[3]={-1,-1,-1};
        for(int i=0;i<n;i++){
            hash[s[i]-'a']=i;
            cnt = cnt + min(hash[0] , min(hash[1],hash[2]) ) + 1; 
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int l = 0;
//         int n = s.size();
//         int hash[3] = {0};
//         int typecnt = 0;
//         long long cnt = 0;

//         for(int r=0; r<n; r++){
//             if(hash[s[r]-'a'] == 0) typecnt++;
//             hash[s[r]-'a']++;

//             while(typecnt>2){
//                 hash[s[l]-'a']--;
//                 if(hash[s[l]-'a'] == 0) typecnt--;
//                 l++;
//             }

//             cnt += r-l+1;
//         }
//         return static_cast<long long>(n) * (n + 1) / 2 - cnt;
//     }
// };