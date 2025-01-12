class Solution {
public:
    bool canBeValid(string s, string locked) {
        // If the length of the string is odd, it's impossible to form valid parentheses
        if (s.size() % 2 == 1) {
            return false;
        }

        int unlocked = 0; // Count of unlocked characters
        int balance = 0;  // Balance of '(' and ')'

        // Left-to-Right Pass
        for (int i = 0; i < s.size(); ++i) {
            if (locked[i] == '0') {
                ++unlocked; // Unlocked can act as either '(' or ')'
            } else {
                if (s[i] == '(') {
                    balance += 1; // Update balance for '('
                } else {
                    balance -= 1; // Update balance for ')'
                }
            }

            // If balance goes negative, unlocked must compensate
            if (balance < -unlocked) {
                return false;
            }
        }

        // Reset for Right-to-Left Pass
        unlocked = 0;
        balance = 0;

        // Right-to-Left Pass
        for (int i = s.size() - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                ++unlocked; // Unlocked can act as either '(' or ')'
            } else {
                if (s[i] == ')') {
                    balance += 1; // Update balance for ')'
                } else {
                    balance -= 1; // Update balance for '('
                }
            }

            // If balance goes negative, unlocked must compensate
            if (balance < -unlocked) {
                return false;
            }
        }

        return true;
    }
};
