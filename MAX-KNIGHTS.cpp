#include <bits/stdc++.h> 
using namespace std; 
  
int board[100][100] = {0};


void print(int N){
	for(int i=0;i<N;i++){
		int j = 1;
		if (i%2 == 0)
			j = 0;
			
		for(;j<N;){
			board[i][j] = 2;
			j=j+2;
		}
	}
	for(int i =0;i<N;i++){
		cout<<"| ";
		for(int j=0;j<N;j++){
			cout<<board[i][j]<<" | ";
		}
		cout<<endl;
	}	
}

int max_knight(int N){ 

	if(N==0)
		return 0;
    else if (N == 1) { 

        board[0][0] = 2;
        for(int i =0;i<N;i++){
			cout<<"| ";
			for(int j=0;j<N;j++){
				cout<<board[i][j]<<" | ";
			}
			cout<<endl;
		}
		return 1; 
    }else if(N == 2){
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
        		board[i][j] = 2;
			}
		}
		for(int i =0;i<N;i++){
			cout<<"| ";
			for(int j=0;j<N;j++){
				cout<<board[i][j]<<" | ";
			}
			cout<<endl;
		}
		    	
		cout<<endl<<"MAX SOLUTIONS ARE : 1";
		return 4; 
	}else if(N == 3){
		print(N);
		cout<<endl<<"MAX SOLUTIONS ARE : 2";	
		return 5;
	}else if(N == 4){
		print(N);
		cout<<endl<<"MAX SOLUTIONS ARE : 6";
		return 8;
	}else { 
		print(N);
				
		if (N%2 == 0){
			cout<<endl<<"MAX SOLUTIONS ARE : 2";
	        return (N*N)/2; 
		}else{
			cout<<endl<<"MAX SOLUTIONS ARE : 1";
			return ((N*N)/2 + 1);
		}
    		
	} 
} 
 
int main() { 
	cout<<"ENTER THE DIMENSION OF THE BOARD: ";
    int n; 
    cin>>n;
    cout <<endl<<"MAX KNIGHTS THAT CAN BE PLACED : "<< max_knight(n); 
  
    return 0; 
} 
