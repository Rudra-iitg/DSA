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
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // tortoise: 1 step
        fast = fast->next->next;   // hare:    2 steps
        if (slow == fast)          // same ADDRESS = same node
            return true;           // caught up → must be a loop
    }
    return false;                  // fast hit nullptr → no cycle
}
int main(){
    vector<int> arr = {34, 32, 12, 43, 54, 23, 42,65 ,76 ,25, 89, 94,67,43,72, 88};
    Node* head = new Node(arr[0]);
    Node* current = head -> next;
    for(size_t i = 1; i < arr.size(); i++){
        current -> next = new Node(arr[i]);
        current = current -> next;
    }   
    current -> next = head;
    Node* temp = head;
    do{
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }while(temp -> next != head);
    cout << "(back to " << head -> data << " )\n";
    Node* tail = head;
    while(tail -> next != head) tail = tail -> next;
    tail -> next = nullptr;
    
    while(head != nullptr){
        Node* nxt = head -> next;
        delete nxt;
        head = nxt;
    }
    return 0;
}