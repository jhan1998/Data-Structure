#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char Sol[2][13];
	int test[13];
	bool check[13];
	srand( time(NULL) );
	
	
	for(int i = 0; i < 13 ; i++)
	check[i] = false;
	int i = 0;
	while(i < 13){
		int x = (rand() % 13);
		//cout << x << endl;
		while(check[x] == false){
		switch(x){
			case 0:
				test[i] = 1;
				Sol[0][i] = 'A';
				Sol[1][i] = '0';
				check[0] = true;
				i++;
				break;
			case 1:
				test[i] = 2;
				Sol[0][i] = '2';
				Sol[1][i] = '0';
				check[1] = true;
				i++;
				break;
			case 2:
				test[i] = 3;
				Sol[0][i] = '3';
				Sol[1][i] = '0';
				check[2] = true;
				i++;
				break;
			case 3:
				test[i] = 4;
				Sol[0][i] = '4';
				Sol[1][i] = '0';
				check[3] = true;
				i++;
				break;
			case 4:
				test[i] = 5;
				Sol[0][i] = '5';
				Sol[1][i] = '0';
				check[4] = true;
				i++;
				break;
			case 5:
				test[i] = 6;
				Sol[0][i] = '6';
				Sol[1][i] = '0';
				check[5] = true;
				i++;
				break;
			case 6:
				test[i] = 7;
				Sol[0][i] = '7';
				Sol[1][i] = '0';
				check[6] = true;
				i++;
				break;
			case 7:
				test[i] = 8;
				Sol[0][i] = '8';
				Sol[1][i] = '0';
				check[7] = true;
				i++;
				break;
			case 8:
				test[i] = 9;
				Sol[0][i] = '9';
				Sol[1][i] = '0';
				check[8] = true;
				i++;
				break;
			case 9:
				test[i] = 10;
				Sol[0][i] = '0';
				Sol[1][i] = '1';
				check[9] = true;
				i++;
				break;
			case 10:
				test[i] = 11;
				Sol[0][i] = 'J';
				Sol[1][i] = '0';
				check[10] = true;
				i++;
				break;
			case 11:
	     		test[i] = 12;
				Sol[0][i] = 'Q';
				Sol[1][i] = '0';
				check[11] = true;
				i++;
				break;
			case 12:
		    	test[i] = 13;
				Sol[0][i] = 'K';
				Sol[1][i] = '0';
		    	check[12] = true;
		    	i++;
				break;
		}
	}
}
	
	int counter = 13;
	while( counter >= 1 ){
		for(int i = 0; i < counter; i++){
		if(Sol[0][i] == '0')
		cout << Sol[1][i] << Sol[0][i] << " ";
		else
		cout << Sol[0][i] <<" ";
	}
		if(test[0] == counter){
			/*if(test[0] == 10)
			cout << " " << "(" << Sol[1][0] << Sol[0][0] << " will be drawn out)";
			else
			cout << " " << "(" << Sol[0][0] << " will be drawn out)";*/
			for(int i = 0; i < counter-1; i++){
			Sol[0][i] = Sol[0][i+1];
			Sol[1][i] = Sol[1][i+1];
			test[i] = test[i+1];
			if( i == counter-2){
			Sol[0][counter-1] = 'z';
			Sol[1][counter-1] = 'z';
			test[counter -1 ] = -1;
			}
			} 
			counter--;
		}
		else{
			char temp[2][1];
			temp[1][0] = Sol[1][0];
			temp[0][0] = Sol[0][0];
			int temp_t = test[0];
			for(int i = 0; i< counter-1;i++){
				Sol[0][i] = Sol[0][i+1];
				Sol[1][i] = Sol[1][i+1];
				test[i] = test[i+1];
				if( i == counter - 2 ){
					Sol[0][counter-1] = temp[0][0];
					Sol[1][counter-1] = temp[1][0];
					test[counter-1] = temp_t;
				}
			}
			
		}
		cout << endl;
	}
	
	return 0;
}
