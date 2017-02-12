/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "stdafx.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;
    Absis(P)=X;
    Ordinat(P)=Y;
    return(P);
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT(POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	int x, y;
	scanf_s("%d %d", &x, &y);
	*P = MakePOINT(x, y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    printf("(%d,%d)",Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
bool EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}
bool NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return(!EQ(P1,P2));
}
/* *** Kelompok menentukan di mana P berada *** */
bool IsOrigin (POINT P)
{
    return((Absis(P)==0)&&(Ordinat(P)==0));
}
/* Menghasilkan true jika P adalah titik origin */
bool IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return(Ordinat(P)==0);
}
bool IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return(Absis(P)==0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    int x=Absis(P),y=Ordinat(P);
    if (x>0&&y>0)
        return(1);
    else if (x<0&&y>0)
        return(2);
    else if (x<0&&y<0)
        return(3);
    else return(4);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */


POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{

    return(MakePOINT(Absis(P)+1,Ordinat(P)));
}

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    return(MakePOINT(Absis(P),Ordinat(P)+1));
}
POINT PlusDelta (POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    return(MakePOINT(Absis(P)+deltaX,Ordinat(P)+deltaY));
}
POINT MirrorOf (POINT P, bool SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    if (SbX)
            return(MakePOINT(Absis(P),0-(Ordinat(P))));

    else return(MakePOINT(0-(Absis(P)),Ordinat(P)));


}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    float x=float(Absis(P));
    float y=float(Ordinat(P));
    return(sqrt(x*x+y*y));
}
float Panjang (POINT P1, POINT P2){
	float dx,dy;
	dx = float(Absis(P2) - Absis(P1));
	dy = float(Ordinat(P2)-Ordinat(P1));
	return sqrt((dx*dx)+(dy*dy));
}
void Geser (POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
   *P=PlusDelta(*P,deltaX,deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    *P=MakePOINT(Absis(*P),0);
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    *P=MakePOINT(0,Ordinat(*P));
}
void Mirror (POINT *P, bool SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    *P=MirrorOf(*P,SbX);
}
void Putar (POINT *P, double Sudut){
	double x,y,s;
	s = 0 - (Sudut * M_PI / 180);
	x = (double) Absis(*P);
	y = (double) Ordinat(*P);
	// diputar counterclockwise sebesar Sudut
	double newx = x * cos(s) - y * sin(s);
	double newy = x * sin(s) + y * cos(s);;
	*P = MakePOINT((int)(newx),(int)(newy));
}

