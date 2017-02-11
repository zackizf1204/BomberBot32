
#ifndef Tipe_H
#define Tipe_H

#include "point.h"
#include "boolean.h"

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
	int Points;
	bool Status;
	Bombs B;
	int BlastRadius;
	POINT Location;
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

/* Setter dan Getter untuk ADT Bombs*/

#define BombLoc(C)	(C).Location
#define Fuse(C)		(C).Fuse
#define Radius(C)	(C).Radius

/* Setter dan Getter untuk ADT Player*/

#define Name(C)			(C).Name
#define Key(C)			(C).Key
#define Points(C)		(C).Points
#define Status(C)		(C).Status
#define Bombs(C)		(C).B
#define Blast(C)		(C).BlastRadius
#define PlayerLoc(C)	(C).Location

/* Setter dan Getter untuk ADT Map*/

#define Width(C)	(C).Width
#define Height(C)	(C).Height
#define Round(C)	(C).Round
#define Seed(C)		(C).Seed
#define Bounty(C)	(C).Bounty

/* Setter dan Getter untuk ADT TabPlayer*/

#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[i]

#endif
