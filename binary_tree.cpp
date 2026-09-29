#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;                          // hidden — outside code can't touch it

    // ---- private recursive helpers ----
    Node* insertHelper(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->value)
            node->left = insertHelper(node->left, value);
        else
            node->right = insertHelper(node->right, value);
        return node;
    }

    Node* minNode(Node* node) const {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* removeHelper(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->value) {
            node->left = removeHelper(node->left, value);
        } else if (value > node->value) {
            node->right = removeHelper(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;                          // Case 1: leaf
                return nullptr;
            }
            if (node->left == nullptr) {              // Case 2: one child
                Node* child = node->right;
                delete node;
                return child;
            }
            if (node->right == nullptr) {
                Node* child = node->left;
                delete node;
                return child;
            }
            Node* successor = minNode(node->right);   // Case 3: two children
            node->value = successor->value;
            node->right = removeHelper(node->right, successor->value);
        }
        return node;
    }

    void inorderHelper(Node* node) const {
        if (node == nullptr) return;
        inorderHelper(node->left);
        std::cout << node->value << " ";
        inorderHelper(node->right);
    }

    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() { destroy(root); }            // destructor — frees the whole tree

    void insert(int value) { root = insertHelper(root, value); }
    void remove(int value) { root = removeHelper(root, value); }

    bool contains(int value) const {
        Node* node = root;
        while (node != nullptr) {
            if (value == node->value) return true;
            node = (value < node->value) ? node->left : node->right;
        }
        return false;
    }

    void printInOrder() const {
        inorderHelper(root);
        std::cout << "\n";
    }
};

int main() {
    BST tree;

    for (int v : {40, 25, 60, 30, 50, 70, 35})
        tree.insert(v);

    tree.printInOrder();        // 25 30 35 40 50 60 70

    tree.remove(25);
    tree.printInOrder();        // 30 35 40 50 60 70

    std::cout << tree.contains(35) << "\n";   // 1
}   // ← tree dies here: ~BST() runs automatically, every node freed