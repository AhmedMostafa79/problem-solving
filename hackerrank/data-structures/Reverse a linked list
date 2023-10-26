SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode*cur=head;
    vector<int>v;
    while(cur!=NULL){
        v.push_back(cur->data);
        cur=cur->next;
    }
    cur=head;
    while(cur!=NULL){
        cur->data=v.back(),v.pop_back();
        cur=cur->next;
    }
    return head;
}
