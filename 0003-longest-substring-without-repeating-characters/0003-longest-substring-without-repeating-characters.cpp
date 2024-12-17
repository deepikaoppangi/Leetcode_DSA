
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = { -1 };  // Initialize all positions to -1
        fill(hash, hash + 256, -1); // Explicitly set all to -1 to indicate no character is seen yet

        int start = 0; // Start of the sliding window
        int maxLen = 0; // To store the maximum length found

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            // If the character is already in the current window, move `start` forward
            if (hash[ch] >= start) {
                start = hash[ch] + 1;
            }

            // Update the last seen index of the character
            hash[ch] = i;

            // Update the maximum length of the substring
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
