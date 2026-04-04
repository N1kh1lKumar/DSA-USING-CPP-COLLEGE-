//Problem Description : Given the head of a linked list, remove the nth node from the end of the list and return its head.
//Problrem link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/   (problem no. = 19)

#include<bits/stdc++.h>
using namespace std;


class ListNode{
public:
    int val;
    ListNode* next;
    

    ListNode(int val){
        this->val = val;
        next = NULL;
    }    
};

class  Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head , int k){
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i =0; i<k; i++) fast = fast->next;
        if(fast == NULL){
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }   

       
        ListNode* delNode = slow->next;
         slow->next = slow->next->next ;
        delete(delNode);

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
    Solution s;
    vector<int> arr = {1,2,3,4,5,6};
    ListNode* head = convertArr(arr);
    print(head);

    head = s.removeNthFromEnd(head , 3);
    print(head);
  


    return 0;
}