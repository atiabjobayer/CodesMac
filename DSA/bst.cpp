#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

class Node {
    int val;
    Node *left, *right;

  public:
    Node();
    Node(int);
    Node *insert(Node *, int);

    void inorder(Node *);
    Node *inOrderSucc(Node *)
};

Node::Node() : val(0), left(NULL), right(NULL) {}

Node::Node(int data) {
    val   = data;
    left  = NULL;
    right = NULL;
}

Node *Node::insert(Node *root, int data) {
    if (!root) {
        return new Node(data);
    }

    if (data < root->val) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

void Node::inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

Node *Node::inOrderSucc(Node *root) {
    Node *curr = root;

    while (curr and curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}

int main() {
    // read("in.txt"); write("out.txt");

    Node b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.inorder(root);

    return 0;
}