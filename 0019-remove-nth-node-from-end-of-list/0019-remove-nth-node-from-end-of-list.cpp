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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int cnt=0;
//         ListNode* temp=head;
//         while(temp){
//             cnt++;
//             temp=temp->next;
//         }
//         int k = cnt-n+1; //from begining
//         if(k==1){
//             temp=head;
//             head=head->next;
//             delete temp;
//             return head;
//         }
//         temp=head;
//         ListNode* prev = NULL;
//         int p=0;
//         while(temp){
//             p++;
//             if(p==k){
//                 prev->next=prev->next->next;
//                 delete temp;
//                 break;
//             }
//             prev=temp;
//             temp=temp->next;
//         }
//         return head;
//     }
// };



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* remove = slow->next;        //slow remove 
        slow->next=slow->next->next;
        delete remove;
        return head;
    }
};