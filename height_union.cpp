#include <iostream>
#include <cstdlib>
#include <sstream> 
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int parent[101];

void union_h( int x, int y ){
	int temp;
	if( parent[x] < parent[y] ){
		temp = parent[x];
		parent[y] = x;
		parent[x] = temp;
	}
	else if( parent[y] < parent[x] ){
		temp = parent[y];
		parent[x] = y;
		parent[y] = temp;
	}
	else if( parent[x] == parent[y] ){
		temp = parent[x] - 1;
		parent[y] = x;
		parent[x] = temp;
	}
}
int find_c(int i){
	int num, root, trail, lead;
	num = 0;
	for( root = i ; parent[root] >= 0 ; root = parent[root] )
	    num++;
	for( trail = i ; parent[trail] != root ; trail = lead ){
		lead = parent[trail];
		parent[trail] = root;
		num++;
	}
	return num;
}

int main() {
	vector<int> ans;
	for( int i =0 ; i < 101 ; i++){
		parent[i] = -101;
	}
	string x;
	int num_tree = 0;
	cin >> x;
	stringstream change(x);
	change >> num_tree;
	cout << endl;
	while( num_tree > 0 ){
		string y;
		int node = 0;
		cin >> y;
		stringstream change(y);
		change >> node;
		cout << endl;
		for( int i = 0 ; i < node ; i++){
			int counter = 0;
			int child;
			string input; 
			while( cin >> input ){
				if( counter == 0 ){
				   stringstream change(input);
				   change >> child;
			    }
				else if( counter > 0 ){
					int p;
					stringstream change(input);
					change >> p;
					parent[child] = p;
				}
				counter++;
				if( cin.get() == '\n' )
				break;
			}
			cout << endl;
		}
		num_tree--;
	}
	while(1){
		int counter = 0;
		int index1, index2;
		string input, order;
		while( cin >> input ){
			if( counter == 0)
				order = input;
			else if( counter == 1 ){
				stringstream change(input);
				change >> index1;
			}
			else if( counter == 2 ){
				stringstream change(input);
				change >> index2;
			}
			counter++;
			if( cin.get() == '\n' )
				break;
		}
		cout << endl;
		if( order == "UNION" )
			union_h( index1, index2 );
		else if( order == "FIND" ){
			ans.push_back(find_c(index1));
		}
		else if( order == "STOP" )
		break;
	}
	for( int i =0 ; i < ans.size() ; i++){
		cout<< endl << ans[i] << endl;
	}
	return 0;
}
