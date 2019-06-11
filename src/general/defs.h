#ifndef DEFS_H
#define DEFS_H

#include <limits>
#include <iostream>
#include <map>

using std::map;

typedef uint64_t U64;

const int INF = std::numeric_limits<int>::max();

const U64 PAWNSTART =
0b0000000011111111000000000000000000000000000000001111111100000000;
const U64 ROOKSTART =
0b1000000100000000000000000000000000000000000000000000000010000001;
const U64 KNIGHTSTART =
0b0100001000000000000000000000000000000000000000000000000001000010;
const U64 BISHOPSTART =
0b0010010000000000000000000000000000000000000000000000000000100100;
const U64 QUEENSTART =
0b0000100000000000000000000000000000000000000000000000000000001000;
const U64 KINGSTART =
0b0001000000000000000000000000000000000000000000000000000000010000;
const U64 ALLWHITESTART =
0b0000000000000000000000000000000000000000000000001111111111111111;
const U64 ALLBLACKSTART =
0b1111111111111111000000000000000000000000000000000000000000000000;

//Masking
const U64 ROWMASK[] = {
  0b0000000000000000000000000000000000000000000000000000000011111111,
  0b0000000000000000000000000000000000000000000000001111111100000000,
  0b0000000000000000000000000000000000000000111111110000000000000000,
  0b0000000000000000000000000000000011111111000000000000000000000000,
  0b0000000000000000000000001111111100000000000000000000000000000000,
  0b0000000000000000111111110000000000000000000000000000000000000000,
  0b0000000011111111000000000000000000000000000000000000000000000000,
  0b1111111100000000000000000000000000000000000000000000000000000000
};

//Clear
const U64 COLUMNCLEAR[] = {
  0b1111111011111110111111101111111011111110111111101111111011111110,
  0b1111110111111101111111011111110111111101111111011111110111111101,
  0b1111101111111011111110111111101111111011111110111111101111111011,
  0b1111011111110111111101111111011111110111111101111111011111110111,
  0b1110111111101111111011111110111111101111111011111110111111101111,
  0b1101111111011111110111111101111111011111110111111101111111011111,
  0b1011111110111111101111111011111110111111101111111011111110111111,
  0b0111111101111111011111110111111101111111011111110111111101111111,
};

const U64 BLANK =  0b0000000000000000000000000000000000000000000000000000000000000000;
const U64 FULL =   0b1111111111111111111111111111111111111111111111111111111111111111;

const U64 NOT_H_FILE = 0b0111111101111111011111110111111101111111011111110111111101111111;
const U64 NOT_GH_FILE = 0b0011111100111111001111110011111100111111001111110011111100111111;
const U64 NOT_A_FILE = 0b1111111011111110111111101111111011111110111111101111111011111110;
const U64 NOT_AB_FILE = 0b1111110011111100111111001111110011111100111111001111110011111100;

enum SquareIndices : int  {
  A1, B1, C1, D1, E1, F1, G1, H1,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A8, B8, C8, D8, E8, F8, G8, H8,
  Squarebegin = A1, SquareEnd = H8 + 1
};

enum Piecetype : int {
  EMPTY, bP, bR, bN, bB, bQ, bK, wP, wR, wN, wB, wQ, wK
};

enum Playertype : int {
  HUMAN, CPU
};

enum OPTION : int {
  PLAYER_VS_PLAYER = 1,
  PLAYER_VS_CPU,
  CPU_VS_CPU,
  EXIT,
  CREDITS
};

enum PieceColor : int {
  WHITE, BLACK
};


const int VictimScore[13] =
{ 0, 10, 40, 20, 30, 50, 60, 10, 40, 20, 30, 50, 60};
/**
 * @brief An empty bitboard. (ie. the number 0)
 */
const U64 ZERO = U64(0);

/**
 * @brief A bitboard containing only the square a1. (ie. the number 1)
 */
const U64 ONE = U64(1);
const int MAX_MOVES = 256;
const int MAX_DEPTH = 64;

// GLOBALS
extern U64 SetMask[64];
extern U64 ClearMask[64];

