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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answ= new ListNode; // new node to store head of answ
        ListNode *temp= answ; // store tail of answ
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry) //iterate till either of them  becomes null
        {
            int sum=0; 
            if(l1!=NULL){ //add digit 1
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){ // add digit 2
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10; // reinitialize carry
            ListNode *newnode = new ListNode(sum%10); // create a new node and attach it
            temp->next=newnode;
            temp=temp->next;
        }
        return answ->next;
    }
};


// Brute Force/Optimized Solution: TC: O(max(n1,n2)), SC: O(N). reverse both the lists. maintain a sum and a carry. add head1 and head2. add sum%10 to answ->data, and sum/10 to carry. 