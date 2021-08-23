//
// Problem statement :
// find the pair of two numbers which makes the sum 
// 'x'.
//

// A. bruteforce approach

// Arr = [10, 5, 2, 3, -6, 9, 11]
// take 10 and sum with each number on left
// take 5 and sum with each number on left
// and so on.
// complexity --> N * N = O(N^2)
// Two for loops. 0-N and internal will have 0-(N-1)

// B. Search and binary search

// Take one number, and do binary search on left side
// this will have complexity 
// = sorting + finding
// = NlogN + NlogN
// = 2NlogN = O(NlogN)

// C. use set datastructure.

// Take the number and add check compliment in set
// if found, return, else add to set
// keep it up until right pair found.
// = N (iterating) + O(1) (finding compliemnt)
// = O(N)


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int sum){

	vector<int> result;
	unordered_set<int> set;

	for(int n=0; n<arr.size(); n++){
		int find_nr = sum - arr[n];
		if(set.find(find_nr) != set.end()){
			cout<<"Pair found"<<endl;
			result.push_back(find_nr);
			result.push_back(arr[n]);
			return result;
		}
		else{
			set.insert(arr[n]);
		}
	}
	return result;
}


int main(){
	vector<int> arr{10, 5, 2, 3, -6, 9, 11};
	int sum = 4;

	auto ret = pairSum(arr, sum);
	if (ret.size() == 0){
		cout << "No such pair found" << endl;
	}
	else{
		cout << ret[0] << "," << ret[1] << endl;
	}
}