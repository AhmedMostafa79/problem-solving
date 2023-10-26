SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
   SinglyLinkedListNode*newnode= new  SinglyLinkedListNode(data);
  if(head==NULL){
      head=newnode;
      return head;
  }
    SinglyLinkedListNode*cur=head;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=newnode;
    return head;
}
