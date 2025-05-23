#include<iostream>
#include "LinkedList.h" // custom header file for linked list creation and printing in main function
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // check if k nodes exist
        while(cnt<k){
            if(temp==NULL){
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // recursively call for rest of linked list 
        ListNode* prevNode = reverseKGroup(temp,k);


        // reverse current group 
        temp = head; cnt= 0;
        while(cnt<k){
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;
            cnt++;
        }
        return prevNode;

    }


int main(){
    ListNode* head = createList({1,2,3,4,5});
    cout<<"Before reversing: ";
    printList(head);
    head = reverseKGroup(head,2);
    cout<<"After reversing: ";
    printList(head);
    return 0;
}