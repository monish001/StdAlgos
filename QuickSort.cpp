#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

#define ll long long
#define pii pair<int,int>
//HeapSort in C++
class Sort{
	static void swap(int& a, int& b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	int partition(int* a, int s, int e){
		int p = s + (e-s)/2;
		swap(a[p], a[s]);
		for(int i=s+1; i<=e;){
			if(a[s] > [i])
				i++;
			else
				swap(a[i], a[e--]);
		}
		swap(a[s], a[e]);
		return e;
	}
public:
	static void QuickSortAscending(int* a, int s, int e){
		if(e<=s)
			return;
		int p = partition(a, s, e);
		if(p-s > 1)
			QuickSortAscending(a, s, p-1);
		else
			QuickSortAscending(a, p+1, e);
	}
};
int main(){
	int a[] = {9,8,1,5,2,6,4,0};
	Sort::QuickSortAscending(a, 8);
	for(int i=0; i<8; i++)
		cout<<" "<<a[i];
	return 0;
}
