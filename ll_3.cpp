#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1, Node*next1){data = data1; next = next1;}
        Node(int data2){data = data2; next = nullptr;}
};
void traverse_ll(Node* head){
    if(head == nullptr) return ;
    cout << head->data;
    if(head -> next != nullptr) cout << " -> ";
    else cout << " -> nullptr\n";
    traverse_ll(head->next);
}
void insert_at_position(Node*& head, int x, int k){
    // Case 1: position 0 or empty list → new node becomes the head
    if (k <= 0 || head == nullptr) {
        Node* new_node = new Node(x);
        new_node->next = head;
        head = new_node;
        return;
    }

    // Case 2: walk to the node BEFORE position k
    Node* prev = head;
    for (int i = 0; i < k - 1 && prev->next != nullptr; i++)
        prev = prev->next;

    // Case 3: rewire (order matters!)
    Node* new_node = new Node(x);
    new_node->next = prev->next;   // ① grab the rest of the list
    prev->next = new_node;         // ② then let prev point to new
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(size_t i = 1 ; i < arr.size(); i++){
        current -> next = new Node(arr[i]);
        current = current -> next;
    }
    Node* temp = head;
    traverse_ll(temp);
    insert_at_position(temp, 7 , 4);
    traverse_ll(temp);
    while(head != nullptr){
        Node* next = head->next;
        delete head;
        head = next;
    }
    return 0;
}
