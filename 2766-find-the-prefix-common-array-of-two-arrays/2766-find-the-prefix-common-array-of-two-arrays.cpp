// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();
//         vector<int>ans(n,0);
//         if(A[0]==B[0]){
//             ans[0]=1;
//         }
//         int i=1;
//         while(i<n){
//             if(A[i]==B[i]){
//                 ans[i]=1+ans[i-1];
//             }
//             else{
//                 for(int k=0;k<=i;k++){
//                     for(int j=0;j<=i;j++){
//                         if(A[k]==B[j]){
//                             ans[i]=1+ans[i];
//                             break;
//                         }
//                     }
//                 }
//             }
//             i++;
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();
//         vector<int> ans(n, 0);
//         unordered_set<int> setA;
//         unordered_set<int> setB;

//         for (int i = 0; i < n; ++i) {
//             setA.insert(A[i]);
//             setB.insert(B[i]);
//             int cnt = 0;
//             for (auto it = setA.begin(); it != setA.end(); ++it) {
//                 if (setB.count(*it)) {
//                     cnt++;
//                 }
//             }
//             ans[i] = cnt;
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
        vector<int> freq(n + 1, 0); 
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[A[i]] == 1) {
                ++cnt; 
            }
            freq[A[i]] += 1;
            if (freq[B[i]] == 1) {
                ++cnt;
            }
            freq[B[i]] += 1;
            result[i] = cnt; 
        }
        return result;
    }
};

