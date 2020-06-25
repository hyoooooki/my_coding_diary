#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> arr(a+1,0);
	vector<int> block(c,0);
	
	for(int i=0;i<b;i++)
	{
		int t1,t2;
		cin >> t1 >> t2;
		arr[t1] = t2;
	}
	for(int i=0;i<c;i++)
	{
		int t3;
		cin >> t3;
		block[i]= t3;
	}
	
	int push_block=0;
	int temp;
	int count=0;
	
	for(int i=0;i<c;i++)
	{
		push_block=block[i];
		while(1)
		{
			if(arr[push_block] > 0)
			{
				temp = arr[push_block];
				arr[push_block]=-1;
				push_block = temp;
				count++;
			}
			else if(arr[push_block] == 0)
			{
				count++;
				break;
			}
			else
			{
				break;
			}
		}
	}
	
		cout << count << endl;
	
	
	return 0;
}