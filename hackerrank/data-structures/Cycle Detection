bool has_cycle(SinglyLinkedListNode* head) {
    map< SinglyLinkedListNode*,bool>m;
    SinglyLinkedListNode*cur=head;
    while(cur){
        if(m.count(cur))return 1;
        m[cur]=1;
        cur=cur->next;
    }
    return 0;
}

