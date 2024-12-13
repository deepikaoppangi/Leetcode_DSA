// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         //do with stack
//         //do with zeroes//recursion
//         //pointers
//         long long score = 0;
//         int n = nums.size();
//         int index=-1;
//         int cnt = 0;
//         while(cnt!=n){
//             int index=-1;
//             int mini = INT_MAX;
//             for(int i=0;i<n;i++){
//                 if(mini>nums[i] && nums[i]!=0){
//                     mini = nums[i];
//                     index = i;
//                 }
//             }
//             score = score+nums[index];
//             nums[index]=0;
//             cnt++;
//             if(index>0 && nums[index-1]!=0){
//                 nums[index-1]=0;
//                 cnt++;
//             }
//             if(index<n-1 && nums[index+1]!=0){
//                 nums[index+1]=0;
//                 cnt++;
//             }
//         }
//         return score;
//     }
// };


class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<bool> visited(n,false);
        //small on top
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minheap;
        for(int i=0;i<n;i++){
            minheap.push({nums[i],i});
        }
        while(!minheap.empty()){
            auto [value , index] = minheap.top();
            minheap.pop();
            if(visited[index]==true){
                continue;
            }
            score += value;

            //mark
            visited[index]=true;
            if(index>0){
                visited[index-1]=true;
            }
            if(index<n-1){
                visited[index+1]=true;
            }
        }
        return score;
    }
};


