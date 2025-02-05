#include <iostream>

using namespace std;

int nextNode[100100], prevNode[100100];

int findTail(int node) {
    if(nextNode[node] == node) return node;
    return findTail(nextNode[node]);
}

int main() {
    int n, from, to, tailOfFrom, head;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        prevNode[i] = i;
        nextNode[i] = i;
    }

    for(int i = 1; i < n; i++) {
        cin >> from >> to;
        if(nextNode[to] != to) {
            tailOfFrom = findTail(from);
            prevNode[nextNode[to]] = nextNode[tailOfFrom];
            nextNode[tailOfFrom] = nextNode[to];
            nextNode[to] = from;
            prevNode[from] = to;
        } else {
            prevNode[from] = to;
            nextNode[to] = from;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(prevNode[i] == i) {
            head = i;
            break;
        }
    }

    cout << head << " ";
    while(nextNode[head] != head) {
        head = nextNode[head];
        cout << head << " ";
    }
    return 0;
}