// mapreader.h
// Membaca map.txt & menyimpan datanya
//

#pragma once

#ifndef MAPREADER_H
#define MAPREADER_H

#include <fstream>
#include "tipe.h"

using namespace std;

/*VARIABEL EXTERN*/
extern TabPlayer PlayerList;
	/*menyimpan player yang ada*/
extern Map GameMap;
	/*menyimpan data map*/

/*PEMBACAAN FILE*/
void ReadMap(ifstream& infile);
	/*Membaca current state game dari sebuah file*/
	/*Prekondisi : infile baru dibuka, belum dibaca*/
void SkipTo(string& str, size_t& idx, char c);
	/*Increment idx hingga str[idx] adalah karakter c sesuai parameter*/
	/*Jika tidak ada karakter c, setelah prosedur selesai, idx=str.length()*/
void SkipToNumber(string& str, size_t& idx);
	/*Increment idx hingga str[idx] adalah sebuah angka*/
	/*Jika str[idx] bukan angka hingga akhir string, setelah prosedur selesai, idx=str.length()*/
string GetData(string& str, size_t& idx);
	/*Increment idx hingga str[idx] adalah 2 karakter setelah ':' yang pertama ditemukan*/
	/*Jika tidak ada karakter yang dimaksud, setelah prosedur selesai, idx=str.length() dan kembalian menjadi string kosong*/
	/*Jika ada, setelah prosedur selesai, idx=str.length() dan kembalian adalah string dari karakter tersebut hingga karakter terakhir str*/
long long GetNumber(string& str, size_t& idx);
	/*Melakukan SkipToNumber(str,idx)*/
	/*Kemudian membaca deretan angka dan dikonversi ke long long*/
	/*Di akhir pembacaan, idx bernilai 1 lebih tinggi daripada index angka yang terakhir dibaca*/
void ReadBombs(string& str, size_t& idx, Bombs* ArrBombs, int& NeffBombs);
	/*Membaca data Bombs pada string str, dimulai dari index idx*/
	/*Mengisikan datanya ke dalam ArrBombs dan mengisikan banyaknya ke dalam NeffBombs*/

/*CEK & KONVERSI TIPE*/
bool IsNumber(char c);
	/*true jika c adalah karakter angka desimal 0-9*/
bool IsAlphabet(char c);
	/*true jika c adalah huruf*/
bool IsCapital(char c);
	/*true jika c adalah huruf kapital*/
bool IsNotCapital(char c);
	/*true jika c adalah huruf kecil*/
int CharToInt(char c);
	/*Mengubah char ke int*/
	/*Prekondisi : IsAngka(c)==true*/

#endif
