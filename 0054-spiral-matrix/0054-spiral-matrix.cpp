class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        vector<int>result;
        int m = matrix.size();       //no.of rows
        int n = matrix[0].size();    //no.of columns
        int left  = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;
        while(left<=right && top<=bottom) {
            //here , no need to check , we are not modifying top/bottom
            for(int i = left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            //here , no need to check , we are not modifying right/left
            for(int i=top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){               //still have rows
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){           ///still have columns
                for(int i =bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;        
            }

        }
        return result;
    }
};