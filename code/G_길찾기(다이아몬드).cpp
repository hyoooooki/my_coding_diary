#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int main() {
	int a;
	int arr[100][100];
	int visit[100][100];
	int temp;
	int r=0;
	int c=0;
	bool chk=false;
	
	cin >> a;
	
	for(int i=0;i<=(a-1);i++)
	{
		r=i;
		c=0;
		for(int j=0;j<=i;j++)
		{
			cin>>arr[r-j][c+j];
		}
	}
	
	int bias=1;
	for(int i=a-1;0<i;i--)
	{
		r=a-1;
		c=bias;
		for(int j=i;0<j;j--)
		{
			cin>>arr[r][c];
			r=r-1;
			c=c+1;
		}
		bias++;
	}
	
	queue<pair<int,int>> q;
	int i_r=0;
	int i_c=0;
	int c_r,c_c;
	int dr[2]={0,1};
	int dc[2]={1,0};
	int nr;
	int nc;
	int currblock=0;
	
	currblock=arr[i_r][i_c];
	q.push({i_r,i_c});
	visit[i_r][i_c]=currblock;
	
	while(!q.empty())
	{
		c_r=q.front().first;
		c_c=q.front().second;
		q.pop();
		
		for(int i=0;i<2;i++)
		{
			nr=c_r+dr[i];
			nc=c_c+dc[i];
			if( nr<0 || nc<0 || a<=nr || a<=nc)
				continue;
			
			if(visit[nr][nc]!=0)
			{
				if(visit[nr][nc] < arr[nr][nc]+visit[c_r][c_c])
				{
					visit[nr][nc] = arr[nr][nc]+visit[c_r][c_c];
					q.push({nr,nc});	
				}
			}
			else
			{
				visit[nr][nc] = arr[nr][nc]+visit[c_r][c_c];
				q.push({nr,nc});
			}
		}
	}
	
// 	for(int i=0;i<a;i++)
// 	{
// 		for(int j=0;j<a;j++)
// 		{
// 			cout << visit[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
	
	
	cout << visit[a-1][a-1] << endl;
	return 0;
	
}