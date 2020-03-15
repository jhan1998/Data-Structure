#include <iostream>
#include<cstdlib>
#include <sstream> 
#include <vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef  struct{
	unsigned long int key;
} element;
element *heap = new element[1000001];
long int heap_size = 0;

bool heap_full(unsigned long int size){
	if( size > 1000000 )
		return true;
	else return false;
}

void heap_push( element item, long int &size ){
	unsigned long int i;
	if( heap_full(size) ){
		cout << "The heap is full" << endl;
		exit(EXIT_FAILURE);
	}
	i = ++size;
	while( ( i != 1 ) && ( item.key > (*( heap + i/2 )).key ) ){
		*( heap + i ) = *( heap + i/2 );
		i /= 2;
	}
	*( heap + i ) = item;
}
void heap_sort(){
	element item;
	for( long int i = 1 ; i < 2 ; i++ ){
		item = *( heap + i );
		long int parent = i;
		long int child = i*2;
		while( child <= heap_size ){
			if( child < heap_size && ( (*( heap + child )).key < (*( heap + child + 1 )).key ) )
				child++;
			if( item.key > (*( heap + child )).key ) break;
			*( heap + parent ) = *( heap + child );
			parent = child;
			child *= 2;
		}
		*( heap + parent ) = item;
	}
}

int main() {
	string x;
	int turn = 0;
	cin >> x;
	stringstream change(x);
	change >> turn;
	cout << endl;
	vector<unsigned long long int> ans;
	while( turn > 0 ){
		unsigned long int row, person;
		int count = 0;
		string input;
		while( cin >> input ){
			stringstream change(input);
			if( count == 0 )
				change >> row;
			else change >> person;
			count++;
			if( cin.get() == '\n')
			break;
		}
		cout << endl;
		string num;
		unsigned long long int ans_count = 0;
		for( long int i = 0 ; i < row ; i++){
			cin >> num;
			stringstream change(num);
			element item;
			change >> item.key;
			heap_push( item, heap_size );
		}
		cout << endl;
		for( long int i = 0 ; i < person ; i++ ){
			ans_count += (*( heap + 1 )).key;
			-- (*( heap + 1 )).key;
			heap_sort();
			if( (*( heap + 1 )).key == 0 ){
				continue;
			}
		}
		ans.push_back(ans_count);
		turn -= 1;
		for( long int i = 1 ; i < row + 1 ; i++ ){
			element non;
			*( heap + i ) = non;
			--heap_size;
		}
	}
	for( int i = 0 ; i < ans.size() ; i++ ){
			cout<< endl << ans[i] << endl;
		}
	delete [] heap;
	return 0;
}
