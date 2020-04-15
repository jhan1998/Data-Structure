#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv){
	int matrix[100][100];
	
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			matrix[i][j] = -1;
		}
	}
	int num_edge, turn;
	cin >> num_edge;
	turn = num_edge;
	int max_events;
	while( turn > 0 ){
		int input, start, end, weight, count = 0;
		while( cin >> input ){
			if( count == 1 )
				start = input;
			else if( count == 2 )
				end = input;
			else if( count == 3 )
				weight = input;
			
			if( ( turn == 1 ) && ( count == 2) )
				max_events = input;
			count++;
			if( cin.get() == '\n' )
			break;
		}
		matrix[start][end] = weight;
		turn--;
	}
	int ee[max_events+1], le[max_events+1], cost_edge[num_edge + 1];
	memset(ee, 0, sizeof(int)*max_events);
	memset(cost_edge, 0, sizeof(int)*num_edge + 1);
	for( int i = 0 ; i <= max_events ; i++ ){
		for( int j = 1 ; j <= max_events ; j++ ){
			if( matrix[i][j] != -1 ){
				cost_edge[j] = matrix[i][j];
				if( ee[j] < ( cost_edge[i] + matrix[i][j] ) ){
					ee[j] = cost_edge[i] + matrix[i][j];
				}
				cost_edge[j] = ee[j];
			}
		}
	}
	le[max_events] = ee[max_events]; 
	for(int i=0; i<max_events; i++){
		le[i] = INT_MAX;
	}
	for(int i = max_events - 1 ; i >= 0; i--){
		for( int j = 0 ; j <= max_events ; j++ ){
			if( matrix[i][j] != -1 ){
				if( le[i] > (le[j] - matrix[i][j] ) ){
					le[i] = le[j] - matrix[i][j];
				}
			}
		}
	}
	int e[num_edge], l[num_edge];
	int k = 0;
	for( int i = 0 ; i <= max_events ; i++ ){
		for( int j = 0 ; j <= max_events ; j++ ){
			if( matrix[i][j] != -1 ){
				e[k] = ee[i];
				k++; 
			}
		}
	}
	k = 0;
	for( int i = 0 ; i <= max_events ; i++ ){
		for( int j = 0 ; j <= max_events ; j++ ){
			if( matrix[i][j] != -1 ){
				l[k] = le[j]-matrix[i][j];
				k++; 
			}
		}
	}
	cout << endl;
	vector<int> ans;
	cout << "event\tee\tle" <<endl;
	for( int i = 0 ; i <= max_events ; i++ ){
		cout << i << "\t" << ee[i] << "\t" << le[i] << endl;
	}
	cout << endl;
	cout << "act.\te\tl\tslack\tcritical\n";
	for( int i = 0 ; i < num_edge ; i++ ){
		cout << i + 1 << "\t" << e[i] << "\t" << l[i] << "\t" << ( l[i] - e[i] ) << "\t";
		if(( l[i] - e[i] ) == 0){
			cout << "yes" << endl;
			ans.push_back(i+1);
		}
		else
			cout << "no" << endl;
	}
	cout << endl;
	for( int i = 0 ; i < ans.size() ; i++ ){
		cout << ans[i] << " "; 
	}
	cout << endl << endl;
	
	return 0;
}
