#include <stdio.h>
#include <queue>
using namespace std;
 
struct SHARK {
    int y, x, time;
};
 
int N;
int MAP[20][20];
 
int shark_size, shark_eat;
SHARK shark;
 
const int dy[] = { 0, 0, -1, +1 };
const int dx[] = { -1, +1, 0, 0 };

int bfs() {
    // is_update: 상어가 먹을 물고기가 있는지 체크
    bool is_update = true;
    while (is_update) {
        // update가 없으면 한 번 돌고 
        is_update = false;
 
        bool VISITED[20][20] = { false, };
        queue<SHARK> q;
        VISITED[shark.y][shark.x] = true;
        // 초기 위치를 queue에 넣음
        q.push(shark);

        // 상어가 먹을 수 있는 물고기가 여러 마리일 때, 그 중 최적의 한마리 candi
        SHARK candi;
        // candi의 y는 이 지도의 가장 큰 값으로 초기화, candi.y보다 작은 곳 물고기를 먹게끔 update
        candi.y = 20, candi.time = -1;
		// empty(): queue가 비어있으면 true, !q.empty(): 비어있으면 false, 0
		// queue를 이용해서 순회, 비어있지 않을 때 실행
        while (!q.empty()) {
            // current가 queue의 front
			// front(): 큐 제일 앞의 원소 반환, pop(): 큐에 있는 원소 삭제(앞에)
            SHARK cur = q.front();  q.pop();

            // candi.time이 갱신이 되었을 때
            // 이 조건은 가까운 물고기는 이미 잡았다는 뜻, while문 탈출
            if (candi.time != -1 && candi.time < cur.time) {
                break;
            }

            // 이 위치에 물고기가 있을 때, 크기 비교
            if (MAP[cur.y][cur.x] < shark_size && MAP[cur.y][cur.x] != 0) {
                // 물고기를 먹었음을 표현
                is_update = true;
                // y값 -> x값 순으로 작은 것 표현
                if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
                    candi = cur;
                }
            }
 
            // 사방향 탐색, next 위치를 잡아줌
            for (int dir = 0; dir < 4; ++dir) {
                SHARK next;
                next.y = cur.y + dy[dir];
                next.x = cur.x + dx[dir];
                next.time = cur.time + 1;
                // 범위 밖
                if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) {
                    continue;
                }
                // 움직일 수 있는지 체크, 방문한 적이 없고 상어의 크기보다 작거나 같다
                if (VISITED[next.y][next.x] == false && shark_size >= MAP[next.y][next.x]) {
                    VISITED[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }
 
        // 물고기를 먹을 수 있다면 true, while문 계속 돌면 된다
        if (is_update) {
            shark = candi;
            ++shark_eat;
            if (shark_eat == shark_size) {
                ++shark_size;
                shark_eat = 0;
            }
            MAP[shark.y][shark.x] = 0;
        }
    }
    return shark.time;
}

int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            scanf("%d", &MAP[y][x]);

            if (MAP[y][x] == 9) {
                shark.y = y, shark.x = x, shark.time = 0;
                shark_size = 2, shark_eat = 0;
                MAP[y][x] = 0;
            }
        }
    }
    printf("%d\n", bfs());
}


