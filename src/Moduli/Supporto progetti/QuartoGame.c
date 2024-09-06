#include "QuartoGame.h"

/***********************************************
 Nome: createImage;
 Input: Interi esprimenti altezza, colore, forma e consistenza di una pedina.
 Cosa fa: Genera una matrice di caratteri per un pezzo con le caratteristiche in input.

 Ritorna: CMatrix, matrice di caratteri @BaseMatrici.h
 ***********************************************/

CMatrix createImage(int height, int colour, int shape, int consistency)
{
	/*
	 * |"_"|
	 * |   |
	 * |   |
	 * |###|
	 */

	CMatrix image = creaCMatrice(4, 5);
	fillBlank(&image);

	if( height == TALL )
	{
		scriviCMatrice(&image, 0, 0, '|');
		scriviCMatrice(&image, 1, 0, '|');
		scriviCMatrice(&image, 2, 0, '|');
		scriviCMatrice(&image, 3, 0, '|');
		scriviCMatrice(&image, 0, 4, '|');
		scriviCMatrice(&image, 1, 4, '|');
		scriviCMatrice(&image, 2, 4, '|');
		scriviCMatrice(&image, 3, 4, '|');
	}
	else if( height == SHORT )
	{
		scriviCMatrice(&image, 1, 0, '|');
		scriviCMatrice(&image, 2, 0, '|');
		scriviCMatrice(&image, 3, 0, '|');
		scriviCMatrice(&image, 1, 4, '|');
		scriviCMatrice(&image, 2, 4, '|');
		scriviCMatrice(&image, 3, 4, '|');
	}

	if( colour == WHITE )
	{
		scriviCMatrice(&image, 3, 1, '#');
		scriviCMatrice(&image, 3, 2, '#');
		scriviCMatrice(&image, 3, 3, '#');
	}
	else if( colour == BLACK)
	{
		scriviCMatrice(&image, 3, 1, '_');
		scriviCMatrice(&image, 3, 2, '_');
		scriviCMatrice(&image, 3, 3, '_');
	}

	if( shape == ROUND && height == TALL )
	{
		scriviCMatrice(&image, 0, 0, '/');
		scriviCMatrice(&image, 0, 4, '\\');
		scriviCMatrice(&image, 3, 0, '\\');
		scriviCMatrice(&image, 3, 4, '/');
	}
	else if( shape == ROUND && height == SHORT )
	{
		scriviCMatrice(&image, 1, 0, '/');
		scriviCMatrice(&image, 1, 4, '\\');
		scriviCMatrice(&image, 3, 0, '\\');
		scriviCMatrice(&image, 3, 4, '/');
	}

	if( consistency == FULL && height == TALL)
	{
		scriviCMatrice(&image, 0, 1, '"');
		scriviCMatrice(&image, 0, 2, '"');
		scriviCMatrice(&image, 0, 3, '"');
	}
	else if( consistency == FULL && height == SHORT )
	{
		scriviCMatrice(&image, 1, 1, '"');
		scriviCMatrice(&image, 1, 2, '"');
		scriviCMatrice(&image, 1, 3, '"');
	}
	else if( consistency == EMPTY && height == TALL )
	{
		scriviCMatrice(&image, 0, 1, '"');
		scriviCMatrice(&image, 0, 2, '_');
		scriviCMatrice(&image, 0, 3, '"');
	}
	else if( consistency == EMPTY && height == SHORT )
	{
		scriviCMatrice(&image, 1, 1, '"');
		scriviCMatrice(&image, 1, 2, '_');
		scriviCMatrice(&image, 1, 3, '"');
	}

	return image;
}

/***********************************************
 Nome: createPieces();
 Input: Nulla.
 Cosa fa: Genera il vettore di pezzi standard da utilizzare in un gioco.

 Ritorna: Vettore di pezzi standard.
 ***********************************************/

Piece* createPieces()
{
	Piece* pieces = malloc( 17*sizeof(Piece) );
	CMatrix cmat = creaCMatrice(4, 5);

	Piece p0 = newPiece(cmat, 5, 5, 5, 5, 0, 5);
	Piece p1 = newPiece(createImage(TALL,WHITE,SQUARE,FULL),TALL,WHITE,SQUARE,FULL,1, FREE);
	Piece p2 = newPiece(createImage(TALL,WHITE,SQUARE,EMPTY),TALL,WHITE,SQUARE,EMPTY,2, FREE);
	Piece p3 = newPiece(createImage(TALL,WHITE,ROUND,FULL),TALL,WHITE,ROUND,FULL,3, FREE);
	Piece p4 = newPiece(createImage(TALL,WHITE,ROUND,EMPTY),TALL,WHITE,ROUND,EMPTY,4, FREE);
	Piece p5 = newPiece(createImage(TALL,BLACK,SQUARE,FULL),TALL,BLACK,SQUARE,FULL,5, FREE);
	Piece p6 = newPiece(createImage(TALL,BLACK,SQUARE,EMPTY),TALL,BLACK,SQUARE,EMPTY,6, FREE);
	Piece p7 = newPiece(createImage(TALL,BLACK,ROUND,FULL),TALL,BLACK,ROUND,FULL,7, FREE);
	Piece p8 = newPiece(createImage(TALL,BLACK,ROUND,EMPTY),TALL,BLACK,ROUND,EMPTY,8, FREE);
	Piece p9 = newPiece(createImage(SHORT,WHITE,SQUARE,FULL),SHORT,WHITE,SQUARE,FULL,9, FREE);
	Piece p10 = newPiece(createImage(SHORT,WHITE,SQUARE,EMPTY),SHORT,WHITE,SQUARE,EMPTY,10, FREE);
	Piece p11 = newPiece(createImage(SHORT,WHITE,ROUND,FULL),SHORT,WHITE,ROUND,FULL,11, FREE);
	Piece p12 = newPiece(createImage(SHORT,WHITE,ROUND,EMPTY),SHORT,WHITE,ROUND,EMPTY,12, FREE);
	Piece p13 = newPiece(createImage(SHORT,BLACK,SQUARE,FULL),SHORT,BLACK,SQUARE,FULL,13, FREE);
	Piece p14 = newPiece(createImage(SHORT,BLACK,SQUARE,EMPTY),SHORT,BLACK,SQUARE,EMPTY,14, FREE);
	Piece p15 = newPiece(createImage(SHORT,BLACK,ROUND,FULL),SHORT,BLACK,ROUND,FULL,15, FREE);
	Piece p16 = newPiece(createImage(SHORT,BLACK,ROUND,EMPTY),SHORT,BLACK,ROUND,EMPTY,16, FREE);

	pieces[0] = p0;
	pieces[1] = p1;
	pieces[2] = p2;
	pieces[3] = p3;
	pieces[4] = p4;
	pieces[5] = p5;
	pieces[6] = p6;
	pieces[7] = p7;
	pieces[8] = p8;
	pieces[9] = p9;
	pieces[10] = p10;
	pieces[11] = p11;
	pieces[12] = p12;
	pieces[13] = p13;
	pieces[14] = p14;
	pieces[15] = p15;
	pieces[16] = p16;

	return pieces;
}

