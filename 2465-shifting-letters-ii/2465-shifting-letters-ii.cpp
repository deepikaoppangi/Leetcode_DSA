
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0);

        // Step 1: Populate the difference array
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            // Update the difference array
            delta[start] += (direction == 1 ? 1 : -1);
            delta[end + 1] -= (direction == 1 ? 1 : -1);
        }

        // Step 2: Compute cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += delta[i];
            int shift = (cumulativeShift % 26 + 26) % 26; // Ensure positive shift
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
