/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head)
    {
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL)
        {
            ++count;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)
            return NULL;
        
        int len1 = len(headA),len2 = len(headB);
        ListNode* temp1,*temp2;
        if(len1 >= len2)
        {
            int diff = len1 - len2;
            temp1 = headA;
            for(int i = 0;i<diff;i++)
                temp1 = temp1->next;
            
            temp2 = headB;
            while(temp1!=NULL)
            {
                if(temp1 == temp2)
                    return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else
        {
            int diff = len2 - len1;
            temp1 = headB;
            for(int i = 0;i<diff;i++)
                temp1 = temp1->next;
            
            temp2 = headA;
            while(temp2!=NULL)
            {
                if(temp1 == temp2)
                    return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};