/*
#include <stdio.h>
#include <queue>
using namespace std;
 
struct SHARK {
    int y, x, time;
};
 
int N;
int MAP[20][20];
 
int shark_size, shark_eat;
SHARK shark;
 
const int dy[] = { 0, 0, -1, +1 };
const int dx[] = { -1, +1, 0, 0 };
 
int main()
{
    scanf("%d", &N);
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            scanf("%d", &MAP[y][x]);

            if (MAP[y][x] == 9) {
                shark.y = y, shark.x = x, shark.time = 0;
                shark_size = 2, shark_eat = 0;
                MAP[y][x] = 0;
            }
        }
    }
    
    // is_update: 상어가 먹을 물고기가 있는지 체크
    bool is_update = true;
    while (is_update) {
        // update가 없으면 한 번 돌고 
        is_update = false;
 
        bool VISITED[20][20] = { false, };
        queue<SHARK> q;
        VISITED[shark.y][shark.x] = true;
        // 초기 위치를 queue에 넣음
        q.push(shark);

        // 상어가 먹을 수 있는 물고기가 여러 마리일 때, 그 중 최적의 한마리 candi
        SHARK candi;
        // candi의 y는 이 지도의 가장 큰 값으로 초기화, candi.y보다 작은 곳 물고기를 먹게끔 update
        candi.y = 20, candi.time = -1;
		// empty(): queue가 비어있으면 true, !q.empty(): 비어있으면 false, 0
		// queue를 이용해서 순회, 비어있지 않을 때 실행
        while (!q.empty()) {
            // current가 queue의 front
			// front(): 큐 제일 앞의 원소 반환, pop(): 큐에 있는 원소 삭제(앞에)
            SHARK cur = q.front();  q.pop();

            // candi.time이 갱신이 되었을 때
            // 이 조건은 가까운 물고기는 이미 잡았다는 뜻, while문 탈출
            if (candi.time != -1 && candi.time < cur.time) {
                break;
            }

            // 이 위치에 물고기가 있을 때, 크기 비교
            if (MAP[cur.y][cur.x] < shark_size && MAP[cur.y][cur.x] != 0) {
                // 물고기를 먹었음을 표현
                is_update = true;
                // y값 -> x값 순으로 작은 것 표현
                if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
                    candi = cur;
                }
            }
 
            // 사방향 탐색, next 위치를 잡아줌
            for (int dir = 0; dir < 4; ++dir) {
                SHARK next;
                next.y = cur.y + dy[dir];
                next.x = cur.x + dx[dir];
                next.time = cur.time + 1;
                // 범위 밖
                if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) {
                    continue;
                }
                // 움직일 수 있는지 체크, 방문한 적이 없고 상어의 크기보다 작거나 같다
                if (VISITED[next.y][next.x] == false && shark_size >= MAP[next.y][next.x]) {
                    VISITED[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }
 
        // 물고기를 먹을 수 있다면 true, while문 계속 돌면 된다
        if (is_update) {
            shark = candi;
            ++shark_eat;
            if (shark_eat == shark_size) {
                ++shark_size;
                shark_eat = 0;
            }
            MAP[shark.y][shark.x] = 0;
        }
    }
    printf("%d\n", shark.time);
    return 0;
}
//</shark>


//출처: https://na982.tistory.com/101?category=145346 [na982]


/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 500


// 알고리즘: 완전탐색(BFS)
// 1. 최단 경로 찾기
// 2. BFS: 모든 간선의 가중치가 1일 때 최단 경로
// 3. BFS: 시간 복잡도
//     1) 인접리스트를 사용한 경우
//     2) 인접행렬을 사용한 경우

// 상어 또는 물고기의 좌표(x, y)를 저장할 구조체 정의
struct shark {
	int first, second, size, feed;
};

// 가장 위, 왼쪽 비교 - pair 사용
struct pair {
	int first, second;
};
struct shark sk;
struct pair q[MAX];
int N,rear,front;
int map[20][20];
int d[20][20];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int ans = 0;
void gofeed() {
	rear = 0, front = 0;
	q[rear].first = sk.first; q[rear].second = sk.second;
	d[sk.first][sk.second] = 1;
	rear += 1;
	int ok = 0;
	int gx = 987, gy = 987;
	int ret = 0;
	int ct = 1;
	int val = 0;
	while (front != rear) {
		int st = front, ed = rear;
		val += 1;
		for (int i = st; i < ed; i++) {
			int x = q[front].first; int y = q[front].second;
			front += 1;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j]; int ny = y + dy[j];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (d[nx][ny] >= ct) continue;
				if (map[nx][ny] <= sk.size) {
					if (map[nx][ny] > 0 && map[nx][ny] < sk.size) {
						if (gx > nx) {
							gx = nx; gy = ny;
						}
						else if (gx == nx) {
							if (gy > ny)
								gy = ny;
						}
						ok = 1;
					}
					else if(map[nx][ny] == 0 || map[nx][ny] == sk.size){
						d[nx][ny] = ct;
						q[rear].first = nx; q[rear].second = ny;
						rear += 1;
					}
				}
			}
		}
		if (ok) {
			sk.feed += 1;
			ct += 1;
			if (sk.feed == sk.size) {
				sk.feed = 0; sk.size += 1;
			}
			ans += val;
			val = 0;
			sk.first = gx; sk.second = gy;
			front = 0, rear = 0;
			q[rear].first = gx; q[rear].second = gy;
			d[gx][gy] = ct;
			rear += 1;
			map[gx][gy] = 0;
			gx = 987, gy = 987;
			ok = 0;
		}
	}
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);

            // 아기 상어의 경우
            if(map[i][j] == 9) {
                // x, y를 따로 지정
                sk.first = i;
                sk.second = j;
                sk.size = 2;
                map[i][j] = 0;
            }
        }
    } gofeed();
    printf("%d\n", ans);
}
*/