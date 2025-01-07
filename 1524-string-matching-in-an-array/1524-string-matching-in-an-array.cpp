class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        vector<bool> visited(n, false); // To track if a word is already in the result
        // Iterate through all pairs of words
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Ensure we are not comparing a word with itself
                if (i != j && !visited[i]) {
                    // Check if words[i] is a substring of words[j]
                    if (words[j].find(words[i]) != string::npos) {
                        result.push_back(words[i]);
                        visited[i] = true; // Mark as visited
                        break; // No need to check further once it's found
                    }
                }
            }
        }
        return result;
    }
};