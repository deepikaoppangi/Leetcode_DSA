/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         map<ListNode* ,int>mpp;
//         ListNode* temp=head;
//         while(temp){
//             if(mpp.find(temp)!=mpp.end()){
//                 return temp;
//             }
//             mpp[temp]=1;
//             temp=temp->next;
//         }
//         return NULL;
//     }
// };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                ListNode* entry = head;
                while(entry!=slow){
                    slow=slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};