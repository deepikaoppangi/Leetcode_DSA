/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>qu;
        vector<int>arr;
        if(root==NULL){
            return arr;
        }
        qu.push(root);
        while(!qu.empty()){
            int maxi= INT_MIN;
            int len = qu.size();
            for(int i=0;i<len;i++){
                TreeNode* node = qu.front();
                qu.pop();
                maxi= max(maxi , node->val);
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }
            }
            arr.push_back(maxi);
        }
        return arr;
    }
};