// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int>res;
//         unordered_set<int>sett;
//         for(int i=0;i<nums.size();i++){
//             sett.insert(nums[i]);
//         }
//         for(int i=1;i<=nums.size();i++){
//             if(sett.find(i)==sett.end()){
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        // Mark visited numbers
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  // Convert number to index (1-based to 0-based)
            if (nums[index] > 0) {
                nums[index] = -nums[index];  // Mark as visited
            }
        }
        
        // Find missing numbers
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);  // Convert index to missing number
            }
        }
        
        return result;
    }
};
