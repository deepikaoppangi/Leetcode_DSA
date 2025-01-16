// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int bitxor= nums1[0]^nums2[0];
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(i==0 && j==0){
//                     continue;
//                 }
//                 bitxor=bitxor^(nums1[i]^nums2[j]);
//             }
//         }
//         return bitxor;
//     }
// };

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for (int i=0;i<nums1.size();i++) {
            xor1 = xor1^nums1[i];
        }
        for (int i=0;i<nums2.size();i++) {
            xor2 = xor2^nums2[i];
        }
        int result = 0;
        if (nums1.size() % 2 == 1) {
            result = result^xor2; 
        }
        if (nums2.size() % 2 == 1) {
            result = result^xor1; 
        }
        return result;
    }
};