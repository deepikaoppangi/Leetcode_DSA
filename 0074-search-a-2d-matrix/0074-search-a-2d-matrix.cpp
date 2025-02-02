// //did on my own

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size(); //rows
//         int m = matrix[0].size();  //cols
//         //if only one row , u have to check
//         if(n==1){
//             for(int j=0;j<m;j++){
//                 if(matrix[0][j]==target){
//                     return true;
//                 }
//             }
//             return false;
//         }
//         int index=-1;
//         //finding index
//         for(int i=0;i<n;i++){
//             if(target<matrix[i][0]){
//                 index = i-1;
//                 break;
//             }
//             else if(target==matrix[i][0]){
//                 index=i;
//                 break;
//             }
//         }
//         //still -1 is the index
//         if(index==-1){
//             //if it is last row , 23 30 40 50 , target = 30
//             for(int j=0;j<m;j++){
//                 if(matrix[n-1][j]==target){
//                     return true;
//                 }
//             }
//             //if u didn't find any??
//             return false;
//         }
//         //after finding row , find in cols of each row
//         for(int j=0;j<m;j++){
//             if(matrix[index][j]==target){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//did on my own

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //rows
        int n = matrix[0].size();  //cols
        if(target<matrix[0][0]){
            return false;
        }
        for(int i=0;i<=m-1;i++){
            if(target==matrix[i][0]){
                return true;
            }
            if(target<matrix[i][0]){
                for(int j=0;j<n;j++){
                    if(target==matrix[i-1][j]){
                        return true;
                    }
                }
            }
            if(i==m-1 && target>matrix[i][0]){
                for(int j=0;j<n;j++){
                    if(target==matrix[i][j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};