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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL){
//             return head;
//         }
//         ListNode* front = NULL;
//         ListNode* prev = NULL;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             front = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp=front;
//         }
//         return prev;
//     }
// };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};

