// tipe.h
// Tipe bentukan untuk menyimpan data dari map.txt
//

#pragma once

#ifndef TIPE_H
#define TIPE_H

#include "point.h"

/*  Kamus Umum */
#define IdxMax 200
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

//Type Data Bomb
typedef struct 
{
	POINT BombLoc;
	int Fuse;
	int Radius;
} Bombs;

// Type Data Construct Player
typedef struct 
{
	string Name;
	char Key;
	int Points;
	bool Status; /*true jika hidup*/
	Bombs B[101]; /*index 0 tidak dipakai (IdxMin = 1)*/
	int NeffBombs; /*banyaknya Bombs yang aktif / banyak elemen array B[]*/
	int BombBag;
	int BlastRadius;
	POINT PlayerLoc;
} Player;

//Type Data Map
typedef struct 
{
	int Width;
	int Height;
	int Round;
	long long Seed;
	int Bounty;
	char Block[1001][1001];
		/*matrix of char, index 0 tidak dipakai (IdxMin = 1)*/
		/*Block[i][j] = kolom ke-i (X=i), baris ke-j (Y=j)*/
} Map;

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct { 
	Player TI[IdxMax+1]; /* memori tempat penyimpan elemen (container), index 0 tidak dipakai (IdxMin = 1) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabPlayer;

/* Setter dan Getter untuk ADT Bombs*/

#define BombLoc(C)	(C).BombLoc
#define Fuse(C)		(C).Fuse
#define Radius(C)	(C).Radius

/* Setter dan Getter untuk ADT Player*/

#define Name(C)			(C).Name
#define Key(C)			(C).Key
#define Points(C)		(C).Points
#define Status(C)		(C).Status
#define B(C)			(C).B
#define Bombs(C,i)		((C).B)[(i)] /*i>=1*/
#define NeffBombs(C)	(C).NeffBombs
#define BombBag(C)		(C).BombBag
#define Blast(C)		(C).BlastRadius
#define PlayerLoc(C)	(C).PlayerLoc

/* Setter dan Getter untuk ADT Map*/

#define Width(C)	(C).Width
#define Height(C)	(C).Height
#define Round(C)	(C).Round
#define Seed(C)		(C).Seed
#define Bounty(C)	(C).Bounty
#define Block(C,x,y) ((C).Block)[(x)][(y)] /*nb : Block(C,kolom,baris) , Block(C,X,Y) ; X>=1 ; Y>=1*/

/* Setter dan Getter untuk ADT TabPlayer*/

#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)] /*i>=1*/

#endif
