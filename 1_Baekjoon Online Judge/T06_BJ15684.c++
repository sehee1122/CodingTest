// 입력을 처리해서 어떻게 사다리를 표현?
// 입력된 사다리를 가지고 결과를 어떻게 체크할 수 있을까?
// 추가할 수 있는 최대 사다리가 3개 뿐이 없기 때문에, 다 해보면 된다.

#include <stdio.h>

// N: 세로선의 개수, M: 가로선의 개수, H: 놓을 수 있는 위치의 개수
int n, m, h, ret;
int map[31][11];
 
bool check() {
    bool ret = true;
 
    for (int i = 1; i <= n; ++i) {
        int pos = i;
 
        for (int j = 0; j <= h; ++j) {
            if (map[j][pos] == 1) {
                ++pos;
            }
            else if (map[j][pos - 1] == 1) {
                --pos;
            }
        }
 
        if (pos != i) {
            return ret = false;
        }
    }
    return ret;
}
 
void dfs(int count, int y, int x) {
    if (count >= ret)    return;
    if (check()) {
        ret = count;
        return;
    }
    // 정답이 3보다 큰 값이면 -1 출력, 불가능한 경우도 -1 출력
    // 아무것도 반환하지 않는 return; - 단지 함수를 종료시키기 위함
    if (count == 3) return;
    for (int i = y; i <= h; ++i) {
        for (int j = x; j < n; ++j) {
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
                map[i][j] = 1;
                dfs(count + 1, i, j);
                map[i][j] = 0;
            }
        }
        x = 1;
    }
}
 
int main() {
    scanf("%d %d %d", &n, &m, &h);
    // a - row: 행, b - column: 열
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    // 사다리를 놓는 횟수
    ret = 4;
    dfs(0, 1, 1);
    if (ret == 4)   ret = -1;
    printf("%d\n", ret);
    return 0;
}
