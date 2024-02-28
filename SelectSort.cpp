#include <iostream>
using namespace std;

void printingValues (double* arr, int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] <<" ";	
	}
	cout << endl;
}

int main (int argc, char* argv[]) {
	int length = argc -1;
	double vec[length];
	if(argc <= 2){
		cout << "Too few elements for sorting"<<endl;
		return 0;
	}else{
		int j = 1;
		for (int i = 0; i < length; i++){
			vec[i] = stod(argv[j]);
			j = j + 1;
		}
	}
	
	for(int i = 0; i < length-1; i++) {
		printingValues(vec,length);
		int j = i + 1;
		while (j < length) {
			if (vec[j] < vec[i]){
				int key = vec[i];
				vec[i] = vec[j];
				vec[j] = key;
			}
			j = j + 1;  
		}
	} 
	printingValues (vec,  length);
	return 0;
}
