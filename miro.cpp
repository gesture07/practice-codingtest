//미로 탈출
#include <bits/stdc++.h>

using namespace std;


int N, M;
int graph[201][201];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (graph[nx][ny] == 0)
				continue;

			if (graph[nx][ny] == 1) {
				graph[nx][ny] == graph[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return graph[N - 1][M - 1];
}


int main() {

	

	//cout << "N(4<=N)과 M(M<=200)을 입력하시오: " << endl;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	cout << bfs(0, 0) << endl;
	return 0;
}