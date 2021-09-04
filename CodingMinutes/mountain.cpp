//
// Problem statement :
// find the highest mountain length.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find_mountain(vector<int> arr){

	vector<int> result;
	int largest = 0;
	int cnt = 0;

	for(int i = 1; i< (arr.size() - 1); i++)
	{
		//find peak
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){

			cout<<"peak found at i = "<<i<<" arr[i] = "<<arr[i]<<endl;

			int j = i;
			// find backward length
			for( ; j>0 && (arr[j]>arr[j-1]); j++){
				cnt++;
			}
			//find forward length
			for( ;arr[i]>arr[i+1]; i++){
				cnt++;
			}
			largest = max(largest, cnt);
		}
	}
	return largest;
}


int main(){

	vector<int> arr{10, 5, 6, 2, 3, 4, 5, 0, -6, -7, -9, 11};
	auto largest = find_mountain(arr);
	cout << "largest mountain " << largest << endl;

}