#include <iostream>
#include <queue>
#include <string> 

using namespace std;
struct Node {
    string data;
    Node* left;
    Node* right;
};
Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
Node* insertNode(Node* root, string data) {
    if (root == nullptr) {
        return createNode(data);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr) {
            current->left = createNode(data);
            break;
        } else {
            q.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = createNode(data);
            break;
        } else {
            q.push(current->right);
        }
    }
    return root;
}
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node* root){
    if(root != nullptr){
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Node* root){
    if(root != nullptr){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}
void levelOrderTraversal(Node* root){
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left != nullptr){
            q.push(current->left);
        }

        if(current->right != nullptr){
            q.push(current->right);
        }
    }
}
bool searchNode(Node* root, string data) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    return searchNode(root->left, data) || searchNode(root->right, data);
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, "University");
    root = insertNode(root, "Lectures");
    root = insertNode(root, "Friends");
    root = insertNode(root, "Assignments");
    root = insertNode(root, "Clubs");
    root = insertNode(root, "Exams");
    root = insertNode(root, "Socials");
    root = insertNode(root, "Library");
    root = insertNode(root, "Study Groups");
    root = insertNode(root, "Parties");
    root = insertNode(root, "Presentations");

    cout << "Binary Tree Operations (Student Life):" << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    string searchItem = "Clubs";
    if (searchNode(root, searchItem)) {
        cout << "'" << searchItem << "' found in the tree." << endl;
    } else {
        cout << "'" << searchItem << "' not found in the tree." << endl;
    }

    string searchItem2 = "Sleep";

    if(searchNode(root, searchItem2)){
        cout << "'" << searchItem2 << "' found in the tree." << endl;
    } else {
        cout << "'" << searchItem2 << "' not found in the tree." << endl;
    }
    return 0;
}