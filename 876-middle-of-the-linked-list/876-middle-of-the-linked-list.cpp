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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL && fast->next!=NULL){ // till we reach null node or last node
            slow=slow->next;
            fast=fast->next->next;
        }
    return slow;
    }
    
};

// Brute Force: TC: O(N)+O(N/2) , SC: O(1) : First iterate the whole linkedlist, then incase n is odd, go to ((n/2)+1)th node and print it. incase n is even, go to n/2 th node and print it.  

// Optimized solution: TC: O(N/2) SC: O(1) : (Tortoise method): maintain two pointers, fast and slow. move slow by 1 step, fast by 2 step. when fast reaches the end, slow will be at the middle.