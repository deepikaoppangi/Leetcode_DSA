class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (k > n) return false; // Cannot create more palindromes than the number of characters

        vector<int> freq(26, 0); // Frequency array for 'a' to 'z'
        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0; // Count of characters with odd frequencies
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        return oddCount <= k; // Can construct palindromes if oddCount <= k
    }
};
