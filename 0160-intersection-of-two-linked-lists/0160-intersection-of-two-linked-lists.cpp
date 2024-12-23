/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

////submitted
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* temp=headA;
//         map<ListNode*,int>mpp;
//         //pushing
//         while(temp){
//             mpp[temp]=1;
//             temp=temp->next;
//         }
//         temp=headB;
//         //checking
//         while(temp){
//             if(mpp.find(temp)!=mpp.end()){
//                 return temp;
//             }
//             temp=temp->next;
//         }
//         return NULL;
//     }
// };

//my 1st idea

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int cnt1=0;
        int cnt2=0;
        while(temp1){
            cnt1++;
            temp1=temp1->next;
        }
        while(temp2){
            cnt2++;
            temp2=temp2->next;
        }
        int k = abs(cnt2-cnt1);
        temp1=headA;
        temp2=headB;
        if(cnt1<cnt2){
            for(int i=0;i<k;i++){
                temp2=temp2->next;
            }
        }
        else if(cnt1>cnt2){
            for(int i=0;i<k;i++){
                temp1=temp1->next;
            }
        }
        while(temp1 && temp2){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};