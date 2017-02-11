
#ifndef Tipe_H
#define Tipe_H
#include "point.h"
/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/


//Type Data Bomb
typedef struct 
{
	POINT Location;
	int Fuse;
	int Radius;
} Bombs;

// Type Data Construct Player
typedef struct 
{
	char Name[25];
	char Key;
	int Point;
	bool Status;
	Bombs B;
	int BlastRadius;
	POINT P;
} Player;

//Type Data Map
typedef struct 
{
	int Width;
	int Height;
	int Round;
	long Seed;
	int Bounty;
} Map;

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct { 
	Player TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabPlayer;


#endif