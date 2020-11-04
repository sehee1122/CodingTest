#include<stdio.h>
#include<queue>
using namespace std;

void check(int);
int bfs();
queue<int> q;
int N, K;
int isVisited[100001];

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", bfs());
}

int bfs() {
    q.push(N);
    int depth = 0;
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; ++i) {
            int cur = q.front();
            q.pop();
            if (cur == K)
                return depth;
            check(cur+1);
            check(cur-1);
            check(cur*2);
        }
        ++depth;
    }
}

void check(int to) {
    if (to >= 0 && to <= 100000 && !isVisited[to]) {
        isVisited[to] = 1;
        q.push(to);
    }
}

/* 틀린 풀이
// ver.1

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 100000

int N, K;
int MAP[MAX + 1];

int BFS() {
    int V[MAX + 1] = { 0, };
    queue<int> q;
    q.push(N);
    V[N] = 1;

    memset(MAP, 0, sizeof(MAP));
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        if (cur == K) {
            return V[cur] - 1;
        }
        if (cur-1 >= 0 || V[cur-1] == 0) {
            V[cur-1] = V[cur] + 1;
            q.push(cur-1);
        }
        if (cur+1 <= MAX || V[cur+1] == 0) {
            V[cur+1] = V[cur] + 1;
            q.push(cur+1);
        }
        if (2*cur <= MAX || V[2*cur] == 0) {
            V[2*cur] = V[cur] + 1;
            q.push(2*cur);
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", BFS());
}
*/