class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Create a frequency array to count character occurrences
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Create a max priority queue to store characters by their lexicographic order
        priority_queue<pair<char, int>> pq;
        
        // Add characters with non-zero frequencies to the priority queue
        for (char ch = 'z'; ch >= 'a'; ch--) {
            if (freq[ch - 'a'] > 0) {
                pq.push({ch, freq[ch - 'a']});
            }
        }
        
        string result;
        
        while (!pq.empty()) {
            // Get the most frequent character
            char currentChar = pq.top().first;
            int currentCount = pq.top().second;
            pq.pop();
            
            // If result is empty or last character is different
            if (result.empty() || result.back() != currentChar) {
                // Add as many characters as possible within repeat limit
                int addCount = min(currentCount, repeatLimit);
                result.append(addCount, currentChar);
                currentCount -= addCount;
                
                // If there are remaining characters, add to queue
                if (currentCount > 0) {
                    pq.push({currentChar, currentCount});
                }
            } 
            // If we can't add more of current character due to repeat limit
            else if (!pq.empty()) {
                // Get next character
                char nextChar = pq.top().first;
                int nextCount = pq.top().second;
                pq.pop();
                
                // Add one of the next character
                result += nextChar;
                nextCount--;
                
                // Put back characters if they still exist
                if (nextCount > 0) {
                    pq.push({nextChar, nextCount});
                }
                // Put back current character if it still exists
                if (currentCount > 0) {
                    pq.push({currentChar, currentCount});
                }
            }
            // If no other characters available, we're done
            else {
                break;
            }
        }
        
        return result;
    }
};