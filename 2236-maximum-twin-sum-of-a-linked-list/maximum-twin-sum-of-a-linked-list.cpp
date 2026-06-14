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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        stack<int>st;
        st.push(slow->val);
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            st.push(slow->val);
        }
        int maxi = INT_MIN;
        slow = slow->next;
        while(slow!=NULL){
            auto x = st.top();
            maxi = max(slow->val+x,maxi);
            st.pop();
            slow = slow->next;
        }
        return maxi;

    }
};