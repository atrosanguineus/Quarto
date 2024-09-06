#ifndef MODULI_SUPPORTO_PROGETTI_QUARTOLIB_H_
#define MODULI_SUPPORTO_PROGETTI_QUARTOLIB_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <time.h>

#include "../Vettori/BaseVettori.h"
#include "../Matrici/BaseMatrici.h"
#include "../Matrici/OperazioniMatrici.h"
#include "../Files/CursesFiles.h"
#include "../Files/OperazioniFile.h"
#include "../Stringhe/OperazioniStringhe.h"
#include "../Utility/Utility.h"

#define MAXSERIAL 2047
#define MAXNAME 23
#define NUMPIECES 17
#define ENTER 13
#define LINE_FEED 10
#define BACKSPACE 8
#define STD_STR_SIZE 255
#define DEFAULT_PLAYERS 1
#define DEFAULT_LEVEL 2
#define SETTINGS_STARTING_ROW 8
#define SETTINGS_STARTING_COL 5
#define LOADS_STARTING_ROW 8
#define LOADS_STARTING_COL 26
#define SAVES_STARTING_ROW 3
#define SAVES_STARTING_COL 8
#define WINDOW_WIDTH 80
#define WINDOW_HEIGTH 25
#define SAVES_WIDTH 41
#define SAVES_HEIGHT 11
#define WIN_WIDTH 36
#define WIN_HEIGHT 11

typedef struct
{
	int players;
	int level;
}Settings;

typedef struct
{
	CMatrix image;
	int height;
	int colour;
	int shape;
	int consistency;
	int number;
	int status;
}Piece;

typedef struct
{
	int check;
	char* saveName;
	Settings set;
	Matrix board;
	Piece* pieces;
	int activePlayer;
	int activeStep;
	int turn;
}Game;

char* settingsFile;
char* savesFile;
char* rules1;
char* rules2;
char* rules3;

//INIZIALIZZAZIONI
int initCurse();
int localizeExe(char** argv);
Settings loadSettings();

//INTERFACCE
int showSettings(Settings set);
int showRules();
int page(char *index, int id);

int playerWon(int activePlayer, int players, int patta);

//MENU MINORI
int centerPrintString(int line, char* string);
int printTitle();
int showMenu();

int settings();
int settingsSelection();

int saveGame(Game* game);
int displaySaves(WINDOW* saveWindow, SVector names);
int actionSaves(WINDOW* saveWindow, Game* game, SVector names);
int writeSave(Game game, int slot);
Game deserialize(int slot);
char* serializeGame(Game game);

SVector getSaveNames();
int isLoadable(int slot);

Game loadGame();
int displayLoadGame(SVector svector);
Game actionLoadGame();

//INCAPSULAMENTO
int getPlayers(Settings set);
int getLevel(Settings set);
int setPlayers(Settings* set, int val);
int setLevel(Settings* set, int val);

Piece newPiece(CMatrix image, int height, int colour, int shape, int consistency, int number, int status);
CMatrix getImage(Piece piece);
int getHeight(Piece piece);
int getColour(Piece piece);
int getShape(Piece piece);
int getConsistency(Piece piece);
int getNumber(Piece piece);
int getStatus(Piece piece);
int setImage(Piece* piece, CMatrix image);
int setHeight(Piece* piece, int height);
int setColour(Piece* piece, int colour);
int setShape(Piece* piece, int shape);
int setConsistency(Piece* piece, int consistency);
int setNumber(Piece* piece, int number);
int setStatus(Piece* piece, int status);

Game newGame(int check, char* saveName, Settings set, Matrix board, Piece* unusedPieces, int startingPlayer, int activeStep, int turn);
int getCheck(Game game);
char* getSaveName(Game game);
Settings getSettings(Game game);
Matrix getBoard(Game game);
Piece* getPieces(Game game);
int getActivePlayer(Game game);
int getActiveStep(Game game);
int getTurn(Game game);
int setCheck(Game* game, int check);
int setSaveName(Game* game, char* name);
int setSettings(Game* game, Settings set);
int setBoard(Game* game, Matrix board);
int setPieces(Game* game, Piece* pieces);
int setActivePlayer(Game* game, int player);
int setActiveStep(Game* game, int step);
int setTurn(Game* game, int turn);

//UTILITY
int writeSettings(Settings set);

#endif /* MODULI_SUPPORTO_PROGETTI_QUARTOLIB_H_ */
