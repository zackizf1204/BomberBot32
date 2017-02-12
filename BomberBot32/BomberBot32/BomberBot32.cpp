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
	cout << "Data Player :" << endl;
	for (int i = 1; i <= Neff(PlayerList); i++) {
		cout << "==========<" << i << ">==========" << endl;
		cout << "Name = " << Name(Elmt(PlayerList, i)) << endl;
		cout << "Key = " << Key(Elmt(PlayerList, i)) << endl;
		cout << "Points = " << Points(Elmt(PlayerList, i)) << endl;
		cout << "Status = " << Status(Elmt(PlayerList, i)) << endl;
		cout << "Daftar Bombs = " << endl;
		for (int j = 1; j <= NeffBombs(Elmt(PlayerList, i)); j++) {
			cout << "\t[";
			cout << "x(kolom)=" << Absis(BombLoc(Bombs(Elmt(PlayerList, i), j))) << ";";
			cout << "y(baris)=" << Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j))) << ";";
			cout << "f=" << Fuse(Bombs(Elmt(PlayerList, i), j)) << ";";
			cout << "r=" << Radius(Bombs(Elmt(PlayerList, i), j)) << ";";
			cout << "]\n";
		}
		cout << "Bomb Bag = " << BombBag(Elmt(PlayerList, i)) << endl;
		cout << "Blast Radius = " << Blast(Elmt(PlayerList, i)) << endl;
		cout << "Lokasi(x(kolom),y(baris)) = "; TulisPOINT(PlayerLoc(Elmt(PlayerList, i))); cout << endl;
	}
	cout << endl << "Tekan Enter untuk keluar" << endl;
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
			outfile << 1 << endl;
		}
		else {
			outfile << 4 << endl;
		}
		outfile.close();
	}
}