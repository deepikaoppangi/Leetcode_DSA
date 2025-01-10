class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxFreq;
        for (const string& word : words2) {
            unordered_map<char, int> wordFreq;
            for (char ch : word) {
                wordFreq[ch]++;
            }
            for (const auto& pair : wordFreq) {
                maxFreq[pair.first] = max(maxFreq[pair.first], pair.second);
            }
        }
        vector<string> result;
        for (const string& word : words1) {
            unordered_map<char, int> wordFreq;
            for (char ch : word) {
                wordFreq[ch]++;
            } 
            bool isUniversal = true;
            for (const auto& pair : maxFreq) {
                if (wordFreq[pair.first] < pair.second) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }
        return result;
    }
};
