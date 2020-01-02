#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;
char map[51][51];
int dp[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

string etc = "KAKTUS";

int main()
{
    cin >> N >> M;
    vector<string> _map;
    queue< pair<int, int> > nextwq;
    int startX, startY;
    int endX, endY;
    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        _map.push_back(s);
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            map[i][j] = _map[i][j];
            if(map[i][j] == 'D')
            {
                endX = i; endY = j;
            }
            else if(map[i][j] == 'S')
            {
                map[i][j] = '.';
                startX = i; startY = j;
            }
            else if(map[i][j] == '*')
            {
                nextwq.push(make_pair(i, j));
            }
        }
    }

    queue< pair<int, int> > wq;
    queue< pair<int, int> > emp;

    queue< pair<int, int> > q;
    queue< pair<int, int> > nextq;
    nextq.push(make_pair(startX, startY));
    dp[startX][startY] = 0;

    bool ok = false;
    int ans = 0;
    while (!nextq.empty())
    {
        wq = nextwq;
        nextwq = emp;
        while(!wq.empty())
        {
            int wx = wq.front().first;
            int wy = wq.front().second;
            wq.pop();

            for(int k=0; k<4; k++)
            {
                int wnx = wx + dx[k];
                int wny = wy + dy[k];
                if(wnx < 0 || wnx >= N || wny < 0 || wny >= M) continue;

                if(map[wnx][wny] == '.')
                {
                    map[wnx][wny] = '*';
                    nextwq.push(make_pair(wnx, wny));
                }
            }
        }

        q = nextq;
        nextq = emp;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if(map[nx][ny] == '.' && dp[nx][ny] == 0)
                {
                    dp[nx][ny] = dp[x][y] + 1;
                    nextq.push(make_pair(nx, ny));
                }

                if(map[nx][ny] == 'D' && dp[nx][ny] == 0)
                {
                    ok = true;
                    ans = dp[x][y] + 1;
                }
            }
        }

        if(ok)
            break;
    }

    if(ans == 0)
        cout << etc << endl;
    else
        cout << ans << endl;

    return 0;
<<<<<<< HEAD
}
//
=======
}
>>>>>>> 4c8fb4ccc75c0a5433294a42cb31d9f1528400bf
