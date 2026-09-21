#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        
        Node(int data1, Node* next1){data = data1; next = next1;}
        Node(int data2){data = data2; next = nullptr;}
};
void ll_traversal(Node* head){
    if(head == nullptr){
        cout << endl;
        return;
    }
    cout << head -> data;
    if(head-> next != nullptr) cout << " -> ";

    ll_traversal(head->next);
}
Node* inser_new_node(Node* head, int x){
    Node* new_node = new Node(x);
    new_node-> next = head;
    return new_node; 
}
void insert_end_node(Node* head, int x){
    while (head->next != nullptr) {   
        head = head->next;
    }
    head->next = new Node(x);
}
int main(){
    vector<int> arr = {3, 5, 2,6 ,22, 54};
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(size_t i = 1; i < arr.size(); i++){
        current -> next = new Node(arr[i]);
        current = current -> next; 
    }
    Node* temp = head;
    // while(temp != nullptr){
    //     cout << temp -> data << " -> ";
    //     temp = temp -> next;
    // }
    ll_traversal(temp);
    temp = head;
    Node* new_head = inser_new_node(temp, 25);
    temp = new_head;
    ll_traversal(temp);
    insert_end_node(head,56);
    ll_traversal(temp);
    cout << "nullptr\n";
    temp = new_head;
    while(temp != nullptr){
        Node* nextnode = temp -> next;
        delete temp;
        temp = nextnode;
    }
    return 0;
}