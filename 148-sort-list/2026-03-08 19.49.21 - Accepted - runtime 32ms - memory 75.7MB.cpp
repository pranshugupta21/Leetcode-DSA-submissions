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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL &&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* mergetwolist(ListNode* head1,ListNode* head2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* currNode=dummyNode;
        while(head1 && head2){
            if(head1->val<head2->val){
                currNode->next=head1;
                head1=head1->next;
            }
            else{
                currNode->next=head2;
                head2=head2->next;
            }
            currNode=currNode->next;
        }
        if(head1){
            currNode->next=head1;
        }
        else{
            currNode->next=head2;
        }
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        ListNode* left=sortList(lefthead);
        ListNode* right=sortList(righthead);
        return mergetwolist(left,right);
    }
};