// #include <vector>
// #include <queue>
// #include <unordered_set>
// using namespace std;

// class Solution {
// public:
//     int minimumOneBitOperations(int n) {
//         if (n == 0) return 0;
        
//         // BFS to find minimum operations
//         // State: (current_number, can_do_op1, can_do_op2, operations_count)
//         queue<tuple<int, bool, bool, int>> q;
//         unordered_set<int> visited;
        
//         // Initially, both operations are allowed
//         q.push({n, true, true, 0});
//         visited.insert(n);
        
//         while (!q.empty()) {
//             auto [current, canOp1, canOp2, ops] = q.front();
//             q.pop();
            
//             // If we reached 0, return the number of operations
//             if (current == 0) {
//                 return ops;
//             }
            
//             // Operation 1: Toggle the rightmost (0th) bit
//             if (canOp1) {
//                 int next1 = current ^ 1; // XOR with 1 to toggle rightmost bit
                
//                 if (visited.find(next1) == visited.end()) {
//                     visited.insert(next1);
//                     // After op1: can't do op1 next (n1=-1), can do op2 (n2=1)
//                     q.push({next1, false, true, ops + 1});
//                 }
//             }
            
//             // Operation 2: Find the leftmost bit where we can apply operation 2
//             // Can change ith bit if (i-1)th bit is 1 and all bits from (i-2) to 0 are 0
//             if (canOp2) {
//                 for (int i = 1; i < 31; i++) {
//                     // Check if bit (i-1) is set to 1
//                     if ((current & (1 << (i - 1))) != 0) {
//                         // Check if all bits from (i-2) to 0 are 0
//                         bool allZeros = true;
//                         for (int j = 0; j < i - 1; j++) {
//                             if ((current & (1 << j)) != 0) {
//                                 allZeros = false;
//                                 break;
//                             }
//                         }
                        
//                         if (allZeros) {
//                             int next2 = current ^ (1 << i); // Toggle ith bit
                            
//                             if (visited.find(next2) == visited.end()) {
//                                 visited.insert(next2);
//                                 // After op2: can do op1 (n1=1), can't do op2 (n2=-1)
//                                 q.push({next2, true, false, ops + 1});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
        
//         return -1; // Should never reach here
//     }
// };

using namespace std;

class Solution {
public:
    // Optimized O(log n) solution using Gray Code property
    // The minimum operations to convert n to 0 is actually the inverse Gray code
    int minimumOneBitOperations(int n) {
        int result = 0;
        
        // XOR all bits from left to right
        // This converts from binary to Gray code (inverse operation)
        while (n > 0) {
            result ^= n;
            n >>= 1;
        }
        
        return result;
    }
};

/* 
EXPLANATION:
============

Why your BFS solution TLE:
- Time Complexity: O(2^n) - exponential, explores too many states
- Space Complexity: O(2^n) - stores all visited states
- For n=339963 (19 bits), it tries to explore millions of states

Why this solution works:
- This problem is equivalent to Gray Code transformation
- Gray Code: sequence where adjacent numbers differ by exactly 1 bit
- The operations given follow Gray Code rules!

The pattern:
- To go from any number to 0, we follow inverse Gray code
- Inverse Gray code formula: repeatedly XOR with right-shifted value

Example with n=6 (binary: 110):
  110
^ 011 (110 >> 1)
------
  101
^ 010 (011 >> 1)  
------
  111
^ 001 (010 >> 1)
------
  110
^ 000 (001 >> 1)
------
  110 (but we continue until n becomes 0)

Actually for n=6:
  result = 0
  result ^= 6    -> result = 6   (110)
  result ^= 3    -> result = 5   (101)
  result ^= 1    -> result = 4   (100)
  result ^= 0    -> result = 4
  
Answer: 4 operations ✓

Time Complexity: O(log n) - only processes each bit once
Space Complexity: O(1) - constant space

This is the mathematical insight that makes the problem solvable efficiently!
*/