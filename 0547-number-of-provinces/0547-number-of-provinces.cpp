// class Solution {
// public:
//     void traversal(int node , vector<vector<int>>& isConnected ,vector<int> &visited_array ){
//         visited_array[node]=1;
//         for(int i = 0;i<isConnected[node].size();i++){
//             if(isConnected[node][i]==1 && visited_array[i]==0)
//             traversal(i,isConnected,visited_array);
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         vector<int> visited_array(isConnected.size(),0);
//         int count=0;
//         for(int i = 0 ;i<isConnected.size();i++){
//             if(visited_array[i]==0){
//                 count++;
//                 traversal(i,isConnected,visited_array);
//             }
//         }
//         return count;
//     }
    
// };

class Solution {
public:

    void dfsfun(int node,vector<vector<int>> &isConnected,vector<int> &vis){
        int col=isConnected[0].size();
        vis[node]=1;
        for(int i=0;i<col;i++){
            if(isConnected[node][i]==1 && vis[i]==0){
                dfsfun(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int count=0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                dfsfun(i,isConnected,vis);
                count++;
            }
        }
        return count;
    }
    
};