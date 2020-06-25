#include <iostream>
#include <vector>

using namespace std;

int rst=0;
int cnt=0;
int arr[100];
int a;

void dfs(int n1,int n2,int loc)
{
	int sumval= n1+n2;
	int difval= n1-n2;
	
	if(loc==a-1)
	{
		if(sumval == rst)
			cnt++;
	
		if(difval == rst)
			cnt++;
		
		return;
	}
	
	if(20 < sumval && 20 < difval)
		return;
	
	if(sumval<=20)
		dfs(sumval,arr[loc],loc+1);
	
	if(difval<=20 && 0<=difval)
		dfs(difval,arr[loc],loc+1);
	
	return;
}



int main() {
	cin >> a;
	
	for(int i=0;i<a-1;i++)
	{
		cin >> arr[i];
	}
	cin >> rst;
	
	dfs(arr[0],arr[1],2);	
	
	
	cout << cnt << endl;
	
	return 0;
}