#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;

    vector<Node*> children;
    Node(int x): data(x){}
};
void PrintTree(Node* node){
    cout << node->data << " : ";
    for(Node* child : node->children){
        cout << child->data << " ";
    }
    cout << endl;

    for(Node* child: node-> children){
        PrintTree(child);
    }
}
int CountNode(Node* node) {
    int count = 1;

    for (Node* child : node->children) {
        count += CountNode(child);
    }

    return count;
}
int main(){
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    root->children.push_back(n2);
    root->children.push_back(n3);
    n2->children.push_back(n4);
    n2->children.push_back(n5);
    PrintTree(n2);
    cout << endl;
    cout << "Total number of nodes are: ";
    cout << CountNode(root);
    cout << endl;
    delete n4;
    delete n3;
    delete n5;
    delete n2;
    delete root;
    return 0;
}