#include "stdafx.h"
bool DangerKanan(POINT P)
{
	int a, b;
	int i, j;
	bool found, danger;
	danger = false;
	a = Absis(P);
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
		if((Block(GameMap, a, Ordinat(P)) != '#') && (Block(GameMap, a, Ordinat(P)) != '+'))
		{
			danger = false;
		}
		else
		{
			if ((!IsNotCapital(Block(GameMap, a, Ordinat(P)))) && !IsNumber((Block(GameMap, a, Ordinat(P)))))
			{
				found = false;
				i = 0;
				while ((i < Neff(PlayerList)) && (!found))
				{
					j = 0;
					while (j < NeffBombs(Elmt(PlayerList, i)) && (!found))
						{
							if ((Absis(P) == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (Ordinat(P) == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
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
	a = Absis(P);
	b = Ordinat(P);
	while ((a > 1) && (Block(GameMap, a, Ordinat(P)) != '#') && (Block(GameMap, a, Ordinat(P)) != '+') && (!IsNotCapital(Block(GameMap, a, Ordinat(P)))) && !IsNumber((Block(GameMap, a, Ordinat(P)))))
	{
		a = a - 1;
	}
	if (a <= 1)
	{
		danger = true;
	}
	else
	{
		if((Block(GameMap, a, Ordinat(P)) != '#') && (Block(GameMap, a, Ordinat(P)) != '+'))
		{
			danger = true;
		}
		else
		{
			if ((!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
			{
				found = false;
				i = 0;
				while ((i < Neff(PlayerList)) && (!found))
				{
					j = 0;
					while (j < NeffBombs(Elmt(PlayerList, i)) && (!found))
						{
							if ((Absis(P) == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (Ordinat(P) == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
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
	b = Ordinat(P);
	while ((b < Height(GameMap)) && (Block(GameMap, a, b) != '#') && (Block(GameMap, a, b) != '+') && (!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
	{
		b = b + 1;
	}
	if (b >= Height(GameMap))
	{
		danger = false;
	}
	else
	{
		if((Block(GameMap, a, b) != '#') && (Block(GameMap, a, b) != '+'))
		{
			danger = false;
		}
		else
		{
			if ((!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
			{
				found = false;
				i = 0;
				while ((i < Neff(PlayerList)) && (!found))
				{
					j = 0;
					while (j < NeffBombs(Elmt(PlayerList, i)) && (!found))
						{
							if ((Absis(P) == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (Ordinat(P) == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
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

bool DangerBawah(POINT P)
{
	int a, b;
	int i, j;
	bool found, danger;
	danger = false;
	a = Absis(P);
	b = Ordinat(P);
	while ((b > 1) && (Block(GameMap, a, b) != '#') && (Block(GameMap, a, b) != '+') && (!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
	{
		b = b - 1;
	}
	if (b <= Height(GameMap))
	{
		danger = false;
	}
	else
	{
		if((Block(GameMap, a, b) != '#') && (Block(GameMap, a, b) != '+'))
		{
			danger = false;
		}
		else
		{
			if ((!IsNotCapital(Block(GameMap, a, b))) && !IsNumber((Block(GameMap, a, b))))
			{
				found = false;
				i = 0;
				while ((i < Neff(PlayerList)) && (!found))
				{
					j = 0;
					while (j < NeffBombs(Elmt(PlayerList, i)) && (!found))
						{
							if ((Absis(P) == Absis(BombLoc(Bombs(Elmt(PlayerList, i), j)))) && (Ordinat(P) == Ordinat(BombLoc(Bombs(Elmt(PlayerList, i), j)))))
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
bool InDanger(POINT P)
{
	return(DangerKanan(P) || DangerKiri(P) || DangerAtas(P) || DangerBawah(P) || (!IsNotCapital(Block(GameMap, Absis(P), Ordinat(P)))));
}