/***********************************************
 Nome: lookUp;
 Input: Vettore di pezzi pieces, intero number.
 Cosa fa: Ritorna il pezzo con numero number.

 Ritorna: Piece, tipo pezzo @QuartoLib.h
 ***********************************************/

Piece lookUp(Piece* pieces, int number)
{
	if( number >= 0 && number <= 16 )
	{
		return pieces[number];
	}

	return pieces[0];
}

/***********************************************
 Nome: findSelected;
 Input: Vettore di pezzi pieces.
 Cosa fa: Trova il pezzo correntemente selezionato all'interno del vettore pieces.

 Ritorna: Piece, tipo pezzo @QuartoLib.h
 ***********************************************/

Piece findSelected(Piece* pieces)
{
	int i = 0;
	while( i <= 16 )
	{
		if( getStatus( pieces[i] ) == SELECTED )
		{
			return pieces[i];
		}

		i = i + 1;
	}

	return pieces[0];
}

/////////////////////////////////////////
////////////////////////// MAIN MENU

/***********************************************
 Nome: getSelection;
 Input: Input da tastiera interno alla funzione.
 Cosa fa: Prende in input un tasto da tastiera finché non è ESC oppure un numero tra 0 e 5.

 Ritorna: ASCII del tasto confermato oppure 0 se ESC premuto.
 ***********************************************/

int getSelection()
{
	int asciiChoice;
	int numChoice;

	do
	{
		asciiChoice = getch();
		numChoice = asciiChoice - 48;
	}
	while( ((numChoice < 0) || (numChoice > 5)) && asciiChoice != 27 );


	if( asciiChoice == 27 )
	{
		return 0;
	}
	else
	{
		return numChoice;
	}
}

/***********************************************
 Nome: followSelection;
 Input: Intero choice.
 Cosa fa: Seleziona la funzione del menu principale da eseguire in base a choice.

 Ritorna: 1 se procede all'interno di una funzione, 0 se si esce dal programma. Default: 1.
 ***********************************************/

int followSelection(int choice)
{
	if( choice == 1 )
	{
		Game game = newStdGame();
		newPlay(&game);
		return 1;
	}

	else if( choice == 2 )
	{
		Game game = loadGame();

		if( getCheck(game) )
		{
			newPlay(&game);
		}
		return 1;
	}

	else if( choice == 3 )
	{
		settings();
		return 1;
	}

	else if( choice == 4 )
	{
		showRules();
		return 1;
	}

	else if( choice == 0 )
	{
		return 0;
	}

	return 1;
}

/***********************************************
 Nome: enterMenu;
 Input: Nulla.
 Cosa fa: Itera la selezione di voci del menù finché un carattere valido non è premuto.

 Ritorna: 1 quando esce dall'iterazione.
 ***********************************************/

int enterMenu()
{
//	attron(A_BOLD);
	int choice;

	do
	{
		clear();
		showMenu();
		choice = getSelection();
	}
	while( followSelection(choice) != 0 );
//	attroff(A_BOLD);
	return 1;
}

/////////////////////////////////////////
//////////////////////// GESTIONE PARTITE

/***********************************************
 Nome: newStdGame;
 Input: Nulla.
 Cosa fa: Genera il Game di default con le impostazioni corrent.

 Ritorna: Game, tipo gioco @QuartoLib.h
 ***********************************************/

Game newStdGame()
{
	int firstPlayer = rand() % 2;
	Piece* pieces = createPieces();
	Settings set = loadSettings();
	Matrix mat = creaMatrice(4, 4);
	Game game = newGame(1, NULL, set, mat, pieces, firstPlayer, CHOOSING, 1);
	return game;
}

/////

/***********************************************
 Nome: showBoard;
 Input: Intero dim, Intero intervalSpecial.
 Cosa fa: Genera una scacchiera di dimensioni dim con suddivisioni interne ogni intervalSpecial caratteri.

 Ritorna: 1 avvenuta la generazione.
 ***********************************************/

int showBoard(int dim, int intervalSpecial)
{
	attron(A_ALTCHARSET);

	move(0, 3);
	char topLine[dim + 1];
	char downLine[dim + 1];
	char midLine[dim + 1];
	char bottomLine[dim + 1];

	int i = 0;
	while( i < dim )
	{
		if( i == 0 )
		{
			topLine[i] = (char) ACS_ULCORNER;
		}
		else if( i == dim -1 )
		{
			topLine[i] = (char) ACS_URCORNER;
		}
		else if( i % intervalSpecial == 0)
		{
			topLine[i] = (char) ACS_TTEE;
		}
		else
		{
			topLine[i] = (char) ACS_HLINE;
		}

		i = i + 1;
	}
	topLine[dim] = '\0';

	i = 0;
	while( i < dim )
	{
		if( i == 0 )
		{
			downLine[i] = (char) ACS_VLINE;
		}
		else if( i == dim - 1 )
		{
			downLine[i] = (char) ACS_VLINE;
		}
		else if( i % intervalSpecial == 0)
		{
			downLine[i] = (char) ACS_VLINE;
		}
		else
		{
			downLine[i] = ' ';
		}

		i = i + 1;
	}
	downLine[dim] = '\0';

	i = 0;
	while( i < dim )
	{
		if( i == 0 )
		{
			midLine[i] = (char) ACS_LTEE;
		}
		else if( i == dim - 1 )
		{
			midLine[i] = (char) ACS_RTEE;
		}
		else if( i % intervalSpecial == 0)
		{
			midLine[i] = (char) ACS_PLUS;
		}
		else
		{
			midLine[i] = (char)  ACS_HLINE;
		}

		i = i + 1;
	}
	midLine[dim] = '\0';

	i = 0;
	while( i < dim )
	{
		if( i == 0 )
		{
			bottomLine[i] = (char) ACS_LLCORNER;
		}
		else if( i == dim - 1 )
		{
			bottomLine[i] = (char) ACS_LRCORNER;
		}
		else if( i % intervalSpecial == 0)
		{
			bottomLine[i] = (char)  ACS_BTEE;
		}
		else
		{
			bottomLine[i] = (char) ACS_HLINE;
		}

		i = i + 1;
	}
	bottomLine[dim] = '\0';

	int y, x;
	i = 0;
	while( i < 21 )
	{
		getyx(stdscr, y, x);

		if( i == 0 )
		{
			addstr(topLine);
			move(y + 1, x);
		}
		else if( i == 21 -1 )
		{
			addstr(bottomLine);
			move(y + 1, x);
		}
		else if( i % 5 == 0)
		{
			addstr(midLine);
			move(y + 1, x);
		}
		else
		{
			addstr(downLine);
			move(y + 1, x);
		}

		i = i + 1;
	}

	attroff(A_ALTCHARSET);
	mvaddch(3,1,'A');
	mvaddch(8,1,'B');
	mvaddch(13,1,'C');
	mvaddch(18,1,'D');

	mvaddch(21,7,'1');
	mvaddch(21,15,'2');
	mvaddch(21,23,'3');
	mvaddch(21,31,'4');

	int j = 0;
	while( j < 2 )
	{
		i = 0;
		while( i < 22 )
		{
			mvaddch(i, 38 + j, '|');
			i = i + 1;
		}
		j = j + 1;
	}

	refresh();
	return 1;
}

