class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        // Left-to-right pass
        int balls = 0; // Number of balls encountered so far
        int moves = 0; // Accumulated moves
        for (int i = 0; i < n; i++) {
            answer[i] += moves;
            balls += (boxes[i] == '1'); // Add balls at current position
            moves += balls;            // Update moves for the next position
        }
        
        // Right-to-left pass
        balls = 0; // Reset number of balls
        moves = 0; // Reset accumulated moves
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += moves;
            balls += (boxes[i] == '1'); // Add balls at current position
            moves += balls;            // Update moves for the next position
        }
        
        return answer;
    }
};
