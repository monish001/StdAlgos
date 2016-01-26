//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//For example:
//Given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//For this problem, return the maximum sum.

#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
using namespace std;

#define ll long long
#define pii pair<int,int>

// O(n3) solution
int Solution1(const vector<int> &A){
    int maxSum = INT_MIN, len = A.size();
    //for each sub_array_size
    for(int sub_array_size = 1; sub_array_size <= len; sub_array_size++){
        //for each start_index x
        for(int start_index=0; start_index<len; start_index++){
            // if end index exceeds array size, break loop
            int end_index = start_index + sub_array_size - 1;
            if(end_index >= len){
                break;
            }

            // find sum from index x to index x+sub_arry_size-1
            // and put max of sum, maxSum in maxSum
            int sum = 0;
            for(int index = start_index; index<=end_index; index++){
                sum += A[index];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
// O(n2) solution
int Solution2(const vector<int> &A){
    int maxSum = INT_MIN, len = A.size();
    //vector<vector<int>> mat(vector<int>(INT_MIN, len), len);
    //for each sub_array_size
    for(int start_index=0; start_index<len; start_index++){
        //for each start_index x
        int curSum = 0;
        for(int sub_array_size = 1; sub_array_size <= len; sub_array_size++){
            // if end index exceeds array size, break loop
            int end_index = start_index + sub_array_size - 1;
            if(end_index >= len){
                break;
            }

            curSum += A[end_index];

            // find sum from index x to index x+sub_arry_size-1
            // and put max of sum, maxSum in maxSum
            maxSum = max(maxSum, curSum);
        }
    }
    return maxSum;
}
int main()
{
    //Given the array [-2,1,-3,4,-1,2,1,-5,4],
    //the contiguous subarray [4,-1,2,1] has the largest sum = 6.


    static const int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    cout << Solution1(vec) << endl;
    cout<< Solution2(vec) << endl;
    return 0;
}
