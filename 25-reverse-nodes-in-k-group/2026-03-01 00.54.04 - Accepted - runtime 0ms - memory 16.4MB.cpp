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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
         for (int i = 0; i < k; i++)
          { if (!node) return head; 
        node = node->next; }
         ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* Next=NULL;
       int count=0;
        while(curr!=NULL && count<k){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
            count++;
        }
        if(curr!=NULL){
            head->next=reverseKGroup(curr,k);
        }
        return prev;
    }
};