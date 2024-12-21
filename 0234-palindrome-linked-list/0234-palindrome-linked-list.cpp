/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


//////////brute force.

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL){
//             return true;
//         }
//         vector<int>arr; 
//         ListNode* temp = head;
//         while(temp){
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
//         int low = 0;
//         int high = arr.size()-1;
//         while(low<high){
//             if(arr[low]!=arr[high]){
//                 return false;
//             }
//             low++;
//             high--;
//         }
//         return true;
//     } 
// };


// optimal
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        // Step 1: Find the middle of the list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = NULL;
        ListNode* temp = slow;
        while (temp != NULL) {
            ListNode* nextTemp = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextTemp;
        }

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val) {
                return false;  // Not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Restore the original structure of the second half (optional)
        // Reverse the second half back to its original structure
        ListNode* current = prev;
        prev = NULL;
        while (current != NULL) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }

        return true;  // It is a palindrome
    }
};
