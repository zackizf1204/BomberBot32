#include "stdafx.h"

using namespace std;

static int jarak[1001][1001]; //jarak blok map dari lokasi player

bool DangerKanan(POINT P)
{
	int a, b;
	int i, j;
	bool found, danger;
	danger = false;
	a = Absis(P) + 1;
	b = Ordinat(P);
	while ((a < Width(GameMap)) && (Block(GameMap, a, Ordinat(P)) != '#') && (Block(GameMap, a, Ordinat(P)) != '+') && (!IsNotCapital(Block(GameMap, a, Ordinat(P)))) && !IsNumber((Block(GameMap, a, Ordinat(P)))))
	{
		a = a + 1;
	}
	if (a >= Width(GameMap))
	{
		danger = false;
	}
	else
	{
		if ((Block(GameMap, a, Ordinat(P)) == '#') || (Block(GameMap, a, Ordinat(P)) == '+'))
		{
			danger = false;
		}
		else
		{
			if ((IsNotCapital(Block(GameMap, a, Ordinat(P)))) || IsNumber((Block(GameMap, a, Ordinat(P)))))
			{
				found = false;
				i = 1;
				while ((i <= Neff(PlayerList)) && (!found))
				{
					j = 1;
					while (j <= NeffBombs(Elmt(PlayerList, i)) && (!found))
					{
						if ((a == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (b == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
						{
							if (abs(Absis(BombLoc(Bombs(Elmt(PlayerList, i), j))) - Absis(P)) <= Radius(Bombs(Elmt(PlayerList, i), j)))
							{
								danger = true;
							}
							else
							{
								danger = false;
							}
							found = true;
						}
						else
						{
							j = j + 1;
						}
					}
					i = i + 1;
				}
			}
			else
			{
				danger = false;
			}

		}
	}
	return(danger);
}

bool DangerKiri(POINT P)
{
	int a, b;
	int i, j;
	bool found, danger;
	danger = false;
	a = Absis(P) - 1;
	b = Ordinat(P);
	while ((a > 1) && (Block(GameMap, a, Ordinat(P)) != '#') && (Block(GameMap, a, Ordinat(P)) != '+') && (!IsNotCapital(Block(GameMap, a, Ordinat(P)))) && !IsNumber((Block(GameMap, a, Ordinat(P)))))
	{
		a = a - 1;
	}
	if (a <= 1)
	{
		danger = false;
	}
	else
	{
		if ((Block(GameMap, a, Ordinat(P)) == '#') || (Block(GameMap, a, Ordinat(P)) == '+'))
		{
			danger = false;
		}
		else
		{
			if ((IsNotCapital(Block(GameMap, a, b))) || IsNumber((Block(GameMap, a, b))))
			{
				found = false;
				i = 1;
				while ((i <= Neff(PlayerList)) && (!found))
				{
					j = 1;
					while (j <= NeffBombs(Elmt(PlayerList, i)) && (!found))
					{
						if ((a == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (b == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
						{
							if (abs(Absis(BombLoc(Bombs(Elmt(PlayerList, i), j))) - Absis(P)) <= Radius(Bombs(Elmt(PlayerList, i), j)))
							{
								danger = true;
							}
							else
							{
								danger = false;
							}
							found = true;
						}
						else
						{
							j = j + 1;
						}
					}
					i = i + 1;
				}
			}
			else
			{
				danger = false;
			}

		}
	}
	return(danger);
}

bool DangerAtas(POINT P)
{
	int a, b;
	int i, j;
	bool found, danger;
	danger = false;
	a = Absis(P);
	b = Ordinat(P) - 1;
	while ((b >1) && (Block(GameMap, a, b) != '#') && (Block(GameMap, a, b) != '+') && (!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
	{
		b = b - 1;
	}
	if (b == 1)
	{
		danger = false;
	}
	else
	{
		if ((Block(GameMap, a, b) == '#') || (Block(GameMap, a, b) == '+'))
		{
			danger = false;
		}
		else
		{
			if ((IsNotCapital(Block(GameMap, a, b))) || IsNumber((Block(GameMap, a, b))))
			{
				found = false;
				i = 1;
				while ((i <= Neff(PlayerList)) && (!found))
				{
					j = 1;
					while (j <= NeffBombs(Elmt(PlayerList, i)) && (!found))
					{
						if ((a == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (b == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
						{
							if (abs(Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j))) - Ordinat(P)) <= Radius(Bombs(Elmt(PlayerList, i), j)))
							{
								danger = true;
							}
							else
							{
								danger = false;
							}
							found = true;
						}
						else
						{
							j = j + 1;
						}
					}
					i = i + 1;
				}
			}
			else
			{
				danger = false;
			}

		}
	}
	return(danger);
}

bool DangerBawah(POINT P)
{
	int a, b;
	int i, j;
	bool found, danger;
	danger = false;
	a = Absis(P);
	b = Ordinat(P) + 1;
	while ((b < Height(GameMap)) && (Block(GameMap, a, b) != '#') && (Block(GameMap, a, b) != '+') && (!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
	{
		b = b + 1;
	}
	if (b == Height(GameMap))
	{
		danger = false;
	}
	else
	{
		if ((Block(GameMap, a, b) == '#') || (Block(GameMap, a, b) == '+'))
		{
			danger = false;
		}
		else
		{
			if ((IsNotCapital(Block(GameMap, a, b))) || IsNumber((Block(GameMap, a, b))))
			{
				found = false;
				i = 1;
				while ((i <= Neff(PlayerList)) && (!found))
				{
					j = 1;
					while (j <= NeffBombs(Elmt(PlayerList, i)) && (!found))
					{
						if ((a == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (b == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
						{
							if (abs(Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j))) - Ordinat(P)) <= Radius(Bombs(Elmt(PlayerList, i), j)))
							{
								danger = true;
							}
							else
							{
								danger = false;
							}
							found = true;
						}
						else
						{
							j = j + 1;
						}
					}
					i = i + 1;
				}
			}
			else
			{
				danger = false;
			}

		}
	}
	return(danger);
}
bool InDanger(POINT P)
{
	return(DangerKanan(P) || DangerKiri(P) || DangerAtas(P) || DangerBawah(P) || (IsNotCapital(Block(GameMap, Absis(P), Ordinat(P)))) || (IsNumber(Block(GameMap, Absis(P), Ordinat(P)))));
}

bool CekTembok(POINT P) {
	int a, b;
	a = Absis(P);
	b = Ordinat(P);

	if ((Block(GameMap, a + 1, b) == '+') || (Block(GameMap, a - 1, b) == '+') || (Block(GameMap, a, b + 1) == '+') || (Block(GameMap, a, b - 1) == '+')) {
		return(true);
	}
	else {
		return(false);
	}
}

int Jalan(POINT p) {
	int a, b;
	a = Absis(p);
	b = Ordinat(p);

	if (InDanger(MakePOINT(a + 1, b)) || InDanger(MakePOINT(a - 1, b)) || InDanger(MakePOINT(a, b + 1)) || InDanger(MakePOINT(a, b - 1))) {
		return 0;
	}
	else {
		deque <POINT> safe; /*menampung koordinat yang aman. initial state : kosong*/
		deque <POINT> notsafe; /*menampung koordinat yang tidak aman. initial state : kosong*/
		int d = 0; /*jarak titik p dari posisi pemain. nilai awal : 0*/
		int move = 0; /*kode gerakan yang akan dikembalikan. nilai awal : sembarang*/
		for (int i = 1; i <= Width(GameMap); i++) {
		for (int j = 1; j <= Height(GameMap); j++) {
			jarak[i][j] = -1;
		}
	}
	jarak[Absis(p)][Ordinat(p)] = 0;
	do {
		if (d == 0) {
			Jalan2(p, 0, safe, notsafe);
		}
		else {
			int i = 0;
			int notsafesize = notsafe.size();
			while (i<notsafesize && safe.empty()) {
				Jalan2(notsafe[0], d, safe, notsafe);
				notsafe.pop_front();
				i++;
			}
		}
		d++;
	} while (safe.empty() && !notsafe.empty());
	if (!safe.empty()) {
		/*ada tempat aman*/
		POINT safeplace; /*koordinat yang dituju*/
		Absis(safeplace) = Absis(safe.front());
		Ordinat(safeplace) = Ordinat(safe.front());
		cout << "Tujuan : "; TulisPOINT(safeplace); cout << "Jarak : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
		while (jarak[Absis(safeplace)][Ordinat(safeplace)] > 1) {
			cout << "before : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
			int i = 1;
			POINT nextsafeplace;
			do {
				if (i == 1) {
					Absis(nextsafeplace) = Absis(safeplace);
					Ordinat(nextsafeplace) = Ordinat(safeplace) - 1;
				}
				else if (i == 2) {
					Absis(nextsafeplace) = Absis(safeplace) - 1;
					Ordinat(nextsafeplace) = Ordinat(safeplace);
				}
				else if (i == 3) {
					Absis(nextsafeplace) = Absis(safeplace) + 1;
					Ordinat(nextsafeplace) = Ordinat(safeplace);
				}
				else {
					Absis(nextsafeplace) = Absis(safeplace);
					Ordinat(nextsafeplace) = Ordinat(safeplace) + 1;
				}
				i++;
			} while (i <= 4 && (jarak[Absis(nextsafeplace)][Ordinat(nextsafeplace)] <= 0 || jarak[Absis(nextsafeplace)][Ordinat(nextsafeplace)] >= jarak[Absis(safeplace)][Ordinat(safeplace)]));
			i--;
			Absis(safeplace) = Absis(nextsafeplace);
			Ordinat(safeplace) = Ordinat(nextsafeplace);
			cout << i << "Gerak dulu ke : "; TulisPOINT(safeplace); cout << "Jarak : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
			cout << "after : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
		}
		if (Absis(safeplace) < Absis(p)) {
			/*titik yang dituju ada di sebelah kiri pemain*/
			move = 2;
		}
		else if (Absis(safeplace) > Absis(p)) {
			/*titik yang dituju ada di sebelah kanan pemain*/
			move = 3;
		}
		else if (Ordinat(safeplace) < Ordinat(p)) {
			/*titik yang dituju ada di sebelah atas pemain*/
			move = 1;
		}
		else if (Ordinat(safeplace) > Ordinat(p)) {
			/*titik yang dituju ada di sebelah bawah pemain*/
			move = 4;
		}
	}
	else {
		/*tidak ada tempat aman, do nothing*/
	}
	return move;
	}
}

void Jalan2(POINT p, int d, deque<POINT>& safe, deque<POINT>& notsafe) {
	/*Menentukan arah yang diprioritaskan secara random*/
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 4);
	int dir = uni(rng);
	/*Menentukan apakah koordinat tetangga aman atau tidak aman*/
	POINT tetangga;
	int i = 0;
	while (i<4 && safe.size() == 0) {
		if (dir == 1) {
			Absis(tetangga) = Absis(p);
			Ordinat(tetangga) = Ordinat(p) - 1;
		}
		else if (dir == 2) {
			Absis(tetangga) = Absis(p) - 1;
			Ordinat(tetangga) = Ordinat(p);
		}
		else if (dir == 3) {
			Absis(tetangga) = Absis(p) + 1;
			Ordinat(tetangga) = Ordinat(p);
		}
		else if (dir == 4) {
			Absis(tetangga) = Absis(p);
			Ordinat(tetangga) = Ordinat(p) + 1;
		}
		if (Block(GameMap, Absis(tetangga), Ordinat(tetangga)) != '#' && Block(GameMap, Absis(tetangga), Ordinat(tetangga)) != '+' && !isalnum(Block(GameMap, Absis(tetangga), Ordinat(tetangga))) && jarak[Absis(tetangga)][Ordinat(tetangga)]<0) {
			if ((!InDanger(tetangga)) && (CekTembok(tetangga))) {
				safe.push_back(tetangga);
				cout << "safe : ";
				TulisPOINT(tetangga);
				cout << endl;
			}
			else {
				notsafe.push_back(tetangga);
				cout << "not safe : ";
				TulisPOINT(tetangga);
				cout << endl;
			}
			jarak[Absis(tetangga)][Ordinat(tetangga)] = d + 1;
		}
		dir = (dir % 4) + 1;
		i++;
	}
}

int Kabur(POINT p) {
	deque <POINT> safe; /*menampung koordinat yang aman. initial state : kosong*/
	deque <POINT> notsafe; /*menampung koordinat yang tidak aman. initial state : kosong*/
	int d = 0; /*jarak titik p dari posisi pemain. nilai awal : 0*/
	int move = 0; /*kode gerakan yang akan dikembalikan. nilai awal : sembarang*/
	for (int i = 1; i <= Width(GameMap); i++) {
		for (int j = 1; j <= Height(GameMap); j++) {
			jarak[i][j] = -1;
		}
	}
	jarak[Absis(p)][Ordinat(p)] = 0;
	do {
		if (d == 0) {
			Kabur2(p, 0, safe, notsafe);
		}
		else {
			int i = 0;
			int notsafesize = notsafe.size();
			while (i<notsafesize && safe.empty()) {
				Kabur2(notsafe[0], d, safe, notsafe);
				notsafe.pop_front();
				i++;
			}
		}
		d++;
	} while (safe.empty() && !notsafe.empty());
	if (!safe.empty()) {
		/*ada tempat aman*/
		POINT safeplace; /*koordinat yang dituju*/
		Absis(safeplace) = Absis(safe.front());
		Ordinat(safeplace) = Ordinat(safe.front());
		cout << "Tujuan : "; TulisPOINT(safeplace); cout << "Jarak : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
		while (jarak[Absis(safeplace)][Ordinat(safeplace)] > 1) {
			cout << "before : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
			int i = 1;
			POINT nextsafeplace;
			do {
				if (i == 1) {
					Absis(nextsafeplace) = Absis(safeplace);
					Ordinat(nextsafeplace) = Ordinat(safeplace) - 1;
				}
				else if (i == 2) {
					Absis(nextsafeplace) = Absis(safeplace) - 1;
					Ordinat(nextsafeplace) = Ordinat(safeplace);
				}
				else if (i == 3) {
					Absis(nextsafeplace) = Absis(safeplace) + 1;
					Ordinat(nextsafeplace) = Ordinat(safeplace);
				}
				else {
					Absis(nextsafeplace) = Absis(safeplace);
					Ordinat(nextsafeplace) = Ordinat(safeplace) + 1;
				}
				i++;
			} while (i <= 4 && (jarak[Absis(nextsafeplace)][Ordinat(nextsafeplace)] <= 0 || jarak[Absis(nextsafeplace)][Ordinat(nextsafeplace)] >= jarak[Absis(safeplace)][Ordinat(safeplace)]));
			i--;
			Absis(safeplace) = Absis(nextsafeplace);
			Ordinat(safeplace) = Ordinat(nextsafeplace);
			cout << i << "Gerak dulu ke : "; TulisPOINT(safeplace); cout << "Jarak : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
			cout << "after : " << jarak[Absis(safeplace)][Ordinat(safeplace)] << endl;
		}
		if (Absis(safeplace) < Absis(p)) {
			/*titik yang dituju ada di sebelah kiri pemain*/
			move = 2;
		}
		else if (Absis(safeplace) > Absis(p)) {
			/*titik yang dituju ada di sebelah kanan pemain*/
			move = 3;
		}
		else if (Ordinat(safeplace) < Ordinat(p)) {
			/*titik yang dituju ada di sebelah atas pemain*/
			move = 1;
		}
		else if (Ordinat(safeplace) > Ordinat(p)) {
			/*titik yang dituju ada di sebelah bawah pemain*/
			move = 4;
		}
	}
	else {
		/*tidak ada tempat aman, do nothing*/
	}
	return move;
}

void Kabur2(POINT p, int d, deque<POINT>& safe, deque<POINT>& notsafe) {
	/*Menentukan arah yang diprioritaskan secara random*/
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 4);
	int dir = uni(rng);
	/*Menentukan apakah koordinat tetangga aman atau tidak aman*/
	POINT tetangga;
	int i = 0;
	while (i<4 && safe.size() == 0) {
		if (dir == 1) {
			Absis(tetangga) = Absis(p);
			Ordinat(tetangga) = Ordinat(p) - 1;
		}
		else if (dir == 2) {
			Absis(tetangga) = Absis(p) - 1;
			Ordinat(tetangga) = Ordinat(p);
		}
		else if (dir == 3) {
			Absis(tetangga) = Absis(p) + 1;
			Ordinat(tetangga) = Ordinat(p);
		}
		else if (dir == 4) {
			Absis(tetangga) = Absis(p);
			Ordinat(tetangga) = Ordinat(p) + 1;
		}
		if (Block(GameMap, Absis(tetangga), Ordinat(tetangga)) != '#' && Block(GameMap, Absis(tetangga), Ordinat(tetangga)) != '+' && !isalnum(Block(GameMap, Absis(tetangga), Ordinat(tetangga))) && jarak[Absis(tetangga)][Ordinat(tetangga)]<0) {
			if (!InDanger(tetangga)) {
				safe.push_back(tetangga);
				cout << "safe : ";
				TulisPOINT(tetangga);
				cout << endl;
			}
			else {
				notsafe.push_back(tetangga);
				cout << "not safe : ";
				TulisPOINT(tetangga);
				cout << endl;
			}
			jarak[Absis(tetangga)][Ordinat(tetangga)] = d + 1;
		}
		dir = (dir % 4) + 1;
		i++;
	}
}