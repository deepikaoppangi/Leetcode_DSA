

class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int maxScore = 0;
        int countZeros = 0, countOnes = totalOnes;

        for (size_t i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') countZeros++;
            else countOnes--;

            int currentScore = countZeros + countOnes;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
