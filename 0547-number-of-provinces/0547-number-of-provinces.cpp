

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