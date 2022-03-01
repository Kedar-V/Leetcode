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
    
    ListNode* insert_node(ListNode* head, int val)
    {
        ListNode* p = new ListNode(val);

        //insert front        
        // p->next = head;
        // return p;
        
        ListNode* curr = head;
        
        if (!curr){
            return p;
        }
        
        // insert end
        while (curr->next != NULL){
            curr = curr->next;
        }
        
        curr->next = p;
        return head;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* head3 = NULL;
        int carry = 0;    
        // vector<int> ans;
        while (curr1 || curr2){
            int val1, val2;
            if (curr1)
                val1 = curr1->val;
            else
                val1 = 0;
            
            if (curr2)
                val2 = curr2->val;
            else
                val2 = 0;
            
            int current_sum = val1 + val2 + carry;
            carry = current_sum/10;
            current_sum = current_sum % 10;
            
            // ans.insert(ans.begin(), current_sum);
            if(curr1)
                curr1 = curr1 -> next;
            if(curr2)
                curr2 = curr2 -> next;
            head3 = insert_node(head3, current_sum);
        }
        if (carry != 0)
            head3 = insert_node(head3, carry);
        
        // for (int i : ans)
        //     cout << i << " ";
        // cout << endl;
        return head3;            
    }
};
