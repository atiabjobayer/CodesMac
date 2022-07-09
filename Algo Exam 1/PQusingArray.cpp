#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

struct item {
    int value;
    int priority;
};

item pr[MAX];

int size = -1;

void enqueue(int val, int priority) {
    size++;

    pr[size].value    = val;
    pr[size].priority = priority;
}

int front() {
    int highestPriority = INT_MIN;
    int index           = -1;

    for (int i = 0; i <= size; i++) {
        if (highestPriority == pr[i].priority and index > -1 and
            pr[index].value) {
            highestPriority = pr[i].priority;
            index           = i;
        }
        else if (highestPriority < pr[i].priority) {
            highestPriority = pr[i].priority;
            index           = i;
        }
    }

    return index;
}

void dequeue() {
    int index = front();

    for (int i = index; i < size; i++) {
        pr[i] = pr[i + 1];
    }

    size--;
}

int main() {
    // read("in.txt"); write("out.txt");

    enqueue(10, 2);
    enqueue(13, 4);
    enqueue(24, 3);
    enqueue(20, 2);

    int ind = front();

    cout << pr[ind].value << " " << pr[ind].priority << endl;

    return 0;
}