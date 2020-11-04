#include <stdio.h>
int N,max;
 
int map[501][501];
int visit[501][501];
int rank[1001];
int vectX[4] = { 0,0,1,-1 };
int vectY[4] = { 1,-1,0,0 };
int count;
int dfs(int stx, int sty)
{
    int i, j;
    int x, y, nextX, nextY;
    x = stx;
    y = sty;
    for (i = 0; i < 4; i++)
    {
        nextX = x + vectX[i];
        nextY = y + vectY[i];
        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
        {
            if (map[nextX][nextY] == 1 && visit[nextX][nextY]==0)
            {
                count++;
                visit[nextX][nextY] =count;
                dfs(nextX, nextY);
            }
            if (max < visit[x][y])
            {
                max = visit[x][y];
            }    
        }
    }
    return max;
}
 
int main()
{
    int i, j,index;
    index = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);
    
    for(i=0;i<N;i++){
        for (j = 0; j < N; j++)
        {
            if (visit[i][j] != 0 || map[i][j] == 0)
                continue;
            if (map[i][j] == 1 && visit[i][j] == 0){
                count = 1; max = 0; visit[i][j] = 1;
                int val = dfs(i, j);
                rank[++index] = val;
            }
        }
    }
    for(i=1;i<=index;i++)
        for (j = i; j <= index; j++)
        {
            if (rank[i] == 0)
                continue;
            if (rank[j] < rank[i])
            {
                int temp = rank[i];
                rank[i] = rank[j];
                rank[j] = temp;
            }
        }
    printf("%d\n", index);
    for (i = 1; i <= index; i++) {
        printf("%d ", rank[i]);
    }
}


/*
#include <iostream>
#include <sstream>

using namespace std;

void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.

}

struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.sizeOfMatrix;

  inputData.matrix = new int*[inputData.sizeOfMatrix];
  for (int i = 0; i < inputData.sizeOfMatrix; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.matrix[i] = new int[inputData.sizeOfMatrix];
    for (int j = 0; j < inputData.sizeOfMatrix; j++) {
      iss >> inputData.matrix[i][j];
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}
*/


//////////////////// Testcase1 ////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int xsize, ysize, cnt;
int arr[100][100] = {};
bool visit[100][100] = {};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
void dfs(int x,int y) {
   cnt++;
   for (int i = 0; i < 4; i++) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if (nx >= 0 && ny >= 0 && nx < xsize && ny < ysize) {
         if ((!visit[nx][ny]) && (arr[nx][ny] == 0)) {
            visit[nx][ny] = 1;
            dfs(nx, ny);
         }
      }
   }
}
int main() {
   int t;
   vector<int> v;
   cin >> xsize >> ysize >> t;

   while (t--) {
      int sx, sy, ex, ey;
      cin >> sy >> sx >> ey >> ex;

      for (int i = sx; i < ex; i++) {
         for (int j = sy; j < ey; j++) {
            arr[i][j] = 1;
         }
      }   
   }
   for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
         if (!arr[i][j] && !visit[i][j]){
            visit[i][j] = 1;
            dfs(i, j);
            v.push_back(cnt);
            cnt = 0;
         }
      }
   }
   sort(v.begin(), v.end());
   cout << v.size() << '\n';
   for (int i = 0; i < v.size(); i++) {
      cout << v[i] << ' ';
   }
}


//////////////////// Testcase2 ////////////////////
 
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int dy[] = {0,1,-1,0};
int dx[] = {1,0,0,-1};

int cnt = 0;
vector<int> ans;

void bfs(int i, int j, int sizeOfMatrix, int **matrix){
   
   queue<pair<int,int>> q;
   int size = 1;
   matrix[i][j] = 0;
   q.push({i,j});
   while(!q.empty()){
      pair<int,int> cur = q.front();
      q.pop();
      for(int z = 0; z<4 ;z++){
         int ny = cur.first + dy[z];
         int nx = cur.second + dx[z];
         if(ny < 0 || nx < 0 || ny >= sizeOfMatrix || sizeOfMatrix <= nx || matrix[ny][nx] == 0) continue;
         size++;
         matrix[ny][nx] = 0;
         q.push({ny,nx});
      }
   }
   ans.push_back(size);
}

void solution(int sizeOfMatrix, int **matrix) {
   for(int i = 0; i < sizeOfMatrix; i++){
         for(int j = 0; j < sizeOfMatrix; j++){
         if(matrix[i][j] == 1){
            bfs(i, j, sizeOfMatrix, matrix);
            cnt++;
         }   
      }
   }
   cout << cnt << endl;
   sort(ans.begin(), ans.end());
   for(long unsigned int i = 0; i < ans.size(); i++){
      cout << ans[i] << ' ';
   }
}


//////////////////// Testcase3 ////////////////////

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> visited;
vector<int> each_size;
void check_in(const int cur_y, const int cur_x, int& cur_size, int **matrix)
{
   if(cur_y < 0 || cur_x < 0 || cur_y >= visited.size() || cur_x >= visited.size()) return;
   if(visited[cur_y][cur_x] || matrix[cur_y][cur_x] == 0) return;
   visited[cur_y][cur_x] = true;
   cur_size++;
   check_in(cur_y, cur_x - 1, cur_size, matrix);
   check_in(cur_y, cur_x + 1, cur_size, matrix);
   check_in(cur_y - 1, cur_x, cur_size, matrix);
   check_in(cur_y + 1, cur_x, cur_size, matrix);
}
void check_size(const int& start_y, const int& start_x, int **matrix)
{
   int size = 0;
   check_in(start_y, start_x, size, matrix);
   each_size.push_back(size);
}
void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.
   visited = vector<vector<bool>>(sizeOfMatrix, vector<bool>(sizeOfMatrix, false));
   each_size = vector<int>();
   int cnt = 0;
   for(int y=0; y<sizeOfMatrix; y++)
   {
      for(int x=0; x<sizeOfMatrix; x++)
      {
         if(matrix[y][x] == 1 && !visited[y][x])
         {
            cnt++;
            check_size(y, x, matrix);
         }
      }
   }
   sort(each_size.begin(), each_size.end());
   cout << cnt << "\n";
   for(int i = 0; i < each_size.size(); i++)
   {
      cout << each_size[i];
      if(i != each_size.size() - 1) cout << " ";
      else cout << "\n";
   }
}

