// class Solution {
// public:
//     vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//         int leftind=0;
//         int rightind=0;
//         int upind=0;
//         int downind=0;
//         set<vector<int>>uni;
//         for(int i=0;i<trees.size();i++){
//             if(trees[i][0]<trees[leftind][0]){
//                 leftind=i;
//             }
//             if(trees[i][0]>trees[rightind][0]){
//                 rightind=i;
//             }
//             if(trees[i][1]>trees[upind][1]){
//                 upind=i;
//             }
//             if(trees[i][1]<trees[downind][1]){
//                 downind=i;
//             }
//         }
//         uni.insert(trees[leftind]);
//         uni.insert(trees[rightind]);
//         uni.insert(trees[upind]);
//         uni.insert(trees[downind]);
//         for(int i=0;i<trees.size();i++){
//             if(i!=leftind && i!=rightind && i!=upind && i!=downind){
//                 if((trees[i][0]*(trees[leftind][1]-trees[upind][1]) + trees[i][1]*(trees[upind][0]-trees[leftind][0]) + trees[leftind][0]*trees[upind][1]-trees[upind][0]*trees[leftind][1]) >= 0 ){
//                     uni.insert(trees[i]);
//                     continue;
//                 }
//                 if((trees[i][0]*(trees[upind][1]-trees[rightind][1]) + trees[i][1]*(trees[rightind][0]-trees[upind][0]) + trees[upind][0]*trees[rightind][1]-trees[rightind][0]*trees[upind][1]) >= 0 ){
//                     uni.insert(trees[i]);
//                     continue;
//                 }
//                 if((trees[i][0]*(trees[rightind][1]-trees[downind][1]) + trees[i][1]*(trees[downind][0]-trees[rightind][0]) + trees[rightind][0]*trees[downind][1]-trees[downind][0]*trees[rightind][1]) >= 0 ){
//                     uni.insert(trees[i]);
//                     continue;
//                 }
//                 if((trees[i][0]*(trees[downind][1]-trees[leftind][1]) + trees[i][1]*(trees[leftind][0]-trees[downind][0]) + trees[downind][0]*trees[leftind][1]-trees[leftind][0]*trees[downind][1]) >= 0 ){
//                     uni.insert(trees[i]);
//                     continue;
//                 }
//             }
//         }
//         return vector<vector<int>>(uni.begin(), uni.end());
//     }
// };
class Solution {
public:
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 1) return trees;

        // Sort points by x, then by y
        sort(trees.begin(), trees.end());

        vector<vector<int>> hull;

        // Build the lower hull
        for (auto& p : trees) {
            while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), p) < 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }

        // Build the upper hull
        int lower_size = hull.size();
        for (int i = trees.size() - 2; i >= 0; i--) {
            while (hull.size() > lower_size && orientation(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        // Remove duplicates
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};
