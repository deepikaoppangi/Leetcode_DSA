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
//     ListNode* middleNode(ListNode* head) {
//         int cnt = 0 ;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             cnt++;
//             temp=temp->next;
//         }
//         int k =0;
//         temp = head;
//         while(temp!=NULL){
//             k++;
//             if(k==(cnt/2)+1){
//                 return temp;
//             }
//             temp=temp->next;
//         }
//         return NULL;
//     }
// };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }
};