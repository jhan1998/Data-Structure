#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void powerset(vector<string> &str,  vector<string> &ans,int index = 0, string count = ""){
	int length = str.size();
	if( index == length ){
	ans.push_back(count);
	//cout<<index<<count<<endl;
	return;
}
    //cout<<index<<count<<endl;
	powerset(str,ans,index+1,count+str[index]);
	//cout<<index<<count<<endl;
	powerset(str,ans,index+1,count);
	return;
}
void print_matrix(vector<string> &ans){
	for(int i = 0;i < ans.size(); i++){
		cout<< "{" << ans[i] << "}";
	}
	cout << endl;
}

int main() {
	vector<string> str, ans;
	string str1;
	while(!cin.eof()){
	while(cin >> str1){
		str.push_back(str1);
		if(cin.get() == '\n') break;
	}	
	if(!cin.eof()){
		powerset(str, ans);
		print_matrix(ans);
	}
		str.clear();
		ans.clear();
	}
	return 0;
}