/***********************************************
 Nome: showRosterPieces;
 Input: Vettore di pezzi pieces.
 Cosa fa: Stampa a video i pezzi ancora liberi basandosi sul getStatus() di ogni pezzo.
 	 	  Condizione: Se pezzo non piazzato, stampa normalmente. Se è selezionato, stampaci attorno una linea di selezione.

 Ritorna: 1 avvenuta la stampa.
 ***********************************************/

int showRosterPieces(Piece* pieces)
{
	int y, x;
	move(1, 45);

	CMatrix image;
	Piece tempPiece;

	int counter = 1;
	int j = 0;
	while( j < 4)
	{
		int i = 1;
		while( i <= 4 )
		{
			getyx(stdscr, y, x);
			tempPiece = pieces[j*4 + i];

			if( getStatus(tempPiece) != PLACED )
			{
				image = getImage(tempPiece);
				printaCURSCMatrice(image, 0, 1);
				move(y, x-2);
				printw(intWithZeroes(counter, 2));
			}
			if( getStatus(tempPiece) == SELECTED )
			{
				move(y - 1, x - 3);
				printCornice(4, 7);
			}

			if( i == 4 )
			{
				move(y + 5, x - 27);
			}
			else
			{
				move(y, x + 9);
			}

			i = i + 1;
			counter = counter + 1;
		}
		j = j + 1;
	}

	refresh();
	return 1;
}

/***********************************************
 Nome: showBoardPieces;
 Input: Vettore di pezzi pieces, Matrice di interi board.
 Cosa fa: Stampa i pezzi nella scacchiera.
 	 	  Condizione: Se la scacchiera nella posizione i-j è occupata, stampa l'immagine del pezzo che la occupa.

 Ritorna: 1 a generazione finita.
 ***********************************************/

int showBoardPieces(Piece* pieces, Matrix board)
{
	CMatrix image;
	Piece tempPiece;
	int selection;
	int y, x;
	move(1, 5);

	int i = 0;
	while( i < getYMatrice(board) )
	{
		int j = 0;
		while( j < getXMatrice(board) )
		{
			getyx(stdscr, y, x);
			selection = leggiMatrice(board, i, j);
			if( selection > 0 && selection <= 16)
			{
				tempPiece = lookUp(pieces, selection);
				image = getImage(tempPiece);
				printaCURSCMatrice(image, 0, 1);
			}

			move(y, x + 8);
			j = j + 1;
		}

		move(y + 5, x - 24);
		i = i + 1;
	}

	refresh();
	return 1;
}

/***********************************************
 Nome: showConsoleMessage;
 Input: Game game.
 Cosa fa: Aggiorna il messaggio nella console in base al numero di giocatori, lo step corrente ed il giocatore corrente.

 Ritorna: 1 a stampa terminata.
 ***********************************************/

int showConsoleMessage(Game game)
{
	move(23, 1);

	int players = getPlayers( getSettings(game) );
	int step = getActiveStep(game);
	int currPlayer = getActivePlayer(game);

	if( step == CHOOSING )
	{
		if( currPlayer == LOCAL_PLAYER )
		{
			addstr("Giocatore 1, scegli una pedina da dare all'avversario: ");
		}
		else if( currPlayer == ENEMY_OR_AI && players == 2 )
		{
			addstr("Giocatore 2, scegli una pedina da dare all'avversario: ");
		}
		else
		{
			addstr("L'AI sta scegliendo! ");
		}
	}

	else
	{
		if( currPlayer == LOCAL_PLAYER )
		{
			addstr("Giocatore 1, inserisci le coordinate in cui piazzare: ");
		}
		else if( currPlayer == ENEMY_OR_AI && players == 2 )
		{
			addstr("Giocatore 2, inserisci le coordinate in cui piazzare: ");
		}
		else
		{
			addstr("L'AI sta piazzando! ");
		}
	}

	return 1;
}

/***********************************************
 Nome: refreshGame;
 Input: Game game.
 Cosa fa: Aggiorna l'intera schermata (scacchiera, pezzi non usati, pezzi usati e console.
 	 	  Utile per il carica partita.

 Ritorna: 1 ad aggiornamento terminato.
 ***********************************************/

int refreshGame(Game game)
{
	clear();
	Piece* pieces = getPieces(game);
	showBoard(33, 8);
	showRosterPieces(pieces);
	showBoardPieces(pieces, getBoard(game));
	showConsoleMessage(game);
	refresh();
	return 1;
}

///////////

/***********************************************
 Nome: newPlay;
 Input: Game game.
 Cosa fa: Funzione cardine del gioco. Entra in followGameInput se è il turno di un utente;
 	 	  Richiede l'AI nel caso sia il suo turno.
 	 	  Controlla se l'ultima mossa è risultata in vittoria. Se sì, vince il giocatore ad averla effettuata.
 	 	  Se il gioco è patta, non vince nessuno.
 	 	  newPlay itera fino alla vittoria di qualcuno o alla pressione di ESC da parte di un utente.

 Ritorna: 1 se gioco terminato da un utente.
 ***********************************************/

int newPlay(Game* game)
{
	Settings set;
	Matrix board;
	Piece* pieces = getPieces(*game);
	Piece incomingPiece;
	int activeStep;
	int lasty = 0;
	int lastx = 0;
	int players = getPlayers( getSettings(*game) );
	int patta = isPatta(pieces);
	int currPlayer;
	int sigKill;

	do
	{
		activeStep = getActiveStep(*game);
		currPlayer = getActivePlayer(*game);

		refreshGame(*game);

		if( players == 2 || currPlayer == LOCAL_PLAYER )
		{
			sigKill = followGameInput(game, &lasty, &lastx);
		}
		else if( players == 1 && currPlayer == ENEMY_OR_AI)
		{
			if( activeStep == CHOOSING )
			{
				callAI(board, game, 0);
				setActiveStep(game, !activeStep);
			}
			else if( activeStep == POSITIONING )
			{
				incomingPiece = findSelected(pieces);
				callAI(board, game, getNumber(incomingPiece) );

			}
			setActivePlayer(game, !currPlayer);
		}

		board = getBoard(*game);
		pieces = getPieces(*game);
		set = getSettings(*game);
		patta = isPatta(pieces);

		if( isVictory(board, pieces, getLevel(set), lasty, lastx) || patta )
		{
			refreshGame(*game);
			playerWon(currPlayer, players, patta);
			getch();
			return 1;
		}
	}
	while( sigKill != 27 );
	return 1;
}

/***********************************************
 Nome: followGameInput;
 Input: Puntatore a Game game, puntatore a intero lasty, puntatore a intero lastx.
 Cosa fa: L'input utente è reso sicuro da followGameInput.
 	 	  Questa funzione simula l'inserimento di una stringa leggendo carattere per carattere.
 	 	  Potendo fare controlli sulle singole pressioni, followGameInput può impedire di superare certi limiti di caratteri
 	 	  oppure di inserire caratteri illegali. La pressione di ENTER manda la stringa costruita in valutazione.
 	 	  writeHead agisce da "testina" sulla stringa in formazione, permettendo la cancellatura mediante backspace.

 Ritorna: 27 se ESC premuto, 1 se terminata normalmente.
 ***********************************************/

