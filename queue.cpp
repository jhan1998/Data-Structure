#include <iostream>
#include <cstdlib>
#include<vector>
#include<cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int member[26], group_max;
	
	for(int i = 0;i<26;i++)
	member[i] = -1;
	char a;
	cin >> a;
	cout << endl;
	group_max = (a-'0');
	for(int i = 0;i < group_max; i++){
		int num, count;
		char mem,total;
		num = 0;
		count = 0;
		while(cin >> mem){
			//int temp;
			if(num > 0){
			int temp;
			temp = int(mem)-65;
			member[temp] = (i + 1);
		    }
			else if(num == 0)
			total = mem;  
			num++;
			if(cin.get() == '\n'){
				cout << endl;
				break;
			}
		}
		if( (total-'0') != (num-1) ){
		cout << "Didn't input correct number of members"<<endl;
		exit(-1);
	    }
	}
	
	
	vector<char>queue;
	vector<char>ans;
	vector<int>check;
	string q_index, count;
    char en_mem;
	while(!cin.eof()){
		int num=0;
		while(cin >> count){
			if(num == 0){
				q_index = count;
			}
			else{
				en_mem = count[0];
			}
			if(cin.get() == '\n'){
				break;
			}
			num++;
		}
		if( q_index == "ENQUEUE"){
			//cout << "q_index is "<< q_index<<endl;
			//cout<<check.size()<<endl;
			for(int i = 0 ; i < check.size() ; i++){
				if( member[en_mem-65] == check[i]  ){
					check.insert( check.begin()+i, member[en_mem-65] );
					queue.insert( queue.begin()+i, en_mem );
					break;
				}
				else if(i == (check.size() - 1)){
			        queue.push_back( en_mem );
			        check.push_back( member[en_mem-65] );
			        break;
				}
			}
			if( check.size() == 0 && queue.size() == 0 ){
				//cout << "input " << en_mem <<endl;
			    queue.push_back( en_mem );
			    check.push_back( member[en_mem-65] );
			}
		}
		else if( q_index == "DEQUEUE" ){
			if( queue.size() == 0 ){
				cout << "Queue is empty" << endl;
			}
			else{
			ans.push_back( queue[0] );
			queue.erase( queue.begin() );
			check.erase( check.begin() );
		    }
			//cout << "de " << ans.back() << endl;
		}
		q_index = "";
		en_mem = '\0';
		//cout << queue.size() << endl;
		cout<<endl;
	}
	for( int i = 0 ; i < ans.size() ; i++){
		cout << ans[i] << endl << endl ;
	}
	return 0;
}
