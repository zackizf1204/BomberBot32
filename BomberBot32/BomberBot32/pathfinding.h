#pragma once

#include "tipe.h"
#include "mapreader.h"
#include <random>

#ifndef PATHFINDING_H
#define PATHFINDING_H

bool DangerKanan(POINT P);
/*hanya untuk keperluan fungsi InDanger*/
bool DangerKiri(POINT P);
/*hanya untuk keperluan fungsi InDanger*/
bool DangerAtas(POINT P);
/*hanya untuk keperluan fungsi InDanger*/
bool DangerBawah(POINT P);
/*hanya untuk keperluan fungsi InDanger*/
bool InDanger(POINT P);
/*true jika P dalam radius ledakan bom*/
int Kabur(POINT p);
/*mengembalikan kode gerakan yang harus dilakukan untuk kabur dari titik p*/
/*prekondisi : titik p tidak aman (InDanger(p)==true)*/
void Kabur2(POINT p, int d, deque<POINT>& safe, deque<POINT>& notsafe);
/*hanya untuk keperluan fungsi Kabur*/
#endif