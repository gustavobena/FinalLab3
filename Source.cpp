/*  Gustavo Nomura
	C++ Fall 2019
	Due: 09/26/2019
	Lab 3
	User and File I/O */

/*   Write an interactive C++ program that computes and outputs the mean and
standard deviation of a set of four integers that are inputted by a file called
“inMeanStd.dat” and the user (should handle both). Although the individual values are
integers, the results are floating-point values. Be sure to use proper formatting and
appropriate comments in your code. Provide appropriate prompts to the user. The
output should be to the screen for the user inputted values and to a file called
“outMeanStd.dat”. The programs output should be labeled clearly and formatted
neatly. You must calculate the mean and standard deviation in separate functions.*/

#include < iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

float calcmean(int n1, int n2, int n3, int n4) //used to calculate the mean function
{

	float mean; // use decimal numbers.
	mean = (n1 + n2 + n3 + n4) / 4; // mean formula
	return mean;

}

float calcStandardDeviation(int n1, int n2, int n3, int n4) // used to calculate the Standard Deviation
{
	float StandardDeviation = 0.0, mean = 0.0; // return the results of mean and standard deviation in deciaml values
	mean = calcmean(n1, n2, n3, n4);
	StandardDeviation = sqrt((pow(n1 + mean, 2) + pow(n2 + mean, 2) + pow(n3 + mean, 2) + pow(n4 + mean, 2)) / 4 - 1); // Standard Deviation fomula
	return StandardDeviation;

}

int main()
{

	int n1; // use the integer numbers 
	int n2;
	int n3;
	int n4;
	float mean; // use the decimal result of mean 
	float StandardDeviation; // use the decimal result of the standard deviation 
	string inputFileName = "inMeanStd.dat";  // put the values on the debugging screen 
	string outputFileName = "outMeanStd.dat";// storage the values on the folder
	ofstream outFile;
	ifstream inFile;

	inFile.open(inputFileName);
	outFile.open(outputFileName);
	cout << "Enter four integer numbers:  ";
	cin >> n1 >> n2 >> n3 >> n4; // integers user values
	mean = calcmean(n1, n2, n3, n4); // formula of the mean
	StandardDeviation = calcStandardDeviation(n1, n2, n3, n4); // formula of the standard deviation 
	cout << "The mean is:  " << mean;
	cout << endl << endl;
	cout << "The Standard Deviation is:  " << StandardDeviation << endl;

	inFile >> n1 >> n2 >> n3 >> n4; // storage the values 
	mean = calcmean(n1, n2, n3, n4);
	StandardDeviation = calcStandardDeviation(n1, n2, n3, n4);
	outFile << "The mean is: " << mean << endl << endl;
	outFile << "The Standard Deviation is:  " << StandardDeviation;

	cout << "The mean is: " << mean << endl << endl;
	cout << "The Standard Deviation is:  " << StandardDeviation;


	inFile.close();
	outFile.close();

	return 0;

}