class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n,0);
        if(A[0]==B[0]){
            ans[0]=1;
        }
        int i=1;
        while(i<n){
            if(A[i]==B[i]){
                ans[i]=1+ans[i-1];
            }
            else{
                for(int k=0;k<=i;k++){
                    for(int j=0;j<=i;j++){
                        if(A[k]==B[j]){
                            ans[i]=1+ans[i];
                            break;
                        }
                    }
                }
            }
            i++;
        }
        return ans;
    }
};