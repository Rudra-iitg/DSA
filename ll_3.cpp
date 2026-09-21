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
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(size_t i = 1 ; i < arr.size(); i++){
        current -> next = new Node(arr[i]);
        current = current -> next;
    }
    Node *temp = head;
    traverse_ll(temp);
    return 0;
}
