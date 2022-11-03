
#include<iostream>
using namespace std;
int co=0;
bool kyamaiqueendaalsaktihun(int board[20][20],int i,int j,int n){
	// col check
	for(int l=1;l<=n;l++){
		if(board[l][j]==1){
			return false;
		}
	}


	// for(l=0;l<i;l++){
	// 	if(board[l][j]==1){
	// 		return false;
	// 	}
	// }


	// row 

	for(int k=-n;k<=-1;k++){
		if(board[i][k]==1){
			return false;
		}
	}

	// for(int k=0;k<j;k++){
	// 	if(board[i][k]==1){
	// 		return false;
	// 	}
	// }

	int t=i;//2
	int u=j; //1

	// i-->2,j-->1


	// diagonally right 
// loop
	while(i>=1&&j<=-1){
		if(board[i][j]==1){
		return false;

	}
	i--;//2 1 0 -1
	j++;//1 2 3 4

	}


	// i-->-1

	// j-->4


	// diagonally left 
	while(t>=1&&u>=-n){
		if(board[t][u]==1){
		return false;
	}
	t--;
	u--;


	}


	return true;


}
bool nqueen(int board[20][20],int n,int i){
	// base case 
	if(i==n+1){
		for(int l=1;l<=n;l++){
			for(int k=-n;k<=-1;k++)
			{
				if(board[l][k]==1)
				{
					cout<<"{"<<l<<k<<"} ";
				}
		}
		}
		// return true;
		cout<<" ";
		co++;
		return false;
	}


	// recursive case
	for(int j=-n;j<=-1;j++){
		// ki diagonally vertically or horizanttaly queen exist tou nahi karti
	if(kyamaiqueendaalsaktihun(board,i,j,n)==true){
		// haan mai daal sakti hun
		board[i][j]=1;
		bool kyaneechequeenplacehopayi=nqueen(board,n,i+1);
		if(kyaneechequeenplacehopayi==true){
			return true;

		}
		board[i][j]=0;//backtracking 

	}

	}
	return false;



}
int main(){
	// always a square 
	// chess board
	int board[20][20]={0};
	int n;
	cin>>n;
	nqueen(board,n,1);
cout<<endl;
	cout<<co<<endl;



	return 0;
} 
