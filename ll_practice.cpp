#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1) {data = data1; next = next1;}
        Node(int data1){data = data1; next = nullptr;}
};
int main(){
    vector<int> arr = {4, 6, 3, 5, 12, 15};
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i = 1 ; i < (int)arr.size(); i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> " ;
        temp = temp->next;
    }
    cout << "nullptr\n";
    temp = head;
    while(temp != nullptr){
        Node* nextNode = temp -> next;
        delete temp;
        temp = nextNode;
    }
    return 0;
}