//Find length of Longest Increasing Subsequence
//Running Time O(n*n) where n is the length of given list of numbers.
#include<vector>
#include<iostream>
using namespace std;

int LIS(vector<int> list)
{
	vector<int> lisLen(list.size(), 1);//lisLen[i] gives length of LIS in list[0, i].
	for(unsigned index = 0; index<list.size(); index++)
	{
		for(unsigned innerIndex=0; innerIndex<index; innerIndex++)
		{
			if(lisLen[index] < 1+lisLen[innerIndex] && list[index]>list[innerIndex])
				lisLen[index] = lisLen[innerIndex]+1;
		}
	}
	
	// for(unsigned index = 0; index<list.size(); index++)
		// cout<<lisLen[index]<<"; ";
	// cout<<endl;
	
	int maxLIS = 0;
	for(unsigned index = 0; index<list.size(); index++)
		maxLIS = max(maxLIS, lisLen[index]);
	
	return maxLIS;
}

int main(){
	vector<int> list;
	list.push_back(9);
	list.push_back(8);
	list.push_back(1);
	list.push_back(5);	
	list.push_back(2);
	list.push_back(6);
	list.push_back(4);
	list.push_back(0);

	cout<<LIS(list);

	return 0;
}
