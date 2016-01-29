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

vector<int> maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ll maxSum = 0,
        resultStartIndex = INT_MAX,
        resultEndIndex = INT_MAX,
        len = A.size();
    for(int size = 1; size <= len; size++){
        for(int startIndex = 0; startIndex<len; startIndex++){
            int endIndex = startIndex + size - 1;
            if(endIndex >= len){
                break;
            }
            ll curSum = 0;
            bool skip = false;
            for(int index = startIndex; index<=endIndex; index++){
                if(A[index]<0){
                    skip = true;
                    break;
                }
                curSum += A[index];
            }
            if(skip==true){
            }else if(
                (maxSum < curSum) ||
                (maxSum == curSum && endIndex-startIndex > resultEndIndex-resultStartIndex) ||
                (maxSum == curSum && endIndex-startIndex == resultEndIndex-resultStartIndex && startIndex < resultStartIndex)
            ){
                maxSum = curSum;
                resultStartIndex = startIndex;
                resultEndIndex = endIndex;
            }
        }
    }

    vector<int> result;
    if(resultStartIndex!=INT_MAX && resultEndIndex!=INT_MAX){
        for(int index = resultStartIndex; index<=resultEndIndex; index++){
            result.push_back(A[index]);
        }
    }
    return result;
}

int main()
{
    vector<int> vec;
    vec.push_back(1967513926);
    vec.push_back(1540383426);
    vec.push_back(-1303455736);
    vec.push_back(-521595368);
    /*vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(-7);
    vec.push_back(2);
    vec.push_back(3);
    */
    vector<int> result = maxset(vec);
    for(int i=0; i<result.size(); i++){
        cout<<vec[i]<<"\t";
    }
    return 0;
}
