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
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL){
//             return true;
//         }
//         //reversed
//         ListNode* prev = NULL;
//         ListNode* front = NULL;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             front = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = front;
//         }
//         //checked
//         ListNode* temp1=head;
//         ListNode* temp2=prev;
//         while(temp1!=NULL && temp2!= NULL){
//             if(temp1->val!=temp2->val){
//                 return false;
//             }
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         return true;
//     } 
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        vector<int>arr; 
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int low = 0;
        int high = arr.size()-1;
        while(low<high){
            if(arr[low]!=arr[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    } 
};