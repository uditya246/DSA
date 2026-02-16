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
        ListNode* n1 = list1;
        ListNode* n2 = list2;
        if(n1==NULL){
            return n2;
        }
        else if(n2==NULL){
            return n1;
        }

		if(n1 -> val <= n2 -> val)
        {
			n1 -> next = mergeTwoLists(n1 -> next, n2);
			return n1;
		}
		
		else
        {
			n2 -> next = mergeTwoLists(n1, n2 -> next);
			return n2;            
		}
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left > right) return NULL;
        if(left == right) return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        if(lists.empty()) return ans;
        return merge(lists,0,lists.size()-1);
    }
};