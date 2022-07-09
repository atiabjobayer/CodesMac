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
    // declared tree properties
    Node *left;
    Node *right;

    int data;

    // declaring constructor

    Node(int val) {
        data = val;

        left  = NULL;
        right = NULL;
    }
};

int main() {
    // read("in.txt"); write("out.txt");

    // create root
    Node *root = new Node(1);

    root->left  = new Node(2);
    root->right = new Node(3);

    return 0;
}