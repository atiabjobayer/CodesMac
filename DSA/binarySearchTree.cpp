#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;

        left  = NULL;
        right = NULL;
    }

    Node *insert(Node *root, int val) {
        // root doesnt exist
        if (!root) {
            root = new Node(val);
        }

        if (val <= root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }
};

int main() {
    // read("in.txt"); write("out.txt");

    return 0;
}