const int BitTable[64] = {
  63, 30, 3,  32, 25, 41, 22, 33,
  15, 50, 42, 13, 11, 53, 19, 34,
  61, 29, 2,  51, 21, 43, 45, 10,
  18, 47, 1,  54, 9,  57, 0,  35,
  62, 31, 40, 4,  49, 5,  52, 26,
  60, 6,  23, 44, 46, 27, 56, 16,
  7,  39, 48, 24, 59, 14, 12, 55,
  38, 28, 58, 20, 37, 17, 36, 8
};

const int RBits[64] = {
  12, 11, 11, 11, 11, 11, 11, 12,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  12, 11, 11, 11, 11, 11, 11, 12
};

const int BBits[64] = {
  6, 5, 5, 5, 5, 5, 5, 6,
  5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 7, 7, 7, 7, 5, 5,
  5, 5, 7, 9, 9, 7, 5, 5,
  5, 5, 7, 9, 9, 7, 5, 5,
  5, 5, 7, 7, 7, 7, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5,
  6, 5, 5, 5, 5, 5, 5, 6
};

const int KnightTable[64] = {
  -10, -2, -3, -3, -3, -3, -2, -10,
  -4, -2, 0, 0, 0, 0, -2, -2,
  -3, 0, 5, 3, 3, 5, 0, -3,
  -3, 1, 2, 6, 6, 2, 1, -3,
  -3, 0, 2, 6, 6, 2, 0, -3,
  -3, 1, 5, 6, 6, 5, 1, -3,
  -4, -2, 0, 1, 1, 0, -2, -2,
  -10, -4, -3, -3, -3, -3, -4, -10,
};

const int PawnTable[64] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  2, 2, 0, -2, -2, 0, 2, 2,
  1, 0, 0, 1, 1, 0, 0, 1,
  0, 0, 2, 6, 6, 2, 0, 0,
  1, 1, 1, 2, 2, 1, 1, 1,
  2, 2, 2, 4, 4, 2, 2, 2,
  4, 4, 4, 6, 6, 4, 4, 4,
  9, 9, 9, 9, 9, 9, 9, 9
};

const int BishopTable[64] = {
  -4, -2, -2, -2, -2, -2, -2, -4,
  -2, 0, 0, 0, 0, 0, 0, -2,
  -2, 0, 1, 2, 2, 1, 0, -2,
  -2, 1, 1, 2, 2, 1, 1, -2,
  -2, 0, 2, 2, 2, 2, 0, -2,
  -2, 2, 2, 2, 2, 2, 2, -2,
  -2, 1, 0, 0, 0, 0, 1, -2,
  -4, -2, -2, -2, -2, -2, -2, -4,
};

const int RookTable[64] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  1, 2, 2, 2, 2, 2, 2, 1,
  -1, 0, 1, 1, 1, 1, 0, -1,
  -1, 0, 1, 2, 2, 1, 0, -1,
  -1, 0, 1, 2, 2, 1, 0, -1,
  -1, 0, 1, 1, 1, 1, 0, -1,
  -1, 0, 3, 3, 3, 3, 0, -1,
   0, 0, 0, 1, 1, 0, 0, 0
};

const int QueenTable[64] = {
  //queen
  -4, -2, -2, -1, -1, -2, -2, -4,
  -2, 0, 0, 0, 0, 0, 0, -2,
  -2, 0, 1, 1, 1, 1, 0, -2,
  -1, 0, 1, 1, 1, 1, 0, -1,
   0, 0, 1, 1, 1, 1, 0, -1,
  -2, 1, 1, 1, 1, 1, 0, -2,
  -2, 0, 1, 0, 0, 0, 0, -2,
  -4, -2, -2, -1, -1, -2, -2, -4
};

const int MIRROR64[64] = {
  56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 ,
  48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 ,
  40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 ,
  32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 ,
  24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 ,
  16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 ,
  8 , 9, 10 , 11 , 12 , 13 , 14 , 15 ,
  0 , 1, 2  , 3 ,  4 , 5 , 6  , 7
};

const map<Piecetype, std::string> piece_str_name  {
  {bP, "pawn"}, {bR, "rook"}, {bN, "knight"},
  {bB, "bishop"}, {bQ, "queen"}, {bK, "king"},
  {wP, "pawn"}, {wR, "rook"}, {wN, "knight"},
  {wB, "bishop"}, {wQ, "queen"}, {wK, "king"}
};

#endif /* DEFS_H */