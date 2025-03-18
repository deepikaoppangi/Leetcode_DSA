// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int>mpp;
//         for(int i=0;i<nums.size();i++){
//             mpp[nums[i]]++;
//             if(mpp[nums[i]]>1){
//                 return true;
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>sett;
        for(int i=0;i<nums.size();i++){
            if(sett.find(nums[i])!=sett.end()){
                return true;
            }
            else{
                sett.insert(nums[i]);
            }
        }
        return false;
    }
};