int followGameInput(Game* game, int* lasty, int* lastx)
{
	curs_set(1);

	int y, x;
	getyx(stdscr, y, x);

	int input;
	int writeHead = 0;
	char* evalStr = malloc( STD_STR_SIZE * sizeof(char) );

	do
	{
		input = getch();

		if( (char) input == 'S' )
		{
			saveGame(game);
			refreshGame(*game);
		}

		else if( input == BACKSPACE && writeHead > 0 )
		{
			writeHead = writeHead - 1;
			evalStr[writeHead] = '\0';
		}

		else if( isalnum(input) && writeHead >= 0 && writeHead < 2)
		{
			evalStr[writeHead] = (char) input;
			writeHead = writeHead + 1;
			evalStr[writeHead] = '\0';
		}
		else if( input == LINE_FEED || input == ENTER )
		{
			move(y, x);
			addstr("  ");
			refresh();
			evaluateInput(evalStr, game, lasty, lastx);
			return 1;
		}

		move(y, x);
		addstr("  ");
		move(y, x);
		addstr(evalStr);
	}
	while( input != 27 || input == LINE_FEED || input == ENTER );

	curs_set(0);

	if( input == 27 )
	{
		return 27;
	}
	return 1;
}

/***********************************************
 Nome: evaluateInput;
 Input: Stringa in input, Puntatore a Game game, puntatore a intero lasty, puntatore a intero lastx, intero AIGift.
 Cosa fa: Genera una matrice di caratteri per un pezzo con le caratteristiche in input.

 Ritorna: CMatrix, matrice di caratteri @BaseMatrici.h
 ***********************************************/

int evaluateInput(char* input, Game* game, int* lasty, int* lastx)
{
	int turns = getTurn(*game);
	int activePlayer = getActivePlayer(*game);
	int activeStep = getActiveStep(*game);
	Piece* pieces = getPieces(*game);
	Piece selected;

	if( activeStep == CHOOSING )
	{
		int pieceNum = atoi(input);
		if( pieceNum > 0 && pieceNum <= 16 )
		{
			Piece selected = lookUp( pieces, pieceNum);
			if( getStatus(selected) == FREE )
			{
				setStatus(&selected, SELECTED);

				pieces[pieceNum] = selected;
				setPieces(game, pieces);

				setActiveStep(game, !activeStep);
				setActivePlayer(game, !activePlayer);

				setTurn(game, turns + 1);
			}
		}
	}
	else if( activeStep == POSITIONING )
	{
		Matrix board = getBoard(*game);
		int letterOK = 0;
		int numberOK = 0;

		int letter = (int) input[0];
		int number = (int) input[1] - '0';

		//Se la lettera e' tra A e D o tra a e d
		if( letter >= 65 && letter <= 68)
		{
			letter = letter - 17 - 48;
			letterOK = 1;
		}
		else if( letter >= 97 && letter <= 100 )
		{
			letter = letter - 49 - 48;
			letterOK = 1;
		}

		if( number >= 1 && number <= 4 )
		{
			numberOK = 1;
		}

		if( numberOK && letterOK )
		{
			selected = findSelected(pieces);

			int selectedNum = getNumber(selected);

			if( !leggiMatrice(board, letter, number - 1) )
			{
				scriviMatrice(&board, letter, number - 1, selectedNum);
				setStatus(&selected, PLACED);

				pieces[selectedNum] = selected;
				setPieces(game, pieces);
				setBoard(game, board);

				setActiveStep(game, !activeStep);
				*lasty = letter;
				*lastx = number - 1;
			}
		}
	}
	return 1;
}

/////
/***********************************************
 Nome: callAI;
 Input: Matrix board, Puntatore a Game game, intero incomingPiece
 Cosa fa: Descritta nello pseudo consegnato in precedenza

 Ritorna: Il pezzo da lei scelto (per motivi di Debug, in realtà il solo selezionare un pezzo vale come "scelta" agli occhi del programma)
 ***********************************************/

Piece callAI(Matrix board, Game* game, int incomingPiece)
{
	Piece* pieces = getPieces(*game);
	Piece setter;
	Piece toGift;
	Move chosenMove;
	Move worseMove;
	BoardAnalysis result;

	if (getTurn(*game)==1 && incomingPiece == 0 )
	{
		int cardinal = rand()%16 + 1;
		toGift = lookUp(pieces, cardinal);
		setStatus(&toGift, SELECTED);
		pieces[cardinal] = toGift;
		return toGift;
	}

	if (getTurn(*game)==2)
	{
		scriviMatrice(&board, rand()%2 +1, rand()%2 +1, incomingPiece);
		setter = lookUp(pieces, incomingPiece);
		setStatus(&setter, PLACED);
		pieces[incomingPiece] = setter;

		int chosenOne;
		do
		{
			chosenOne = rand()%16+1;
		}
		while( getStatus( lookUp(pieces, chosenOne) ) != FREE );

		toGift = lookUp(pieces, chosenOne);
		setStatus(&toGift, SELECTED);
		pieces[chosenOne] = toGift;

		return toGift;
	}

	result = analyzeMove(board, *game, incomingPiece, pieces);
	chosenMove = getBestMove(result);
	worseMove = getWorseMove(result);

	int chosenNumber = getMoveNumber(chosenMove);
	int worseNumber = getMoveNumber(worseMove);

	scriviMatrice(&board, getYMove(chosenMove), getXMove(chosenMove), chosenNumber);
	setter = lookUp(pieces, chosenNumber);
	setStatus(&setter, PLACED);
	pieces[chosenNumber] = setter;

	setter = lookUp(pieces, worseNumber);
	setStatus(&setter, SELECTED);
	pieces[worseNumber] = setter;

	return lookUp(pieces, worseNumber);
}

/***********************************************
 Nome: analyzeMove;
 Input: Matrix board, Puntatore a Game game, intero incomingPiece, Vettore di pezzi pieces
 Cosa fa: Descritto nello pseudo consegnato in precedenza.

 Ritorna: L'analisi della mossa migliore e peggiore.
 ***********************************************/

