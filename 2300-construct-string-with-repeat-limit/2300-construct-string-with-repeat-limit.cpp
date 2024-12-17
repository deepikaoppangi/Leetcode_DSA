class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        string result = "";
        while (!freq.empty()) {
            auto it = freq.begin(); 
            char currentChar = it->first;
            int count = it->second;
            int useCount = min(count, repeatLimit);
            result.append(useCount, currentChar);
            freq[currentChar] -= useCount; 
            if (freq[currentChar] == 0) {
                freq.erase(currentChar);
            }
            int tempcn= freq[currentChar];
            char temp = currentChar;
            freq.erase(currentChar);
            if (tempcn>0  && !freq.empty()) {
                auto nextIt = freq.begin();
                char nextChar = nextIt->first;
                result += nextChar;      
                freq[nextChar]--;
                freq[temp] = tempcn;
                if (freq[nextChar] == 0) {
                    freq.erase(nextChar);
                }
            } 
            else if (useCount == repeatLimit && freq.empty()) {
                break;
            }
        }
        return result;
    }
};