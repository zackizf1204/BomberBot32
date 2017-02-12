// BomberBot32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
using namespace std;

void readStateFile(string filePath);
void writeMoveFile(string filePath);

int _tmain(int argc, _TCHAR* argv[])
{
	/* Main Block */
		/*jadikan comment untuk debugging*/
		/*aktifkan lagi kalau selesai debugging*/
	string filePath = argv[2];
	cout << "Args: " << argc << endl;
	cout << "Player Key: " << argv[1] << endl;
	cout << "File Path: " << argv[2] << endl;
	readStateFile(filePath);
	writeMoveFile(filePath);

	/* Debugging Block */
		/*aktifkan untuk debugging*/
		/*jadikan comment kalau selesai debugging*/
		/*tambah-tambahin aja kalau butuh debug sesuatu*/
	/*
	readStateFile("sampledata");
	cout << "Seed = " << Seed(GameMap) << " ";
	cout << "Round = " << Round(GameMap) << " ";
	cout << "Bounty = " << Bounty(GameMap) << endl;
	for (int i = 1; i <= Height(GameMap); i++) {
		for (int j = 1; j <= Width(GameMap); j++) {
			cout << Block(GameMap, j, i);
		}
		cout << endl;
	}
	cout << "Data Player Terakhir :" << endl;
	cout << "Name = " << Name(Elmt(PlayerList, Neff(PlayerList))) << endl;
	cout << "Key = " << Key(Elmt(PlayerList, Neff(PlayerList))) << endl;
	cout << "Points = " << Points(Elmt(PlayerList, Neff(PlayerList))) << endl;
	cout << "Status = " << Status(Elmt(PlayerList, Neff(PlayerList))) << endl;
	cout << "Tekan Enter untuk keluar" << endl;
	cin.ignore();
	*/
	
	/* End of _tmain */
	return 0;
}

void readStateFile(string filePath)
{
	cout << "Reading state file " << filePath + "/" + "map.txt" << endl;
	ifstream myfile(filePath + "/" + "map.txt");
	ReadMap(myfile);
	myfile.close();
}

void writeMoveFile(string filePath)
{
	/*Kode gerakan: 1=up 2=left 3=right 4=down 5=bomb 6=timerbomb1*/
	cout << "Writing move file " << filePath + "/" + "move.txt" << endl;
	ofstream outfile(filePath + "/" + "move.txt");
	if (outfile.is_open())
	{
		random_device rd;
		mt19937 rng(rd());
		uniform_int_distribution<int> uni(1, 6);
		//outfile << uni(rng) << endl;
		if (uni(rng)%2==0) {
			outfile << 2 << endl;
		}
		else {
			outfile << 3 << endl;
		}
		outfile.close();
	}
}
