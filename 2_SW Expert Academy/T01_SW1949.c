// ver.3
/*
 Kang_kb
제출일 : 2020-01-26 21:28
*/
#include <stdio.h>
// stdlib.h: malloc, free 함수가 선언된 헤더 파일
// memset 함수가 선언된 헤더 파일
#include <string.h>

// T: 테스트 개수, N: 지도 한 변의 길이, K: 최대 공사 가능 깊이
int T, N, K;
// MAP: 지도 전체, V: 방문한 곳
int MAP[10][10], V[10][10];
// 방향성
int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
// 크기 비교 max
int max(int a, int b) {
    return a > b ? a : b;
}

// y, x: direction, k: depth
int DFS(int y, int x, int k) {
    int ret = 1;
    
    // 좌우상하 이동
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        
        // continue: 다음 코드를 실행시키지 않고 건너뜀
        if (ny < 0 || nx < 0 || ny >= N || nx >= N || V[ny][nx]) continue;
        // 새로운 위치가 지금보다 높은 곳일 때
        if (MAP[ny][nx] >= MAP[y][x]) {
            // can go
            if (k && MAP[ny][nx] - k < MAP[y][x]) {
                int tmp = MAP[ny][nx];
                k = 0;
                V[ny][nx] = 1;
                MAP[ny][nx] = MAP[y][x] - 1;
                // nx, nx인 상태로 계속 이동, 1을 더한 이유는? 1회 추가 이동
                ret = max(ret, 1 + DFS(ny, nx, k));
                MAP[ny][nx] = tmp; 
                V[ny][nx] = 0;
                k = K;
            }
            else continue;
        }
        else {
            V[ny][nx] = 1;
            ret = max(ret, 1 + DFS(ny, nx, k));
            V[ny][nx] = 0;
        }
    }
    return ret;
}

int main() {
    // 테스트 케이스 개수
    scanf("%d", &T);
    // 지도 크기 전까지 이동하면
    //while (++t <= T) {
    for (int t = 0; t < T; t++) {
        int i, j, max_height = 0, ret = 0;
        scanf("%d %d", &N, &K);
        // MAP이 가리키는 메모리를 sizeof(MAP)만큼 0으로 설정
        memset(MAP, 0, sizeof(MAP));
        memset(V, 0, sizeof(V));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &MAP[i][j]);
                if (max_height < MAP[i][j])
                    max_height = MAP[i][j];
            }
        }
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                // 등산 처음 위치
                if (MAP[i][j] == max_height) {
                    V[i][j] = 1;
                    ret = max(ret, DFS(i, j, K));
                    V[i][j] = 0;
                }
            }
        }
        printf("#%d %d\n", t+1, ret);
    }
}


//////////////////////////////
// ver.2
/*
 hjung3113
제출일 : 2019-04-14 02:20

#include <stdio.h>
struct object { int row, col; };
struct object peak[5];
int map[8][8], visited[8][8], max_len, N, K, num_peak;
int dd[2][4] = { {0,1,0,-1},{1,0,-1,0} };
void make_trail(int cr, int cc, int ch, int len, int dig)
{
    if (len > max_len) max_len = len;
    register int nr, nc, dir;
    for (dir = 0; dir < 4; ++dir)
    {
        nr = cr + dd[0][dir], nc = cc + dd[1][dir];
        if (visited[nr][nc] || map[nr][nc] >= ch || nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        visited[nr][nc] = 1;
        make_trail(nr, nc, map[nr][nc], len + 1, dig);
        visited[nr][nc] = 0;
    }
    if (!dig)
        for (dir = 0; dir < 4; ++dir)
        {
            nr = cr + dd[0][dir], nc = cc + dd[1][dir];
            if (ch <= map[nr][nc]-K ||map[nr][nc] < ch || visited[nr][nc] || nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                visited[nr][nc] = 1;
                make_trail(nr, nc, ch-1, len + 1, 1);
                visited[nr][nc] = 0;
        }
}
int main(void)
{
    int T;
    register int t, i, j, top;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        num_peak = top = max_len = 0;
        scanf("%d %d", &N, &K);
        for (i = 0; i < N; ++i) 
            for (j = 0; j < N; ++j)
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] > top)
                {
                    num_peak = 0, top = map[i][j];
                    peak[num_peak].row = i; 
                    peak[num_peak++].col = j;
                }
                else if (map[i][j] == top)
                {
                    peak[num_peak].row = i;
                    peak[num_peak++].col = j;
                }
            }
        for (i = 0; i < num_peak; ++i)
        {
            visited[peak[i].row][peak[i].col] = 1;
            make_trail(peak[i].row, peak[i].col, top, 1, 0);
            visited[peak[i].row][peak[i].col] = 0;
        }
        printf("#%d %d\n", t, max_len);
    }
    return 0;
}
*/

//////////////////////////////
// ver.1
/*
#include <stdio.h>
int N, K, map[10][10], visited[10][10], ans;
int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
void dfs(int x, int y, int e, int n) {
    if (ans < n) ans = n;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i], t = -1;
        if (tx < 0 || ty < 0 || tx >= N || ty >= N || visited[tx][ty]) continue;
        if (e >= 0) {
            if (e > map[tx][ty]) t = -2;
            else continue;
        }
        else if (map[x][y] <= map[tx][ty] && e == -1 && map[tx][ty] - map[x][y] < K) t = map[x][y] - 1;
        else if (map[tx][ty] >= map[x][y]) continue;
        visited[tx][ty] = 1;
        if (t == -1) dfs(tx, ty, e, n + 1);
        else dfs(tx, ty, t, n + 1);
        visited[tx][ty] = 0;
    }
}

int main(void) {
    int test_case, T;
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d", &N, &K);
        int i, j, max = 0;
        ans = 0;
        for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (max < map[i][j]) max = map[i][j];
        }
        for (i = 0; i < N; i++) for (j = 0; j < N; j++) if (max == map[i][j]) {
            visited[i][j] = 1;
            dfs(i, j, -1, 1);
            visited[i][j] = 0;
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
*/