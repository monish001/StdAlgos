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
	static void MaxHeapSiftDown(int* a, int index, int n){
		int root = index;
		int child = 2*root + 1;//index for left child
		while(child<n){
			if(child+1<n && a[child+1]>a[child])
				child++;
			if(a[root]>a[child])
				return;
			swap(a[root], a[child]);
			root = child;
			child = 2 * root +1;
		}
	}
	static void MaxHeapify(int* a, int n){
		for(int index = n-1; index>0; index--)//init with lesser value
		{
			MaxHeapSiftDown(a, index, n);
		}
	}
	static void swap(int& a, int& b){
		int tmp = a;
		a = b;
		b = tmp;
	}
public:
	static void HeapSortAscending(int* a, int n){
		MaxHeapify(a, n);
		for(int index=n-1; index>0; index--){
			swap(a[index], a[0]);
			MaxHeapSiftDown(a, 0, index);
		}
	}
};
int main(){
	int a[] = {9,8,1,5,2,6,4,0};
	Sort::HeapSortAscending(a, 8);
	for(int i=0; i<8; i++)
		cout<<" "<<a[i];
	return 0;
}
