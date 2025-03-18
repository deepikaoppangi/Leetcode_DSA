// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>res(n,0);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i!=j && nums[i]>nums[j]){
//                     res[i]++;
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        vector<int>sortednums=nums;
        unordered_map<int,int>mpp;
        sort(sortednums.begin(),sortednums.end());
        for(int i=0;i<n;i++){
            if(mpp.find(sortednums[i])==mpp.end()){
                mpp[sortednums[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            res[i]=mpp[nums[i]];
        }
        return res;
    }
};