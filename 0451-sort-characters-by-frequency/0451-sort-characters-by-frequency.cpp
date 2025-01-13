class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        //1.
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        //2.
        vector<pair<char,int>> vec(mpp.begin(),mpp.end());
        //3.
        sort(vec.begin(),vec.end(),[](const pair<char,int>& a,const pair<char,int>& b){
            return a.second>b.second;
        });
        //4.
        string res="";
        for(int i = 0;i<vec.size();i++) {
            const auto& temp = vec[i];
            res.append(temp.second, temp.first);  //by temp.second times
        }
        return res;
    }
};