BoardAnalysis analyzeMove (Matrix board, Game game, int incomingPiece, Piece* pieces)
{
	Settings set = getSettings(game);
	BoardAnalysis result;
	Move bestMove = emptyMove();
	Move worseMove = emptyMove();
	setBestMove(&result, bestMove);
	setWorseMove(&result, worseMove);

	Piece currentPiece;
	int boardValue;

	setHeuristicValue(&bestMove, -1000);
	setHeuristicValue(&worseMove, 1000);

	int checkingPiece = 1;
	while (checkingPiece <= 16)
	{
		currentPiece = lookUp(pieces, checkingPiece);

		if (getStatus(currentPiece) != PLACED )
		{

			int i=0;
			while (i < getYMatrice(board) )
			{
				int j=0;
				while (j < getXMatrice(board) )
				{
					int pieceOnCoords = leggiMatrice(board, i, j);
					if( pieceOnCoords == 0 )
					{
//						addstr("y");
//						refresh();

						Matrix virtualBoard = copiaMatrice(board);
						int pieceNumber = getNumber(currentPiece);
						scriviMatrice(&virtualBoard, i, j, pieceNumber );
						boardValue = heuristic(virtualBoard, pieces, set, pieceNumber, i, j);

//						printw("(%dc,%di)", checkingPiece, incomingPiece);
//						refresh();
//						getch();

						if (boardValue > getHeuristicValue(bestMove) && ( getNumber(currentPiece) == incomingPiece ))
						{
							setHeuristicValue(&bestMove, boardValue);
							setYMove(&bestMove, i);
							setXMove(&bestMove, j);
							setMoveNumber(&bestMove, incomingPiece);
						}

						if (boardValue < getHeuristicValue(worseMove) && ( getNumber(currentPiece) != getMoveNumber(bestMove) ))
						{
							setHeuristicValue(&worseMove, boardValue);
							setYMove(&worseMove, i);
							setXMove(&worseMove, j);
							setMoveNumber(&worseMove, getNumber(currentPiece) );
						}
					}

					j = j+1;
				}

				i = i+1;
			}
		}

		checkingPiece = checkingPiece+1;
	}

	if( getMoveNumber(worseMove) == 0 || getMoveNumber(worseMove) == getMoveNumber(bestMove) )
	{
		int worseNumber;
		do
		{
			worseNumber = rand()%16+1;
//			printw("rand %d", worseNumber);
//			refresh();
//			getch();
		}
		while( getStatus( lookUp(pieces, worseNumber) ) != FREE || worseNumber == 0  || worseNumber == getMoveNumber(bestMove) );

		setMoveNumber(&worseMove, worseNumber);
	}

	setBestMove(&result, bestMove);
	setWorseMove(&result, worseMove);

//	printw("%d bestPiece, here %d,%d; %d worst, here %d,%d", getMoveNumber(getBestMove(result)), getYMove(getBestMove(result)), getXMove(getBestMove(result)), getMoveNumber(getWorseMove(result)), getYMove(getWorseMove(result)), getXMove(getWorseMove(result)));
//	refresh();
//	getch();

	return result;
}

/***********************************************
 Nome: heuristic;
 Input: Matrix virtual, Vettore di pezzi pieces, Settings settings, intero pieceNumber
 Cosa fa: Descritta nello pseudo consegnato in precedenza

 Ritorna: Il valore della virtualBoard corrente
 ***********************************************/
int heuristic(Matrix virtualBoard, Piece* pieces, Settings settings, int pieceNumber, int y, int x)
{
	int boardValue = 0;
	int level = getLevel(settings);

	int vertValue = 0;
	int horizValue = 0;
	int diagonValue = 0;
	int paraDiagValue = 0;
	int squareValue = 0;

	int i = 0;
	while( i < getYMatrice(virtualBoard) )
	{
		if( level == 1 )
		{
			horizValue = lineHControl(i, pieces, virtualBoard, pieceNumber);
			vertValue = verticalHControl(i, pieces, virtualBoard, pieceNumber );

			boardValue = boardValue + horizValue + vertValue;
		}
		else if( level == 2 )
		{
			horizValue = lineHControl(i, pieces, virtualBoard, pieceNumber);
			vertValue = verticalHControl(i, pieces, virtualBoard, pieceNumber );
			diagonValue = diagonHControl(pieces, virtualBoard, pieceNumber);
			paraDiagValue = paraHDiagControl(pieces, virtualBoard, pieceNumber);

			boardValue = boardValue +  horizValue + vertValue + diagonValue + paraDiagValue;
		}
		else if( level == 3 )
		{
			horizValue = lineHControl(i, pieces, virtualBoard, pieceNumber);
			vertValue = verticalHControl(i, pieces, virtualBoard, pieceNumber );
			diagonValue = diagonHControl(pieces, virtualBoard, pieceNumber);
			paraDiagValue = paraHDiagControl(pieces, virtualBoard, pieceNumber);
			squareValue = squareHControl(pieces, virtualBoard, pieceNumber, y, x);

			boardValue = boardValue + horizValue + vertValue + diagonValue + paraDiagValue + squareValue;
		}
		i = i + 1;
	}

	return boardValue;
}

/*
 * Controlli euristici linea per linea.
 */

