
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1); // First occurrence of each character
        vector<int> last(26, -1);  // Last occurrence of each character
        
        int n = s.size();
        
        // Track first and last positions of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        int count = 0;
        
        // Iterate over all characters (a to z)
        for (char c = 'a'; c <= 'z'; ++c) {
            int left = first[c - 'a'];
            int right = last[c - 'a'];
            
            if (left != -1 && right != -1 && left < right) {
                unordered_set<char> middleChars;
                
                // Collect unique characters between left and right
                for (int i = left + 1; i < right; ++i) {
                    middleChars.insert(s[i]);
                }
                
                // Add the number of unique characters to the count
                count += middleChars.size();
            }
        }
        
        return count;
    }
};
