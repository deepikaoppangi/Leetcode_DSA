class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0 ;
        int maxlen = 0;
        int n  = fruits.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[fruits[i]]++;
            if(mpp.size()>2){
                mpp[fruits[start]]--;
                if(mpp[fruits[start]]==0){
                    mpp.erase(fruits[start]);
                }
                start++;
            }
            if(mpp.size()<=2){
                maxlen = max(maxlen , i - start+1);
            }
        }
        return maxlen;
    }
};