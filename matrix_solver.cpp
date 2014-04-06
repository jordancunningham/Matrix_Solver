//Author: Jordan Cunningham, Arizona State University

/*			Source Code Disclaimer:

Please feel free to use, modify, and redistribute
this code as you see fit. All I ask is that you give
credit to me as the original creator. Happy coding!

*/

#define WHITESPACE 32

//libraries
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//gross, will remove later
using namespace std;

//forward declarations of functions (function prototypes)
vector<string> storeStrings();
vector<vector<int> > parseMatrix(vector<string>);	//g++ compiler doesn't like two '>' together like this: '>>' so I have to separate them with a space
void Ax_b();
vector<vector<int> > REF(vector<vector<int> >);
vector<vector<int> > RREF(vector<vector<int> >);
void swap(vector<int> &, vector<int> &);
void printMatrix(vector<vector<int> >);


int main(){
	
	
	int x;

	while(true){
	
		cout<<"What would you like to do?"<<endl<<endl;
		cout<<"1. Solve Ax=b"<<endl;
		cout<<"1. Reduce a matrix to REF"<<endl;
		cout<<"2. Reduce a matrix to RREF"<<endl;
		cout<<"3. Find the nullspace of a matrix"<<endl;
		cout<<"4. Quit"<<endl<<endl;

		cin>>x;

		cout<<endl;

		switch(x){
		
		case 1: 
			Ax_b();
		case 4:
			exit(1);
		default:
			cout<<"Invalid input."<<endl<<endl;
		
		}

	}
    return 0;	
}

//This function takes in a matrix of any size row by row until the user enters "d"
//
//The rows are stored as strings (easier for the user) and parsed into integers later
vector<string> storeStrings(){

	vector<string> stringVector;
	string tempStr;
	bool done = false;

	cout<<"Enter each row of the matrix as integers."<<endl;
	cout<<"Hit enter to create a new row, and input \'d\' when done."<<endl<<endl;

	cin.ignore();	//this is essential and was messing up my whole program by not being there

	while(done == false){	//this is kinda crappy...I'll fix it later...
		getline(cin, tempStr);

			if(tempStr.compare("d") != 0){	//if it's not the break case push it onto the vector
				stringVector.push_back(tempStr);
			}
			else
				done = true;
	}

	return stringVector;	//return vector of strings

}

//This function takes in the string vector from storeStrings and parses
//the rows into integer vectors, which are then stored in a larger vector-of-integer-vectors
vector<vector<int> > parseMatrix(vector<string> strMatrix){

	vector<vector<int> > intMatrix;	//matrix to be returned

	stringstream stream;	//used to convert chars to ints

	int matrixLength = strMatrix.size();	//# of elements in matrix
	int stringLength = strMatrix[0].length();	//# of chars in string

	for(int i = 0; i < matrixLength; i++){	//for each row

		vector<int> intVector;

		for(int j = 0; j < stringLength; j++){	//for each char in each row
		
			stream.clear();	//clearing the stringstream is important

			int temp = 0;	//stores values temporarily as they are pushed into the vectors

			if(strMatrix[i][j] != WHITESPACE){	//if the index is not whitespace
				stream<<strMatrix[i][j];	//take in the char
				stream>>temp;	//output the char as an integer
				intVector.push_back(temp);	//push the integer into the vector
			}
		
		}
		
	
		intMatrix.push_back(intVector);	//push the finished vector into the matrix vector
	
	}

	cout<<endl;

	return intMatrix;	//return finished matrix

}

void Ax_b(){

	vector<string> strMatrix = storeStrings();
	vector<vector<int> > matrix = parseMatrix(strMatrix);
	//vector<vector<int> > RREF_matrix = RREF(matrix);

	printMatrix(matrix);

}


/*
//converts matrix to REF (Row Echelon Form)
vector<vector<int> > REF(vector<vector<int> > matrix){

	int rows = matrix.size();	//pretty self explanatory...
	int columns = matrix[0].size();

	//check to see if the matrix is already in REF...
	



}

//converts matrix to RREF from REF
vector<vector<int> > RREF(vector<vector<int> > matrix){







}

//this function determines what order the rows should be in based
//on the number of zeros in each row and column of the matrix
vector<int> analyzeMatrixRows(vector<vector<int> > matrix){

	vector<int> zerosByRow;	//stores how many zeros are in each row of a matrix
	vector<int> zerosByColumn;	//stores # of zeros in columns

	int rowLeastLeadingZeros = 0;	//index of row with least leading zeros
	int currentLeastLeadingZeros = 0;	//current number of least leading zeros
	int rowLeastZeros = 0;	//row with least zeros overall
	int currentLeastZeros = 0;	//currrent number of least overall zeros

	int rows = matrix.size();
	int columns = matrix[0].size();

	for(int i = 0; i < rows; i++){

		int numZeros = 0;	//records how many zeros each row has
		int leadingZeros;
		bool stillLeading = true;

		for(int j = 0; j < columns; j++){
		
			if(matrix[i][j] == 0)
				numZeros++;

			if(matrix[i][0] == 0 && stillLeading == true){	//if the first index is zero then we have the possibility of leading zeros...
				if(matrix[i][j] == 0)	//if current index is zero && first index is zero, increment leading zeros
					leadingZeros++;
				else
					stillLeading = false;	//if current index is not zero, stop counting leading zeros
				
			}
		}
			
		if(leadingZeros < currentLeastLeadingZeros){
			rowLeastLeadingZeros = i;
			currentLeastLeadingZeros = leadingZeros;
		}

		if(numZeros < rowLeastZeros)

	}







}

//swaps two vectors
void swap(vector<int> &v1, vector<int> &v2){

	vector<int> tempVector = v1;

	v1 = v2;
	v2 = tempVector;

	//done.
}

*/


void printMatrix(vector<vector<int> > matrix){

	int mSize = matrix.size();
	int vSize = matrix[0].size();

	cout<<"Matrix:"<<endl;

	for(int i = 0; i < mSize; i++){
	
		cout<<endl;

		for(int j = 0; j < vSize; j++){
		
			cout<<matrix[i][j]<<" ";
		
		}
	
	}

	cout<<endl<<endl;

}