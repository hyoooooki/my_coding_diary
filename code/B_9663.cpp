#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int rst=0;
int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
int dc[8] = { 1,1,0,-1,-1,-1,0,1 };

bool chk(int i, int j)
{
	if (i < N && 0 <= i && j < N && 0 <= j)
	{
		return true;
	}
	return false;
}

void dfs(int t_arr[][15], int r, int c, int cnt)
{
	int t_r = r;
	int t_c = c;
	int f_r = r;
	int f_c = c;
	int arr[15][15] = { 0 };
	int t_cnt = cnt;
	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			arr[i][j] = t_arr[i][j];
		}
	}

	if (t_cnt == N)
	{
		rst++;
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		t_r = t_r + dr[i];
		t_c = t_c + dc[i];
		while (chk(t_r, t_c))
		{
			if (arr[t_r][t_c] == 0)
			{
				arr[t_r][t_c] = 2;
			}
			t_r = t_r + dr[i];
			t_c = t_c + dc[i];
		}
		t_r = f_r;
		t_c = f_c;
	}


	for (int i = 0; i < N; i++)
	{
		if (chk(t_r + 1, i))
		{
			if (arr[t_r + 1][i] == 0)
			{
				arr[t_r + 1][i] = 1;
				dfs(arr, t_r + 1, i, t_cnt+1);
				arr[t_r + 1][i] = 0;
			}
		}
	}

	if(t_cnt != N)
		return;
}

int main()
{
	ios::sync_with_stdio(false);
	int arr[15][15] = { 0 };
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		arr[0][i] = 1;
		dfs(arr,0,i,1);
		arr[0][i] = 0;
	}

	cout << rst << endl;

	return 0;
}