int lineHControl(int line, Piece* pieces, Matrix virtualBoard, int pieceNumber)
{
	Vector commons;
	Piece* linePieces = calloc(4 , sizeof(Piece));

	int found = 0;
	int j = 0;
	int currRead;

	while( j < getXMatrice(virtualBoard) )
	{
		currRead = leggiMatrice(virtualBoard, line, j);
		if( currRead != 0 )
		{
			linePieces[found] = lookUp(pieces, currRead);
			found = found + 1;
		}
		j = j + 1;
	}
	commons = commonAttrs(linePieces, found);

	if( found == 4 )
	{
		if( areCommonsEqualTo(commons, 3) || areCommonsEqualTo(commons, 4) )
		{
			return 1000;
		}
	}

	if( found == 3 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			if( areCommonsEqualTo(commons, 3) )
			{
				return -1000;
			}
			else
			{
				return 2;
			}
		}
	}

	if( found == 2 )
	{
		return 3;
	}

	if( found == 1 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			return 4;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

int verticalHControl(int line, Piece* pieces, Matrix virtualBoard, int pieceNumber)
{
	Vector commons;
	Piece* linePieces = calloc(4 , sizeof(Piece));

	int found = 0;
	int j = 0;
	int currRead;

	while( j < getXMatrice(virtualBoard) )
	{
		currRead = leggiMatrice(virtualBoard, j, line);
		if( currRead != 0 )
		{
			linePieces[found] = lookUp(pieces, currRead);
			found = found + 1;
		}
		j = j + 1;
	}
	commons = commonAttrs(linePieces, found);

	if( found == 4 )
	{
		if( areCommonsEqualTo(commons, 3) || areCommonsEqualTo(commons, 4) )
		{
			return 1000;
		}
	}

	if( found == 3 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			if( areCommonsEqualTo(commons, 3) )
			{
				return -1000;
			}
			else
			{
				return 2;
			}
		}
	}

	if( found == 2 )
	{
		return 3;
	}

	if( found == 1 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			return 4;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

int diagonHControl(Piece* pieces, Matrix virtualBoard, int pieceNumber)
{
	Vector commons;
	Piece* linePieces = calloc(4 , sizeof(Piece));

	int found = 0;
	int j = 0;
	int currRead;

	while( j < getXMatrice(virtualBoard) )
	{
		currRead = leggiMatrice(virtualBoard, j, j);
		if( currRead != 0 )
		{
			linePieces[found] = lookUp(pieces, currRead);
			found = found + 1;
		}
		j = j + 1;
	}
	commons = commonAttrs(linePieces, found);

	if( found == 4 )
	{
		if( areCommonsEqualTo(commons, 3) || areCommonsEqualTo(commons, 4) )
		{
			return 1000;
		}
	}

	if( found == 3 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			if( areCommonsEqualTo(commons, 3) )
			{
				return -1000;
			}
			else
			{
				return 2;
			}
		}
	}

	if( found == 2 )
	{
		return 3;
	}

	if( found == 1 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			return 4;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

int paraHDiagControl(Piece* pieces, Matrix virtualBoard, int pieceNumber)
{
	Vector commons;
	Piece* linePieces = calloc(4 , sizeof(Piece));

	int found = 0;
	int i = 3;
	int j = 0;
	int currRead;

	while( j < getXMatrice(virtualBoard) )
	{
		currRead = leggiMatrice(virtualBoard, j, i);
		if( currRead != 0 )
		{
			linePieces[found] = lookUp(pieces, currRead);
			found = found + 1;
		}
		j = j + 1;
		i = i - 1;
	}
	commons = commonAttrs(linePieces, found);

	if( found == 4 )
	{
		if( areCommonsEqualTo(commons, 3) || areCommonsEqualTo(commons, 4) )
		{
			return 1000;
		}
	}

	if( found == 3 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			if( areCommonsEqualTo(commons, 3) )
			{
				return -1000;
			}
			else
			{
				return 2;
			}
		}
	}

	if( found == 2 )
	{
		return 3;
	}

	if( found == 1 )
	{
		if( isPieceInFound(pieceNumber, linePieces, found ) == 1 )
		{
			return 4;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

int squareHControl(Piece* pieces, Matrix virtualBoard, int pieceNumber, int y, int x)
{
	int control;
	int upLeft = 0;
	int upRight = 0;
	int downLeft = 0;
	int downRight = 0;

	if( y == 0 && x == 0 )
	{
		upLeft = 1;
	}
	else if( y == 0 && x == getXMatrice(virtualBoard) - 1 )
	{
		upRight = 1;
	}
	else if( y == getYMatrice(virtualBoard) - 1 && x == 0 )
	{
		downLeft = 1;
	}
	else if( y == getYMatrice(virtualBoard) - 1 && x == getXMatrice(virtualBoard) )
	{
		downRight = 1;
	}
	else if( y == 0 )
	{
		upLeft = 1;
		upRight = 1;
	}
	else if( y == getYMatrice(virtualBoard) - 1 )
	{
		downLeft = 1;
		downRight = 1;
	}
	else if( x == 0 )
	{
		upLeft = 1;
		downLeft = 1;
	}
	else if( x == getXMatrice(virtualBoard) - 1 )
	{
		upRight = 1;
		downRight = 1;
	}
	else
	{
		upLeft = 1;
		upRight = 1;
		downLeft = 1;
		downRight = 1;
	}

	if( upLeft )
	{
		control = chkUpLeft(virtualBoard, lookUp(pieces, pieceNumber), pieces, y, x);
		if(control)
		{
			return 10000;
		}
	}
	if( upRight )
	{
		control = chkUpRight(virtualBoard, lookUp(pieces, pieceNumber), pieces, y, x);
		if(control)
		{
			return 10000;
		}
	}
	if( downLeft )
	{
		control = chkDownLeft(virtualBoard, lookUp(pieces, pieceNumber), pieces, y, x);
		if(control)
		{
			return 10000;
		}
	}
	if( downRight )
	{
		control = chkDownRight(virtualBoard, lookUp(pieces, pieceNumber), pieces, y, x);
		if(control)
		{
			return 10000;
		}
	}

	return 2;
}

/***********************************************
 Nome: commonAttrs;
 Input: Vettore di pezzi pieces, intero found
 Cosa fa: Trova quali e quanti attributi in comune ci sono nel vettore di pezzi passato.

 Ritorna: Un vettore che esprime quanti e quali attributi.
 ***********************************************/


Vector commonAttrs(Piece* piecesNow, int found)
{
	Vector commons = creaVettore(4);
	Piece startingPiece;
	Piece currPiece;

	int sameColour = 0;
	int sameShape = 0;
	int sameConsistency = 0;
	int sameHeight = 0;

	if( found >= 1 )
	{
		startingPiece = piecesNow[0];
	}

	int i = 0;
	while( i < found )
	{
		currPiece = piecesNow[i];

		if( getColour(startingPiece) == getColour(currPiece) )
		{
			sameColour = sameColour + 1;
		}
		if( getShape(startingPiece) == getShape(currPiece) )
		{
			sameShape = sameShape + 1;
		}
		if( getConsistency(startingPiece) == getConsistency(currPiece) )
		{
			sameConsistency = sameConsistency + 1;
		}
		if( getHeight(startingPiece) == getHeight(currPiece) )
		{
			sameHeight = sameHeight + 1;
		}

		i = i + 1;
	}

	scriviVettore(&commons, 0, sameColour);
	scriviVettore(&commons, 1, sameShape);
	scriviVettore(&commons, 2, sameConsistency);
	scriviVettore(&commons, 3, sameHeight);

	return commons;
}

/***********************************************
 Nome: areCommonsMoreThan;
 Input: Vettore di interi commons, intero questo
 Cosa fa: Ci dice se nel vettore di attributi in comune ci sono più di "questo" attributi

 Ritorna: 1 se sì, 0 se no
 ***********************************************/

int areCommonsMoreThan(Vector commons, int this)
{
	if( leggiVettore(commons, 0) > this  || leggiVettore(commons, 1) > this || leggiVettore(commons, 2) > this || leggiVettore(commons, 3) > this)
	{
		return 1;
	}

	return 0;
}

/***********************************************
 Nome: areCommonsEqualTo;
 Input: Vettore di interi commons, intero questo
 Cosa fa: Ci dice se nel vettore di attributi in comune ci sono "questo" attributi

 Ritorna: 1 se sì, 0 se no
 ***********************************************/

int areCommonsEqualTo(Vector commons, int this)
{
	if( leggiVettore(commons, 0) == this  || leggiVettore(commons, 1) == this || leggiVettore(commons, 2) == this || leggiVettore(commons, 3) == this)
	{
		return 1;
	}

	return 0;
}

/***********************************************
 Nome: isPieceInFound;
 Input: Intero pieceNumber, vettore di pezzi piecesNow, intero found
 Cosa fa: Ci dice se pieceNumber è presente nel vettore di pezzi con cardinalità < found

 Ritorna: 1 se sì, 0 se no
 ***********************************************/

int isPieceInFound(int pieceNumber, Piece* piecesNow, int found )
{
	int i = 0;
	while( i < found )
	{
		if( pieceNumber == getNumber(piecesNow[i]) )
		{
			return 1;
		}

		i = i + 1;
	}

	return 0;
}

/***********************************************
 Nome: emptyMove;
 Input: Nulla.
 Cosa fa: Crea una mossa vuota.

 Ritorna: La mossa vuota.
 ***********************************************/

Move emptyMove()
{
	Move toReturn;
	setHeuristicValue(&toReturn, 0);
	setYMove(&toReturn, 0);
	setXMove(&toReturn, 0);
	setMoveNumber(&toReturn, 0);

	return toReturn;
}

/***********************************************
 Nome: isPatta;
 Input: Vettore di pezzi pieces
 Cosa fa: Ci dice se la partita è patta.

 Ritorna: 1 se sì, 0 se no
 ***********************************************/

int isPatta(Piece* pieces)
{
	int i = 0;
	while( i <= 16 )
	{
		if( getStatus( lookUp(pieces, i) ) == FREE )
		{
			return 0;
		}

		i = i + 1;
	}

	return 1;
}

////////////////////////////////////////////////
///////////////////////////////// INCAPSULAENTO

int getHeuristicValue(Move move)
{
	return move.heuristicValue;
}

int getYMove(Move move)
{
	return move.y;
}

int getXMove(Move move)
{
	return move.x;
}

int getMoveNumber(Move move)
{
	return move.moveNumber;
}

int setHeuristicValue(Move* move, int value)
{
	move->heuristicValue = value;
	return 1;
}

int setYMove(Move* move, int value)
{
	move->y = value;
	return 1;
}

int setXMove(Move* move, int value)
{
	move->x = value;
	return 1;
}

int setMoveNumber(Move* move, int value)
{
	move->moveNumber = value;
	return 1;
}

//

Move getBestMove(BoardAnalysis result)
{
	return result.bestMove;
}

Move getWorseMove(BoardAnalysis result)
{
	return result.worseMove;
}

int setBestMove(BoardAnalysis* result, Move value)
{
	result->bestMove = value;
	return 1;
}

int setWorseMove(BoardAnalysis* result, Move value)
{
	result->worseMove = value;
	return 1;
}

////////////////////////////////////////////
////////////////////////////////// ANALISI BOARD

/***********************************************
 Nome: isVictory;
 Input: Matrice currentBoard, vettore di pezzi pieces, intero level, intero settedy, intero settedx
 Cosa fa: Ci comunica se la corrente scacchiera, con questa difficoltà, è vincente

 Ritorna: 1 se sì, 0 se no
 ***********************************************/

int isVictory (Matrix currentBoard, Piece* pieces, int level, int settedy, int settedx )
{
	Piece startingPiece = lookUp(pieces, leggiMatrice(currentBoard, settedy, settedx) );
	int horizontalVictory = 0;
	int verticalVictory = 0;
	int diagonalVictory = 0;
	int paraDiagonalVictory = 0;
	int squareVictory = 0;


	if( level == 1 )
	{
		horizontalVictory = lineControl(currentBoard, pieces, startingPiece, settedy);
        verticalVictory = verticalLineControl(currentBoard, pieces, startingPiece, settedx);

	}
	else if( level == 2 )
	{
		horizontalVictory = lineControl(currentBoard, pieces, startingPiece, settedy);
		verticalVictory = verticalLineControl(currentBoard, pieces, startingPiece, settedx);
		diagonalVictory = diagonalControl(currentBoard, pieces, startingPiece, settedx, settedy);
		paraDiagonalVictory = secondaryDiagonalControl(currentBoard, pieces, startingPiece, settedx, settedy);

	}
	else if( level == 3 )
	{
		horizontalVictory = lineControl(currentBoard, pieces, startingPiece, settedy);
		verticalVictory = verticalLineControl(currentBoard, pieces, startingPiece, settedx);
		diagonalVictory = diagonalControl(currentBoard, pieces, startingPiece, settedx, settedy);
		paraDiagonalVictory = secondaryDiagonalControl(currentBoard, pieces, startingPiece, settedx, settedy);
		squareVictory = squareControl(currentBoard, pieces, startingPiece, settedx, settedy);
	}

	if(horizontalVictory)
	{
//		addstr("Horiz!");
		return 1;
	}
	if(verticalVictory)
	{
//		addstr("Verti!");
		return 1;
	}
	if(diagonalVictory)
	{
//		addstr("Diagg");
		return 1;
	}
	if(paraDiagonalVictory)
	{
//		addstr("Paradia");
		return 1;
	}
	if(squareVictory)
	{
//		addstr("Square!");
		return 1;
	}

	return 0;
}

//sottocontrolli per la vittoria
int lineControl (Matrix currentBoard, Piece* pieces, Piece startingPiece, int settedy)
{
	int currValue;
	Piece tempPiece;

	int sameColour = 0;
	int sameShape = 0;
	int sameConsistency = 0;
	int sameHeight = 0;

	int i = 0;
	while( i < getYMatrice(currentBoard) )
	{
		currValue = leggiMatrice(currentBoard, settedy, i );
		if( currValue <= 0  || currValue > 16 )
		{
			return 0;
		}
		tempPiece = lookUp(pieces, currValue);

		if( getColour(startingPiece) == getColour(tempPiece) )
		{
			sameColour = sameColour + 1;
		}
		if( getShape(startingPiece) == getShape(tempPiece) )
		{
			sameShape = sameShape + 1;
		}
		if( getConsistency(startingPiece) == getConsistency(tempPiece) )
		{
			sameConsistency = sameConsistency + 1;
		}
		if( getHeight(startingPiece) == getHeight(tempPiece) )
		{
			sameHeight = sameHeight + 1;
		}

		i = i + 1;
	}

	if  ((sameColour == 4) || (sameShape == 4) || (sameConsistency == 4) || (sameHeight == 4))
	{
		return 1;
	}

	return 0;
}

int verticalLineControl (Matrix currentBoard, Piece* pieces, Piece startingPiece,  int settedx)
{
	int currValue;
	Piece tempPiece;

	int sameColour = 0;
	int sameShape = 0;
	int sameConsistency = 0;
	int sameHeight = 0;

	int i = 0;
	while( i < getYMatrice(currentBoard) )
	{
		currValue = leggiMatrice(currentBoard, i, settedx );
		if( currValue <= 0  || currValue > 16 )
		{
			return 0;
		}

		tempPiece = lookUp(pieces, currValue);

		if( getColour(startingPiece) == getColour(tempPiece) )
		{
			sameColour = sameColour + 1;
		}
		if( getShape(startingPiece) == getShape(tempPiece) )
		{
			sameShape = sameShape + 1;
		}
		if( getConsistency(startingPiece) == getConsistency(tempPiece) )
		{
			sameConsistency = sameConsistency + 1;
		}
		if( getHeight(startingPiece) == getHeight(tempPiece) )
		{
			sameHeight = sameHeight + 1;
		}

		i = i + 1;
	}

	if  ((sameColour == 4) || (sameShape == 4) || (sameConsistency == 4) || (sameHeight == 4))
	{
		return 1;
	}

	return 0;
}
int secondaryDiagonalControl (Matrix currentBoard, Piece* pieces,  Piece startingPiece, int settedx, int settedy)
{
	int currValue;
	Piece tempPiece;

	int sameColour = 0;
	int sameShape = 0;
	int sameConsistency = 0;
	int sameHeight = 0;

	if( (settedx + settedy) != (getXMatrice(currentBoard) - 1) )
	{
		return 0;
	}

	int j = getXMatrice(currentBoard) - 1;
	int i = 0;
	while( i < getYMatrice(currentBoard) )
	{
		currValue = leggiMatrice(currentBoard, i, j );
		if( currValue <= 0  || currValue > 16 )
		{
			return 0;
		}
		tempPiece = lookUp(pieces, currValue);

		if( getColour(startingPiece) == getColour(tempPiece) )
		{
			sameColour = sameColour + 1;
		}
		if( getShape(startingPiece) == getShape(tempPiece) )
		{
			sameShape = sameShape + 1;
		}
		if( getConsistency(startingPiece) == getConsistency(tempPiece) )
		{
			sameConsistency = sameConsistency + 1;
		}
		if( getHeight(startingPiece) == getHeight(tempPiece) )
		{
			sameHeight = sameHeight + 1;
		}

		i = i + 1;
		j = j - 1;
	}

	if  ((sameColour == 4) || (sameShape == 4) || (sameConsistency == 4) || (sameHeight == 4))
	{
		return 1;
	}

	return 0;
}

int diagonalControl (Matrix currentBoard, Piece* pieces, Piece startingPiece,  int settedx, int settedy)
{
	int currValue;
	Piece tempPiece;

	int sameColour = 0;
	int sameShape = 0;
	int sameConsistency = 0;
	int sameHeight = 0;

	if( settedx != settedy )
	{
		return 0;
	}

	int j = 0;
	int i = 0;
	while( i < getYMatrice(currentBoard) )
	{
		currValue = leggiMatrice(currentBoard, i, j );
		if( currValue <= 0  || currValue > 16 )
		{
			return 0;
		}
		tempPiece = lookUp(pieces, currValue);

		if( getColour(startingPiece) == getColour(tempPiece) )
		{
			sameColour = sameColour + 1;
		}
		if( getShape(startingPiece) == getShape(tempPiece) )
		{
			sameShape = sameShape + 1;
		}
		if( getConsistency(startingPiece) == getConsistency(tempPiece) )
		{
			sameConsistency = sameConsistency + 1;
		}
		if( getHeight(startingPiece) == getHeight(tempPiece) )
		{
			sameHeight = sameHeight + 1;
		}

		i = i + 1;
		j = j + 1;
	}

	if  ((sameColour == 4) || (sameShape == 4) || (sameConsistency == 4) || (sameHeight == 4))
	{
		return 1;
	}

	return 0;
}
int squareControl(Matrix currentBoard, Piece* pieces,  Piece startingPiece, int settedx, int settedy)
{
	int control = 0;

	int upLeft = 0;
	int upRight = 0;
	int downLeft = 0;
	int downRight = 0;

	if( settedy == 0 && settedx == 0 )
	{
		upLeft = 1;
	}
	else if( settedy == 0 && settedx == getXMatrice(currentBoard) - 1 )
	{
		upRight = 1;
	}
	else if( settedy == getYMatrice(currentBoard) - 1 && settedx == 0 )
	{
		downLeft = 1;
	}
	else if( settedy == getYMatrice(currentBoard) - 1 && settedx == getXMatrice(currentBoard) )
	{
		downRight = 1;
	}
	else if( settedy == 0 )
	{
		upLeft = 1;
		upRight = 1;
	}
	else if( settedy == getYMatrice(currentBoard) - 1 )
	{
		downLeft = 1;
		downRight = 1;
	}
	else if( settedx == 0 )
	{
		upLeft = 1;
		downLeft = 1;
	}
	else if( settedx == getXMatrice(currentBoard) - 1 )
	{
		upRight = 1;
		downRight = 1;
	}
	else
	{
		upLeft = 1;
		upRight = 1;
		downLeft = 1;
		downRight = 1;
	}

	if( upLeft )
	{
		control = chkUpLeft(currentBoard, startingPiece, pieces, settedy, settedx);
		if(control)
		{
			return 1;
		}
	}
	if( upRight )
	{
		control = chkUpRight(currentBoard, startingPiece, pieces, settedy, settedx);
		if(control)
		{
			return 1;
		}
	}
	if( downLeft )
	{
		control = chkDownLeft(currentBoard, startingPiece, pieces, settedy, settedx);
		if(control)
		{
			return 1;
		}
	}
	if( downRight )
	{
		control = chkDownRight(currentBoard, startingPiece, pieces, settedy, settedx);
		if(control)
		{
			return 1;
		}
	}

	return 0;
}
int chkBetweenPieces(Piece startingPiece, Piece next1, Piece next2, Piece next3)
{
	if( getColour(startingPiece) == getColour(next1) &&
	    getColour(startingPiece) == getColour(next2) && getColour(startingPiece) == getColour(next3)	)
	{
		return 1;
	}
	if( getShape(startingPiece) == getShape(next1) &&
		getShape(startingPiece) == getShape(next2) && getShape(startingPiece) == getShape(next3)	)
	{
		return 1;
	}
	if( getConsistency(startingPiece) == getConsistency(next1) &&
		getConsistency(startingPiece) == getConsistency(next2) && getConsistency(startingPiece) == getConsistency(next3)	)
	{
		return 1;
	}
	if( getHeight(startingPiece) == getHeight(next1) &&
		getHeight(startingPiece) == getHeight(next2) && getHeight(startingPiece) == getHeight(next3)	)
	{
		return 1;
	}

	return 0;
}
int chkUpLeft(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx)
{
	int nextInt1 = leggiMatrice(currentBoard, settedy, settedx+1 );
	int nextInt2 = leggiMatrice(currentBoard, settedy+1, settedx );
	int nextInt3 = leggiMatrice(currentBoard, settedy+1, settedx+1 );

	if(nextInt1 == 0 || nextInt2 == 0 || nextInt3 == 0)
	{
		return 0;
	}

	Piece next1 = lookUp(pieces, nextInt1);
	Piece next2 = lookUp(pieces, nextInt2);
	Piece next3 = lookUp(pieces, nextInt3);

	return chkBetweenPieces(startingPiece, next1, next2, next3);
}
int chkUpRight(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx)
{
	int nextInt1 = leggiMatrice(currentBoard, settedy, settedx-1 );
	int nextInt2 = leggiMatrice(currentBoard, settedy+1, settedx-1 );
	int nextInt3 = leggiMatrice(currentBoard, settedy+1, settedx );

	if(nextInt1 == 0 || nextInt2 == 0 || nextInt3 == 0)
	{
		return 0;
	}

	Piece next1 = lookUp(pieces, nextInt1);
	Piece next2 = lookUp(pieces, nextInt2);
	Piece next3 = lookUp(pieces, nextInt3);

	return chkBetweenPieces(startingPiece, next1, next2, next3);
}
int chkDownLeft(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx)
{
	int nextInt1 = leggiMatrice(currentBoard, settedy-1, settedx );
	int nextInt2 = leggiMatrice(currentBoard, settedy-1, settedx+1 );
	int nextInt3 = leggiMatrice(currentBoard, settedy, settedx+1 );

	if(nextInt1 == 0 || nextInt2 == 0 || nextInt3 == 0)
	{
		return 0;
	}

	Piece next1 = lookUp(pieces, nextInt1);
	Piece next2 = lookUp(pieces, nextInt2);
	Piece next3 = lookUp(pieces, nextInt3);

	return chkBetweenPieces(startingPiece, next1, next2, next3);
}
int chkDownRight(Matrix currentBoard, Piece startingPiece, Piece* pieces, int settedy, int settedx)
{
	int nextInt1 = leggiMatrice(currentBoard, settedy, settedx-1 );
	int nextInt2 = leggiMatrice(currentBoard, settedy-1, settedx-1 );
	int nextInt3 = leggiMatrice(currentBoard, settedy-1, settedx );

	if(nextInt1 == 0 || nextInt2 == 0 || nextInt3 == 0)
	{
		return 0;
	}

	Piece next1 = lookUp(pieces, nextInt1);
	Piece next2 = lookUp(pieces, nextInt2);
	Piece next3 = lookUp(pieces, nextInt3);

	return chkBetweenPieces(startingPiece, next1, next2, next3);
}

////////////////////////////////////////////
//////////////////////////////////
