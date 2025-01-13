class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If the entire string is spaces, return 0
        if (i == n) {
            return 0;
        }

        // Handle signs
        bool isNegative = false;
        if (s[i] == '-') {
            isNegative = true;
            i++;
        } else if (s[i] == '+') {
            isNegative = false;
            i++;
        }

        // Process digits
        int ans = 0;
        while (i < n && isdigit(s[i])) {
            // Check for overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (s[i] - '0') > 7)) {
                if (isNegative) {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            }

            // Update the answer
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        // Return the final result
        if (isNegative) {
            return -ans;
        }
        return ans;
    }
};
