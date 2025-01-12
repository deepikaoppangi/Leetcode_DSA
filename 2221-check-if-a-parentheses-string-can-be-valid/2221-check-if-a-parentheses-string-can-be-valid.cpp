class Solution {
public:
    bool canBeValid(string s, string locked) {
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
                balance += (s[i] == '(' ? 1 : -1); // Update balance
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
                balance += (s[i] == ')' ? 1 : -1); // Update balance
            }
            // If balance goes negative, unlocked must compensate
            if (balance < -unlocked) {
                return false;
            }
        }
        return true;
    }
};
