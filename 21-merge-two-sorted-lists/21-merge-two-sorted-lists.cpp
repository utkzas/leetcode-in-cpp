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

// splicing == join or connect
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2; // nothing to merge
        if(list2==NULL) return list1; // nothing to merge
        if(list1->val > list2->val) std::swap(list1,list2); // by default we keep list1 as smaller list
        ListNode *answ=list1;
        while(list1!=NULL && list2!=NULL){
            ListNode *temp=NULL;
            while(list1 !=NULL && list1->val <= list2->val){ //until list1 val is still lesser than list2
                temp=list1; // keep saving the just prev ptr
                list1=list1->next; //move forward
            }
            temp->next=list2;  // have a new connection and break the old one
            std::swap(list1,list2); // ? swap list1 and list 2 before every iteration
        }
        return answ;
    }
};


// Brute Force: TC: O(n1+n2), SC: O(n1+n2) : create a dummy head and dummy tail. iterate over both heads of the LLs. compare, whichever is larger must have it's value copied into new dummy node (another dummy tail) . through this way, dummy head and dummy tails make up a new LL which is the merged list. this will take extra spacec

//Optimized: TC: O(n1+n2) SC: O(1) as it was inplace: 

