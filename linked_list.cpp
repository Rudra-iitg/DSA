// #include <iostream>
// #include <vector>
// using namespace std;
// class Node{
//     public:
//         int data;
//         Node* next;
//         Node(int data1, Node* next1){
//             data = data1;
//             next = next1;
//         }
//         Node(int data1){
//             data = data1;
//             next = nullptr;
//         }
// };
// int main(){
//     vector<int> arr = {2 ,4, 5, 7, 13};
//     Node* y = new Node(arr[0]);
//     cout << y  << " \n";
//     cout << y->data << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) { data = data1; next = next1; }
    Node(int data1) { data = data1; next = nullptr; }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};

    // Build the list: 2 -> 5 -> 8 -> 7
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < (int)arr.size(); i++) {
        current->next = new Node(arr[i]);  // link new node
        current = current->next;           // move forward
    }

    // Traverse the list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";   // 2 -> 5 -> 8 -> 7 -> nullptr

    // Free memory (avoid leaks!)
    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}