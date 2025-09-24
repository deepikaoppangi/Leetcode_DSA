// ///////////this only 54/59 cases passed
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0 ; i<n;i++){
//             for(int j =i+1 ;j<n;j++){
//                 if(nums[j]==nums[i] ){
//                     return nums[j];
//                 }
//             }
//         } 
//         return 0; 
//     }
// };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for (int num : nums) {
//             if (freq[num] > 0) {
//                 return num;   // already seen → duplicate
//             }
//             freq[num]++;  // mark as seen
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int> seen;
//         for (int num : nums) {
//             if (seen.count(num)) {
//                 return num;   // already in set → duplicate
//             }
//             seen.insert(num);
//         }
//         return -1;  // should never happen
//     }
// };



// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin() ,nums.end());
//         for(int i = 0;i<n-1;i++){
//             if(nums[i]==nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Phase 1: Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entrance of cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
