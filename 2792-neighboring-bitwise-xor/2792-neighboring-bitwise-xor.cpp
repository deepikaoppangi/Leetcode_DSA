class Solution {
public:

    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Function to simulate the original array given initial value
        auto simulate = [&](int original_0) -> vector<int> {
            vector<int> original(n);
            original[0] = original_0;
            for (int i = 1; i < n; ++i) {
                original[i] = original[i - 1] ^ derived[i - 1];
            }
            return original;
        };

        // Simulate for original[0] = 0 and original[0] = 1
        vector<int> original_case1 = simulate(0);
        vector<int> original_case2 = simulate(1);

        // Check cyclic condition for both cases
        if ((original_case1[n - 1] ^ original_case1[0]) == derived[n - 1]) {
            return true;
        }
        if ((original_case2[n - 1] ^ original_case2[0]) == derived[n - 1]) {
            return true;
        }

        return false;
    }

};

