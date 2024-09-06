#ifndef MODULI_SUPPORTO_PROGETTI_QUARTOGAME_H_
#define MODULI_SUPPORTO_PROGETTI_QUARTOGAME_H_

#include "QuartoLib.h"

#define TALL 1
#define SHORT 0
#define WHITE 1
#define BLACK 0
#define SQUARE 1
#define ROUND 0
#define FULL 1
#define EMPTY 0
#define FREE 0
#define PLACED 1
#define SELECTED 2
#define CHOOSING 0
#define POSITIONING 1
#define LOCAL_PLAYER 0
#define ENEMY_OR_AI 1

typedef struct
{
	int heuristicValue;
	int y;
	int x;
	int moveNumber;
}Move;

typedef struct
{
	Move bestMove;
	Move worseMove;
}BoardAnalysis;

//GESTIONE PEZZI
CMatrix createImage(int height, int colour, int shape, int consistency);
Piece* createPieces();
Piece lookUp(Piece* pieces, int number);
Piece findSelected(Piece* pieces);

//MAIN MENU
int getSelection();
int followSelection(int choice);
int enterMenu();

//GESTIONE PARTITE
Game newStdGame();

int showBoard(int dim, int intervalSpecial);
int showRosterPieces(Piece* pieces);
int showBoardPieces(Piece* pieces, Matrix board);
int showConsoleMessage(Game game);
int refreshGame(Game game);

int newPlay(Game* game);
int followGameInput(Game* game, int* lasty, int* lastx);
int evaluateInput(char* input, Game* game, int* lasty, int* lastx);

Piece callAI(Matrix board, Game* game, int selectedNum);
BoardAnalysis analyzeMove (Matrix board, Game game, int incomingPiece, Piece* pieces);
int heuristic(Matrix virtualBoard, Piece* pieces, Settings settings, int pieceNumber, int i, int j);
int lineHControl(int line, Piece* pieces, Matrix virtualBoard, int pieceNumber);
int verticalHControl(int line, Piece* pieces, Matrix virtualBoard, int pieceNumber);
int diagonHControl(Piece* pieces, Matrix virtualBoard, int pieceNumber);
int paraHDiagControl(Piece* pieces, Matrix virtualBoard, int pieceNumber);
int squareHControl(Piece* pieces, Matrix virtualBoard, int pieceNumber, int y, int x);
Vector commonAttrs(Piece* piecesNow, int found);
int areCommonsMoreThan(Vector commons, int this);
int areCommonsEqualTo(Vector commons, int this);
int isPieceInFound(int pieceNumber, Piece* piecesNow, int found );
Move emptyMove();
int isPatta(Piece* pieces);

//INCAPSULAMENTO
int getHeuristicValue(Move move);
int getYMove(Move move);
int getXMove(Move move);
int getMoveNumber(Move move);
int setHeuristicValue(Move* move, int value);
int setYMove(Move* move, int value);
int setXMove(Move* move, int value);
int setMoveNumber(Move* move, int value);

Move getBestMove(BoardAnalysis result);
Move getWorseMove(BoardAnalysis result);
int setBestMove(BoardAnalysis* result, Move value);
int setWorseMove(BoardAnalysis* result, Move value);

//ANALISI BOARD
int isVictory (Matrix currentBoard, Piece* pieces, int level, int settedy, int settedx );
int lineControl (Matrix currentBoard, Piece* pieces, Piece startingPiece, int settedy);
int verticalLineControl (Matrix currentBoard, Piece* pieces, Piece startingPiece, int settedx);
int secondaryDiagonalControl (Matrix currentBoard, Piece* pieces, Piece startingPiece, int settedx, int settedy);
int diagonalControl (Matrix currentBoard, Piece* pieces, Piece startingPiece, int settedx,int settedy);
int squareControl(Matrix currentBoard, Piece* pieces, Piece startingPiece, int settedx, int settedy);
int chkBetweenPieces(Piece startingPiece, Piece next1, Piece next2, Piece next3);
int chkUpLeft(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx);
int chkUpRight(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx);
int chkDownLeft(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx);
int chkDownRight(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx);

//UTILITY
int randomTests(); //FUNZIONE PER DEBUGGING


#endif /* MODULI_SUPPORTO_PROGETTI_QUARTOGAME_H_ */
