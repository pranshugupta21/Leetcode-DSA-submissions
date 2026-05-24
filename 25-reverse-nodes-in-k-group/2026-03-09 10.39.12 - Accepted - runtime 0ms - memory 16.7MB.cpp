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
ListNode* reverseknodes(ListNode* head,int k){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(k--){
        ListNode* Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* GroupPrev=dummy;
        while(true){
            ListNode* check=GroupPrev;
            for(int i=0;i<k;i++){
                check=check->next;
                if(!check) return dummy->next;
            }
            ListNode* GroupStart=GroupPrev->next;
            ListNode* NextGroup=check->next;
            ListNode* newhead=reverseknodes(GroupStart,k);
            GroupPrev->next=newhead;
            GroupStart->next=NextGroup;
            GroupPrev=GroupStart;
        }
    }
};