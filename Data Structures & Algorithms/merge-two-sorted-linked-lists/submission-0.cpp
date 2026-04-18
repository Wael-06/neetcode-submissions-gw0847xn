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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp1=list1,*temp2=list2;
        ListNode head(0);
        ListNode *res=&head;
        while(temp1!=nullptr&&temp2!=nullptr){
            if(temp1->val<=temp2->val){
                res->next=temp1;
                temp1=temp1->next;
            }else{
                res->next=temp2;
                temp2=temp2->next;
            }
            res=res->next;
        }
        res->next=(temp1?temp1:temp2);
        return head.next;
    }
};
