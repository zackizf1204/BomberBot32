// mapreader.cpp
// implementasi mapreader.h
//

#include "stdafx.h"

/*VARIABEL EXTERN*/
TabPlayer PlayerList;
Map GameMap;

/*PEMBACAAN MAP*/
void ReadMap(ifstream& infile) {
	size_t i;
	string line;
	string subline;
	/*First Line Reading*/
	i = 0;
	getline(infile, line);
	Width(GameMap) = GetNumber(line, i);
	Height(GameMap) = GetNumber(line, i);
	Round(GameMap) = GetNumber(line, i);
	Seed(GameMap) = GetNumber(line, i);
	Bounty(GameMap) = GetNumber(line, i);
	/*Map Blocks Reading*/
	for (size_t j = 1; j <= Height(GameMap); j++) {
		getline(infile, line);
		for (size_t k = 1; k <= Width(GameMap); k++) {
			Block(GameMap, k, j) = line[k - 1];
		}
	}
	/*Players Data Reading*/
	bool EndOfPlayerData = false;
	Neff(PlayerList) = 0;
	while (!EndOfPlayerData && getline(infile, line)) {
		EndOfPlayerData = line[0] != '-';
		if (!EndOfPlayerData) {
			Neff(PlayerList)++;
			getline(infile, line); i = 0;
			Name(Elmt(PlayerList, Neff(PlayerList))) = GetData(line, i);
			getline(infile, line); i = 0;
			Key(Elmt(PlayerList, Neff(PlayerList))) = (GetData(line, i))[0];
			getline(infile, line); i = 0;
			Points(Elmt(PlayerList, Neff(PlayerList))) = GetNumber(line, i);
			getline(infile, line); i = 0;
			Status(Elmt(PlayerList, Neff(PlayerList))) = (GetData(line, i))[0] == 'A';
			getline(infile, line); i = 0;
			//to be continued...  baca data belum lengkap
		}
	}
}
void SkipTo(string& str, size_t& idx, char c) {
	while (str[idx] != c && idx < str.length()) {
		idx++;
	}
}
void SkipToNumber(string& str, size_t& idx) {
	while (!IsNumber(str[idx]) && idx < str.length()) {
		idx++;
	}
}
string GetData(string& str, size_t& idx) {
	SkipTo(str, idx, ':');
	idx+=2;
	if (idx > str.length()) {
		idx = str.length();
	}
	return str.substr(idx, string::npos);
}
long long GetNumber(string &str, size_t& idx) {
	long long result = 0;
	SkipToNumber(str, idx);
	bool IsStillNumber = true;
	while (idx < str.length() && IsStillNumber) {
		result = result * 10 + CharToInt(str[idx]);
		idx++;
		IsStillNumber = IsNumber(str[idx]);
	}
	return result;
}

/*CEK & KONVERSI TIPE*/
bool IsNumber(char c) {
	return (c >= 48 && c <= 57);
}
int CharToInt(char c) {
	return (c - 48);
}