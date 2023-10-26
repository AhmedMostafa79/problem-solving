SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode*head=new SinglyLinkedListNode(0),*tail=head;
    while(head1 and head2){
        if(head1->data<=head2->data  ){
           tail->next=head1;
           head1=head1->next;
        }
        else {
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }
    while(head1){
        tail->next=head1;
        tail=tail->next;
        head1=head1->next;
    }
    while(head2){
        tail->next=head2;
        tail=tail->next;
        head2=head2->next;
    }
   return head->next;
}
