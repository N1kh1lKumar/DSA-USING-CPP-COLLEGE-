//Problrem Description: Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
//leetcode link: https://leetcode.com/problems/odd-even-linked-list/description/  (problem no. = 328)

#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* t1 = head;
        ListNode* t2 = head->next;
        ListNode* temphead = head->next;

        while (t2 != NULL && t2->next != NULL) {

            t1->next = t1->next->next;
            t1 = t1->next;

            t2->next = t2->next->next;
            t2 = t2->next;
        }


        t1->next = temphead;

        return head;
    }
};


    ListNode* convertArr( vector<int>& vec){
        ListNode* head = new ListNode(vec[0]);
        ListNode* mover = head;

        for(int i= 1; i<vec.size() ; i++){
            ListNode* newNode = new ListNode(vec[i]);
            mover->next = newNode;
            mover = mover->next;
        }
        return head; 
     }

  void print(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->val << " " ;
        temp = temp->next;
    }
    cout << endl;
}




int main(){

    vector<int> arr = {1,2,3,4,5,6};
    ListNode* head = convertArr(arr);
  

    cout << "Original List:\n";
    print(head);

    Solution obj;
    head = obj.oddEvenList(head);

    cout << "After Odd-Even Rearrangement:\n";
    print(head);

    return 0;
}