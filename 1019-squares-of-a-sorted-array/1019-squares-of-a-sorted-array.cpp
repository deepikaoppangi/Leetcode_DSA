class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>sortednums=nums;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sortednums[i]=sortednums[i]*sortednums[i];
        }
        sort(sortednums.begin(),sortednums.end());
        return sortednums;
    }
};