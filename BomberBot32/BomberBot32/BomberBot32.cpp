// BomberBot32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
using namespace std;

void readStateFile(string filePath);
void writeMoveFile(string filePath);

int _tmain(int argc, _TCHAR* argv[])
{
	string filePath = argv[2];

	cout << "Args: " << argc << std::endl;
	cout << "Player Key: " << argv[1] << std::endl;
	cout << "File Path: " << argv[2] << std::endl;

	readStateFile(filePath);
	writeMoveFile(filePath);
	return 0;
}

void readStateFile(string filePath)
{
	cout << "Reading state file " << filePath + "/" + "state.json" << std::endl;
	string fileContent;
	string line;
	ifstream myfile(filePath + "/" + "state.json");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			fileContent += line += "\n";
		}
		myfile.close();
	}
}

void writeMoveFile(string filePath)
{
	/*Kode gerakan: 1up 2left 3right 4down 5bomb 6timer*/
	cout << "Writing move file " << filePath + "/" + "move.txt" << std::endl;
	ofstream outfile(filePath + "/" + "move.txt");
	if (outfile.is_open())
	{
		random_device rd;
		mt19937 rng(rd());
		uniform_int_distribution<int> uni(0, 6);
		//outfile << uni(rng) << std::endl;
		if (uni(rng)%2==0) {
			outfile << 2 << std::endl;
		}
		else {
			outfile << 3 << std::endl;
		}
		outfile.close();
	}
}
