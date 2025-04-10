class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node(int value): val(value),next(nullptr){};
    };
    Node *head;
public:
    MyLinkedList() {
       head=nullptr;
    }
    
    int get(int index) {
        int cnt=0;
        Node* temp=head;
        while(temp){
            if(cnt==index){
                return temp->val;
            }
            else{
                cnt++;
                temp=temp->next;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp=new Node(val);
        temp->next=head;;
        head=temp;
    }
    
    void addAtTail(int val) {
        if(!head) {
            head=new Node(val);
            return;
        }
        Node* t=new Node(val);
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=t;
    }
    
    void addAtIndex(int index, int val) {
        if(!index) {
            addAtHead(val);
            return;
        }
        int cnt=0;
        Node* temp=new Node(val);
        Node* t=head;
        while(t){
            if(cnt!=index-1){
                cnt++;
                t=t->next;
            }
            else break;
        }
        if(!t) return;
        temp->next=t->next;
        t->next=temp;
    }
    
    void deleteAtIndex(int index) {
        if(!head) return;
        int cnt=0;
        Node* t=head;
        if(!index){
            head=head->next;
            delete(t);
            return;
        }
        while(t){
            if(cnt!=index-1){
                cnt++;
                t=t->next;
            }
            else break;
        }
        if(!t || !t->next) return;
        Node* temp=t->next;
        t->next=temp->next;
        temp->next=nullptr;
        delete(temp);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */