#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda function to calculate the gain of adding one student
        auto gain = [](int passed, int total) {
            return (double)(passed + 1) / (total + 1) - (double)passed / total;
        };
        
        // Max-heap to store the negative gain and class info
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        
        // Initialize the heap with initial gains
        for (auto& c : classes) {
            int passed = c[0], total = c[1];
            maxHeap.push({gain(passed, total), {passed, total}});
        }
        
        // Assign extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            
            int passed = classInfo.first;
            int total = classInfo.second;
            
            // Add one student
            passed++;
            total++;
            
            // Push the updated class back into the heap
            maxHeap.push({gain(passed, total), {passed, total}});
        }
        
        // Calculate the final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            
            int passed = classInfo.first;
            int total = classInfo.second;
            totalRatio += (double)passed / total;
        }
        
        return totalRatio / classes.size();
    }
};
