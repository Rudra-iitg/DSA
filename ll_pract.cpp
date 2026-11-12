#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){data = data1; next = next1;}
    Node(int data1){data = data1; next = nullptr;}
};

void insert_new_node_at_k(Node* head, int x, int k){
    if(k <= 0 || head == nullptr){
        Node* newNode = new Node(x);
        newNode -> next = head;
        head = newNode;
        return;
    }
    Node* prev = head;
    for(int i = 0; i < k-1 && prev->next != nullptr; i++){
        prev = prev-> next;
    }
    Node* newNode = new Node(x);
    newNode -> next = prev -> next;
    prev -> next = newNode;
}
int main(){
    vector<int> arr = {3, 5 , 5, 2,6, 23, 34 ,64 ,23, 45, 34};
    Node* head = new Node{arr[0]};
    Node* current = head;
    for(int i = 1; i < arr.size(); i++){
        current->next = new Node{arr[i]};
        current = current -> next;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "nullptr\n";
    temp = head;
    insert_new_node_at_k(temp, 53, 6);
     while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "nullptr\n";

    cout << " =================" << endl;
    temp = head;
    while(temp != nullptr){
        Node* nextNode = temp-> next;
        delete temp;
        temp = nextNode;
    }
    return 0;
}