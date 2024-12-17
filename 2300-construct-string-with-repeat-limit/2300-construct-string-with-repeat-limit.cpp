class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<pair<char, int>> pq;
        for (char ch = 'z'; ch >= 'a'; ch--) {
            if (freq[ch - 'a'] > 0) {
                pq.push({ch, freq[ch - 'a']});
            }
        }
        string result;
        while (!pq.empty()) {
            char currentChar = pq.top().first;
            int currentCount = pq.top().second;
            pq.pop();
            if (result.empty() || result.back() != currentChar) {
                int addCount = min(currentCount, repeatLimit);
                result.append(addCount, currentChar);
                currentCount -= addCount;
                if (currentCount > 0) {
                    pq.push({currentChar, currentCount});
                }
            } 
            else if (!pq.empty()) {
                char nextChar = pq.top().first;
                int nextCount = pq.top().second;
                pq.pop();
                result += nextChar;
                nextCount--;
                if (nextCount > 0) {
                    pq.push({nextChar, nextCount});
                }
                if (currentCount > 0) {
                    pq.push({currentChar, currentCount});
                }
            }
            else {
                break;
            }
        }
        return result;
    }
};