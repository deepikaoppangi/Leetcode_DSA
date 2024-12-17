class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int hash[256];
        fill(hash, hash + 256, -1);
        int start = 0; 
        int maxLen = 0;
        for (int i = 0;i < n;i++) {
            char ch = s[i];
            if (hash[ch]!=-1 && hash[ch] >= start) {
                start = hash[ch] + 1;
            }
            hash[ch] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
