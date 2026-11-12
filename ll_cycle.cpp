#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) { data = data1; next = next1; }
    Node(int data2) { data = data2; next = nullptr; }
};
int find_circleLen(Node* head){
    Node* fast = head;
    Node* slow = head;
    int count = 0;
    while(fast != nullptr && fast-> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            count = 1;
            while(slow-> next != fast){
                slow = slow -> next;
                count++;
            }
            return count;
        }
    }
    return 0;
}
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // tortoise: 1 step
        fast = fast->next->next;   // hare: 2 steps
        if (slow == fast)          // same address = same node
            return true;           // caught up, so there is a loop
    }
    return false;                  // fast hit nullptr, so no cycle
}
Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != nullptr){
        Node* nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int main() {
    vector<int> arr = {34, 32, 12, 43, 54, 23, 42, 65, 76, 25, 89, 94, 67, 43, 72, 88};

    Node* head = new Node(arr[0]);
    Node* current = head;
    Node* circle = nullptr;

    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
        if (i == 5) circle = current;      // remember node 23
    }
    current->next = circle;                // tail (88) points back to 23

    cout << "Cycle? " << hasCycle(head) << "\n";   // 1

    cout << "========================"<< endl;
    cout << "Length of circle " << find_circleLen(head) << endl;

    // Print the tail, then the loop once, stopping at the second visit to circle
    Node* temp = head;
    int seen = 0;
    while (temp != nullptr) {
        if (temp == circle && ++seen == 2) break;
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "(back to " << circle->data << ")\n";

    current->next = nullptr;               // break the cycle (current is the tail)

    cout << "Cycle? " << hasCycle(head) << "\n";   // 0

    // Safe cleanup: the list now ends in nullptr
    while (head != nullptr) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
    return 0;
}