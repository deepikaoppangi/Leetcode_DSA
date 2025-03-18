class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sec=0;
        if(points.size()==1){
            return 0;
        }
        for(int i=0;i<=points.size()-2;i++){
            sec=sec+max(abs(points[i+1][1]-points[i][1]),abs(points[i+1][0]-points[i][0]));
        }
        return sec;
    }
};