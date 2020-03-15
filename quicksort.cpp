#include <iostream>
#include <cstdio> 
#include <vector>
#include <time.h> 
#include<fstream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(vector<int>&arr, int front, int end){
    int pivot = arr[front];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

int Partition_med(vector<int>&arr, int front, int end){
	int median, a = arr[front], b = arr[(front+end)/2], c = arr[end];
	if( a >= b && b >= c || a <= b && b <= c)
		median = b;
	else if ( a >= c && c >= b || a <= c && c <= b )
		median = c;
	else median = a;
	int pivot = median;
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void QuickSort(vector<int>& arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
		QuickSort(arr, pivot + 1, end);
		QuickSort(arr, front, pivot - 1);
    }
}

void QuickSort_med(vector<int>& arr, int front, int end){
    if (front < end) {
        int pivot = Partition_med(arr, front, end);
		QuickSort_med(arr, pivot + 1, end);
		QuickSort_med(arr, front, pivot - 1);
    }
}

void QuickSort_LF(vector<int>& arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        if( pivot >= arr.size()/2 ){
        	QuickSort_LF(arr, front, pivot - 1);
        	QuickSort_LF(arr, pivot + 1, end);
		}
		else if( pivot < arr.size()/2 ){
			QuickSort_LF(arr, pivot + 1, end);
			QuickSort_LF(arr, front, pivot - 1);
		}
    }
}

void QuickSort_LF_med(vector<int>& arr, int front, int end){
    if (front < end) {
        int pivot = Partition_med(arr, front, end);
        if( pivot >= arr.size()/2 ){
        	QuickSort_LF_med(arr, front, pivot - 1);
        	QuickSort_LF_med(arr, pivot + 1, end);
		}
		else if( pivot < arr.size()/2 ){
			QuickSort_LF_med(arr, pivot + 1, end);
			QuickSort_LF_med(arr, front, pivot - 1);
		}
    }
}

void QuickSort_SF(vector<int>& arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        if( pivot <= arr.size()/2 ){
        	QuickSort_SF(arr, front, pivot - 1);
        	QuickSort_SF(arr, pivot + 1, end);
		}
		else if( pivot > arr.size()/2 ){
			QuickSort_SF(arr, pivot + 1, end);
			QuickSort_SF(arr, front, pivot - 1);
		}
    }
}

void QuickSort_SF_med(vector<int>& arr, int front, int end){
    if (front < end) {
        int pivot = Partition_med(arr, front, end);
        if( pivot <= arr.size()/2 ){
        	QuickSort_SF_med(arr, front, pivot - 1);
        	QuickSort_SF_med(arr, pivot + 1, end);
		}
		else if( pivot > arr.size()/2 ){
			QuickSort_SF_med(arr, pivot + 1, end);
			QuickSort_SF_med(arr, front, pivot - 1);
		}
    }
}

int main(int argc, char** argv) {
	//original quick
	vector<int> quick;
	
	fstream fp;
	int element, x = 0;
	fp.open("test.txt", ios::in);
	if(!fp) {
	   cerr << "Failed opening" << endl;
	   exit(1);
  	 }
  	while(fp >> element)
  		quick.push_back(element);
  		
  	fp.close();
	
	clock_t start, end; 
	double cpu_time_used; 
	start = clock(); 
	
	QuickSort(quick, 0, quick.size()-1);
	
	end = clock();
  	// calculate total cost time 
 	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    printf("use leftmost and original execution time = %f\n", cpu_time_used); 
    cout << quick.size() << endl;
    
    /*/original quick median
    
    vector<int> quick_med;

	fp.open("test.txt", ios::in);
	if(!fp) {
	   cerr << "Failed opening" << endl;
	   exit(1);
  	 }
  	//int element;
  	while(fp >> element)
  		quick_med.push_back(element);
  		
  	fp.close();
  	
    clock_t start_med, end_med; 
	//double cpu_time_used; 
	start_med = clock(); 
	
	QuickSort_med(quick_med, 0, quick_med.size()-1);
	
	end_med = clock();
  	// calculate total cost time 
 	cpu_time_used = ((double) (end_med - start_med)) / CLOCKS_PER_SEC; 
    printf("use median of three and originl execution time = %f\n", cpu_time_used); 
    cout << quick_med.size() << endl;*/
    
    /*/long first
    
    vector<int> quick_LF;

	fp.open("test.txt", ios::in);
	if(!fp) {
	   cerr << "Failed opening" << endl;
	   exit(1);
  	 }
  	//int element;
  	while(fp >> element)
  		quick_LF.push_back(element);
  		
  	fp.close();
  	
    clock_t start_L, end_L; 
	//double cpu_time_used; 
	start_L = clock(); 
	
	QuickSort_LF(quick, 0, quick.size()-1);
	
	end_L = clock();
  	// calculate total cost time 
 	cpu_time_used = ((double) (end_L - start_L)) / CLOCKS_PER_SEC; 
    printf("use leftmost and Longer fisrt execution time = %f\n", cpu_time_used); 
    cout << quick_LF.size() << endl;*/
    
    //longer first median
    
    vector<int> quick_LF_med;

	fp.open("test.txt", ios::in);
	if(!fp) {
	   cerr << "Failed opening" << endl;
	   exit(1);
  	 }
  	//int element;
  	while(fp >> element)
  		quick_LF_med.push_back(element);
  		
  	fp.close();
  	
    clock_t start_L_med, end_L_med; 
	//double cpu_time_used; 
	start_L_med = clock(); 
	
	QuickSort_LF_med(quick, 0, quick.size()-1);
	
	end_L_med = clock();
  	// calculate total cost time 
 	cpu_time_used = ((double) (end_L_med - start_L_med)) / CLOCKS_PER_SEC; 
    printf("use median of three and Longer fisrt execution time = %f\n", cpu_time_used); 
    cout << quick_LF_med.size() << endl;
    
    /*/ shorter fisrt
    
    vector<int> quick_SF;
    
	fp.open("test.txt", ios::in);
	if(!fp) {
	   cerr << "Failed opening" << endl;
	   exit(1);
  	 }
  	//int element;
  	while(fp >> element)
  		quick_SF.push_back(element);
  		
  	fp.close();
  	
    clock_t start_S, end_S; 
	//double cpu_time_used; 
	start_S = clock(); 
	
	QuickSort_SF(quick, 0, quick.size()-1);
	
	end_S = clock();
  	// calculate total cost time 
 	cpu_time_used = ((double) (end_S - start_S)) / CLOCKS_PER_SEC; 
    printf("use leftmost and shorter fisrt execution time = %f\n", cpu_time_used); 
    cout << quick_SF.size() << endl;*/
    
    /*/ shorter fisrt median
    
    vector<int> quick_SF_med;

	fp.open("test.txt", ios::in);
	if(!fp) {
	   cerr << "Failed opening" << endl;
	   exit(1);
  	 }
  	//int element;
  	while(fp >> element)
  		quick_SF_med.push_back(element);
  		
  	fp.close();
  	
    clock_t start_S_med, end_S_med; 
	//double cpu_time_used; 
	start_S_med = clock(); 
	
	QuickSort_SF_med(quick_SF_med, 0, quick_SF_med.size()-1);
	
	end_S_med = clock();
  	// calculate total cost time 
 	cpu_time_used = ((double) (end_S_med - start_S_med)) / CLOCKS_PER_SEC; 
    printf("use median of three and shorter fisrt execution time = %f\n", cpu_time_used); 
    cout << quick_SF_med.size() << endl;*/
    
	return 0;
}
