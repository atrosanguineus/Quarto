#include "QuartoLib.h"

///////////////////////////////////////////////////
/////////////////////////////////////INIZIALIZZAZIONI

/***********************************************
 Nome: initCurse;
 Input: Nulla.
 Cosa fa: Inizializza la sessione curses.

 Ritorna: 1 ad inizializzazione terminata.
 ***********************************************/

int initCurse()
{
	initscr();
	noecho();
	start_color();
	keypad(stdscr, 1);
	curs_set(0);
	refresh();

	return 1;
}

/***********************************************
 Nome: localizeExe;
 Input: Argomento del main.
 Cosa fa: Usando l'argomento fornito dal main, localizza relativamente a sè stesso i file necessari.

 Ritorna: 1 ad inizializzazione terminata.
 ***********************************************/

int localizeExe(char** argv)
{
	settingsFile = calloc(MAX_PATH, sizeof(char));
	savesFile = calloc(MAX_PATH, sizeof(char));
	rules1 = calloc(MAX_PATH, sizeof(char));
	rules2 = calloc(MAX_PATH, sizeof(char));
	rules3 = calloc(MAX_PATH, sizeof(char));

	settingsFile = strdup( concatenaStringa( getParentCartella(argv[0]), "\\Files\\settings.bin" ) );
//	printw("%s\n", settingsFile);
//	refresh();

	savesFile = strdup( concatenaStringa( getParentCartella(argv[0]), "\\Files\\saves.txt" ) );
//	printw("%s\n", savesFile);
//	refresh();

	rules1 = strdup( concatenaStringa( getParentCartella(argv[0]), "\\Files\\rules1.txt" ) );
//	printw("%s\n", rules1);
//	refresh();

	rules2 = strdup( concatenaStringa( getParentCartella(argv[0]), "\\Files\\rules2.txt" ) );
//	printw("%s\n", rules2);
//	refresh();

	rules3 = strdup( concatenaStringa( getParentCartella(argv[0]), "\\Files\\rules3.txt" ) );
	printw("%s\n", rules3);
//	refresh();
//
//	getch();
	return 1;
}

/***********************************************
 Nome: loadSettings;
 Input: Nulla.
 Cosa fa: Carica le impostazioni correnti da file.

 Ritorna: Una variabile Settings completa.
 ***********************************************/

Settings loadSettings()
{
	Settings newSet;
	FILE* file = fopen(settingsFile, "rb");
	fread(&newSet, sizeof(Settings), 1, file);
	fclose(file);
	return newSet;
}

///////////////////////////////////////////////////
/////////////////////////////////////INTERFACCE

/***********************************************
 Nome: showSettings;
 Input: Settings set.
 Cosa fa: Stampa a video le settings correnti.

 Ritorna: 1 a stampa completa.
 ***********************************************/

int showSettings(Settings set)
{
	SVector playerOptions = creaSVettore(2);
	SVector diffOptions = creaSVettore(3);
	scriviSVettore(&playerOptions, 0, "(Giocatore vs CPU)   ");
	scriviSVettore(&playerOptions, 1, "(Giocatore vs Giocatore)");
	scriviSVettore(&diffOptions, 0, "(Facile)   ");
	scriviSVettore(&diffOptions, 1, "(Normale)   ");
	scriviSVettore(&diffOptions, 2, "(Pro)");

	clear();
	printTitle();
	centerPrintString(5, "IMPOSTAZIONI");

	move(SETTINGS_STARTING_ROW, SETTINGS_STARTING_COL);
	addstr("1) Modalita' di gioco: ");
//	printw("%d", getPlayers(set));
	highlightElement(playerOptions, getPlayers(set) );

	move(SETTINGS_STARTING_ROW + 2, SETTINGS_STARTING_COL);
	addstr("2) Difficolta': ");
//	printw("%d", getLevel(set));
	highlightElement(diffOptions, getLevel(set) );

	refresh();
	return 1;
}

/***********************************************
 Nome: showRules;
 Input: Nulla.
 Cosa fa: Cicla tra le visualizzazioni delle pagine di regolamento finché non si preme ESC.

 Ritorna: 0 ad ESC premuto.
 ***********************************************/

int showRules()
{
	int id;

	attron(A_BOLD);
	int c = 1;
	while(c != 27)
	{
		if(c == 1)
		{
			id = 1;
			c = page(rules1, id);
		}

		if(c == 2)
		{
			id = 2;
			c = page(rules2, id);
		}

		if(c == 3)
		{
			id = 3;
			c = page(rules3, id);
			clear();
		}
	}
	attroff(A_BOLD);
	clear();
	refresh();
	return 0;
}

/***********************************************
 Nome: page;
 Input: Stringa index, intero id.
 Cosa fa: Stampa la pagina nell'indirizzo index e visualizza i comandi per spostarsi tra le altre pagine.

 Ritorna: Un intero rappresentante la prossima pagina da visualizzare.
 ***********************************************/

int page(char *index, int id)
{
	int c;
	char* line = calloc(STD_STR_SIZE, sizeof(char) );
	FILE *regulament;
	char ask;
	do
	{
		clear();
		regulament = fopen(index,"r");
		if (regulament == NULL)
		{
			printw("Errore in apertura del file!");
			refresh();
		}
		while( fgets(line, STD_STR_SIZE, regulament) )
		{
			addstr(line);
			refresh();
		}
		fclose(regulament);

		init_pair(2, COLOR_CYAN, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		if(id == 1)
		{
			printw("<N>-Prossima pagina " /*| <B>-Indietro */);
			refresh();
			ask = getch();
			if(ask == 'N' || ask == 'n')
			{
				c = 2;
			}
			else if( ask == 'P' || ask == 'p')
			{
				c = 1;
			}
			else if( (int) ask == 27 )
			{
				c = 27;
			}
		}

		else if(id == 2)
		{
			printw("<N>-Prossima pagina | <P>-Pagina precedente "/*| <B>-Indietro */);
			refresh();
			ask = getch();
			if(ask == 'N' || ask == 'n')
			{
				c = 3;
			}
			else if( ask == 'P' || ask == 'p')
			{
				c = 1;
			}
			else if( (int) ask == 27 )
			{
				c = 27;
			}
		}

		else if(id == 3)
		{
			printw("<P>-Pagina precedente "/*| <B>-Indietro */);
			refresh();
			ask = getch();
			if(ask == 'P' || ask == 'p')
			{
				c = 2;
			}
			else if( (int) ask == 27 )
			{
				c = 27;
			}
			else
			{
				c = 3;
			}
		}
		attroff(COLOR_PAIR(2));
	}
	while(ask != 'N' && ask != 'n' && ask != 'P' && ask != 'p' && (int) ask != 27 );
	return c;
}

//

/***********************************************
 Nome: playerWon;
 Input: Intero activePlayer, intero players, intero patta.
 Cosa fa: In base al numero di giocatori, il giocatore corrente ed alla pattezza o meno della partita,
 	      Visualizza il messaggio corretto.

 Ritorna: 1 a messaggio stampato.
 ***********************************************/

int playerWon(int activePlayer, int players, int patta)
{
	char* message = calloc(STD_STR_SIZE, sizeof(char));
	char* intBuf = calloc(7, sizeof(char));

	curs_set(0);
	WINDOW* winWindow = newwin(WIN_HEIGHT, WIN_WIDTH, 5, 42);
	wborder(winWindow, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, '+', '+', '+', '+');

	if( patta )
	{
		message = "Patta!";
	}
	else if( players == 2 )
	{
		message = concatenaStringa("Giocatore ", itoa( activePlayer + 1, intBuf, 10));
		message = concatenaStringa(message, ", hai vinto!");
	}
	else if( players == 1 && activePlayer == 1)
	{
		message = "La CPU ha vinto..";
	}
	else if ( players == 1 && activePlayer == 0)
	{
		message = concatenaStringa("Giocatore ", itoa( activePlayer+1 , intBuf, 10));
		message = concatenaStringa(message, ", hai vinto!");
	}


	wmove(winWindow, WIN_HEIGHT/2, (WIN_WIDTH - strlen(message)) /2 );
	waddstr(winWindow, message);
	wrefresh(winWindow);

	return 1;
}

///////////////////////////////////////////////////
/////////////////////////////////////GESTIONE MENU

//DOCUMENTATA IN PSEUDO PRECEDENTE
int centerPrintString(int line, char* string)
{
	int x;
	int y;
	getyx(stdscr, y, x);

	int col = (WINDOW_WIDTH -  strlen(string) )/2;
	move(line, col);
	addstr(string);
	move(y, x);

	return 1;
}

// La backslash, per essere interpretata come tale, deve essere preceduta da un'altra backslash (Risultato: scritta nell'editor leggermente spostata)
//DOCUMENTATA IN PSEUDO PRECEDENTE
int printTitle()
{
	init_pair(3, COLOR_CYAN, COLOR_BLACK);

	attron(COLOR_PAIR(3));
	attron(A_BOLD);
	centerPrintString(1, "  __           _    __ ____ ___   ||");
	centerPrintString(2, "||  | ||  |  //_\\  ||_) || ||  |  ||");
	centerPrintString(3, "||_\\| ||__| //   \\ || \\ || ||__|  []");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(3));

	return 1;
}

//DOCUMENTATA IN PSEUDO PRECEDENTE
int showMenu()
{
	clear();
	printTitle();
	centerPrintString(7,  "1) NUOVA PARTITA ");
	centerPrintString(10, "2) CARICA PARTITA ");
	centerPrintString(13, "3) MODIFICA IMPOSTAZIONI");
	centerPrintString(16, "4) REGOLAMENTO DEL GIOCO");
	centerPrintString(20, "0) ESCI ");

	return 1;
}



////

/***********************************************
 Nome: settings;
 Input: Nulla.
 Cosa fa: In base ad input utente, cambia le impostazioni e le scrive su file.

 Ritorna: 1 a pressione di ESC.
 ***********************************************/

int settings()
{
	Settings set = loadSettings();
	int players = getPlayers(set);
	int level = getLevel(set);

	int choice;
	do
	{
		showSettings(set);
		choice = settingsSelection();
		if( choice == 1 )
		{
			if( players == 1)
			{
				players = 2;
			}
			else
			{
				players = 1;
			}

			setPlayers(&set, players);
			writeSettings(set);
		}
		else if( choice == 2 )
		{
			if( level < 3 )
			{
				level = level + 1;
			}
			else if( level == 3 )
			{
				level = 1;
			}

			setLevel(&set, level);
			writeSettings(set);
		}
	}
	while( choice !=  27 );
	return 1;
}

/***********************************************
 Nome: settingsSelection;
 Input: Nulla.
 Cosa fa: Se il tasto premuto è 27, lo ritorna. Altrimenti ritorna il valore ASCII del tasto - 48,
 	 	  per filtrare i numeri.

 Ritorna: 27 o ascii tasto - 48.
 ***********************************************/

int settingsSelection()
{
	int choice;
	choice = getch();

	if( choice == 27 )
	{
		return choice;
	}
	else
	{
		return choice - 48;
	}
}

//

/***********************************************
 Nome: saveGame;
 Input: Puntatore a Game game.
 Cosa fa: Racchiude tutte le funzioni da applicare alla pressione di S.

 Ritorna: 1 a schermata di salvataggio chiusa.
 ***********************************************/

int saveGame(Game* game)
{
	SVector names = getSaveNames();
	curs_set(0);

	WINDOW* saveWindow = newwin(SAVES_HEIGHT, SAVES_WIDTH, 6, 18);
	displaySaves(saveWindow, names);
	actionSaves(saveWindow, game, names);
	curs_set(1);

	return 1;
}

/***********************************************
 Nome: displaySaves;
 Input: Puntatore a finestra saveWindow, vettore di stringhe names.
 Cosa fa: Stampa a schermo i nomi dei salvataggi caricabili oppure EMPTY in corrispondenza
 	      di uno slot vuoto.

 Ritorna: 1 a display terminato.
 ***********************************************/

int displaySaves(WINDOW* saveWindow, SVector names)
{
	char* salvaStr = "SALVA PARTITA";

	wborder(saveWindow, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, '+', '+', '+', '+');
	wrefresh(saveWindow);

	wmove(saveWindow, 1, (SAVES_WIDTH - strlen(salvaStr)) / 2 );
	waddstr(saveWindow, salvaStr);
	wrefresh(saveWindow);

	int i = 1;
	while( i <= 5 )
	{
		wmove(saveWindow, 3 + i-1, 8);
		wprintw(saveWindow, "%d) ", i);
		wrefresh(saveWindow);

		if( isLoadable(i) )
		{
			waddstr(saveWindow, leggiSVettore(names, i-1));
		}
		else
		{
			waddstr(saveWindow, "========EMPTY========");
		}

		i = i + 1;
	}
	wrefresh(saveWindow);
	return 1;
}

/***********************************************
 Nome: actionSaves;
 Input: Puntatore a finestra saveWindow, puntatore a Game game, vettore di stringhe names.
 Cosa fa: actionSaves filtra gli input che non corrispondono ad uno dei cinque slot.
 	 	  Se uno slot è selezionato e pieno, viene chiesta la sovrascrittura.
 	 	  Se tutto va bene, lo slot viene sovrascritto con una stringa controllata
 	 	  carattere per carattere, come se fosse followGameInput.

 Ritorna: 1 a salvataggio terminato o ESC premuto.
 ***********************************************/

int actionSaves(WINDOW* saveWindow, Game* game, SVector names)
{
	int overWrite = 0;
	int y, x;
	int yStr, xStr;
	wmove(saveWindow, 9, 1);
	getyx(saveWindow, y, x);
	char* saveName = calloc(STD_STR_SIZE, sizeof(char));

	int selectedSlot;
	int inputStrDigit;

	do
	{
		selectedSlot = getch();
		selectedSlot = selectedSlot - '0';

		if( selectedSlot >= 1 && selectedSlot <= 5 )
		{
			if( isLoadable(selectedSlot) )
			{
				waddstr(saveWindow, "Sicuro di voler sovrascrivere?  ( Y/N )");
				wrefresh(saveWindow);
				overWrite = sceltaYN("");
			}

			wmove(saveWindow, y, x);
			waddstr(saveWindow, "                                       ");
			wmove(saveWindow, y, x);
			wrefresh(saveWindow);

			if( (isLoadable(selectedSlot) && overWrite == 1) ||  ( !isLoadable(selectedSlot) && overWrite == 0) )
			{
				waddstr(saveWindow, "Come lo chiamo?: ");
				getyx(saveWindow, yStr, xStr);
				wrefresh(saveWindow);

				int writeHead = 0;
				do
				{
					inputStrDigit = getch();

					if( inputStrDigit == BACKSPACE && writeHead > 0 )
					{
						writeHead = writeHead - 1;
						saveName[writeHead] = '\0';
					}

					else if( isalnum(inputStrDigit) && writeHead >= 0 && writeHead < 21 )
					{
						saveName[writeHead] = (char) inputStrDigit;
						writeHead = writeHead + 1;
						saveName[writeHead] = '\0';
					}
					else if( inputStrDigit == LINE_FEED || inputStrDigit == ENTER )
					{
						if( strlen(saveName) > 0 )
						{
							setSaveName(game, saveName);

							writeSave(*game, selectedSlot);
							inputStrDigit = 27;
							selectedSlot = -21;
						}
					}

					wmove(saveWindow, yStr, xStr);
					waddstr(saveWindow, "                     ");
					wmove(saveWindow, yStr, xStr);
					waddstr(saveWindow, saveName);
					wrefresh(saveWindow);
				}
				while( inputStrDigit != 27 );

				wmove(saveWindow, y, x);
				waddstr(saveWindow, "                                       ");
				wmove(saveWindow, y, x);
				wrefresh(saveWindow);
			}
		}
	}
	while( selectedSlot + '0' != 27 );
	return 1;
}

/***********************************************
 Nome: writeSave;
 Input: Game game, intero slot.
 Cosa fa: serializza il gioco game e lo salva nello slot slot.

 Ritorna: 1 a salvataggio terminato.
 ***********************************************/

int writeSave(Game game, int slot)
{
	char* serial = calloc(MAXSERIAL, sizeof(char) );
	serial = strdup(serializeGame(game));
	replaceLine(savesFile, slot, serial);

	return 1;
}

/***********************************************
 Nome: deserialize;
 Input: intero slot.
 Cosa fa: Deserializza la stringa nello slot slot e la traduce in un formato game.
 	 	  La deserializzazione consiste nel prendere singolarmente, in ordine, i caratteri
 	 	  compresi tra ogni ';', per poi convertirli sequenzialmente nei tipi originali definiti in Game.
 	 	  Esempio: il primo elemento è sempre check, il secondo è sempre nome, il terzo e quarto sono sempre settings,
 	 	  e così via per ogni campo di Game, in ordine.

 Ritorna: un Game completo, pronto per essere caricato.
 ***********************************************/

Game deserialize(int slot)
{
	Game game;
	setCheck(&game, 0);

	FILE* savFile = fopen(savesFile, "r");
	if(savFile == NULL)
	{
		printw("Error: %d (%s)\n", errno, strerror(errno));
		refresh();
		getch();
	}
	char* saveLine = calloc(MAXSERIAL, sizeof(char) );
	saveLine = getLinea(savFile, slot);
	fclose(savFile);

	// CAMPI DA RIEMPIRE //
	int check = getCheck(game);
	char* name;
	Settings set;
	Matrix board;
	Piece* pieces = calloc(17, sizeof(Piece));
	int activePlayer;
	int activeStep;
	int turn;

	//
	int counter = 0;
	int pos = 0;
	int len = strlen(saveLine);

	while( pos != len - 1 )
	{
		if( counter == 0 )
		{
			check = atoi(cropToSeparator(saveLine, &pos, ';'));
			if(check == 0 )
			{
				return game;
			}
			counter = counter + 1;
		}
		else if( counter == 1 )
		{
			name = cropToSeparator(saveLine, &pos, ';');
			counter = counter + 1;
		}
		else if( counter == 2 )
		{
			int setPlayer = atoi(cropToSeparator(saveLine, &pos, ';'));
			int setLevels = atoi(cropToSeparator(saveLine, &pos, ';'));
			setPlayers(&set, setPlayer);
			setLevel(&set, setLevels);
			counter = counter + 1;
		}
		else if( counter == 3 )
		{
			int boardY = atoi(cropToSeparator(saveLine, &pos, ';'));
			int boardX = atoi(cropToSeparator(saveLine, &pos, ';'));

			board = creaMatrice(boardY, boardX);
			int i = 0;
			while( i < boardY )
			{
				int j = 0;
				while( j < boardX )
				{
					int toWrite = atoi(cropToSeparator(saveLine, &pos, ';'));
					scriviMatrice(&board, i, j, toWrite);
					j = j + 1;
				}
				i = i + 1;
			}

			counter = counter + 1;
		}
		else if( counter == 4 )
		{
			int i = 0;
			while( i < NUMPIECES )
			{
				CMatrix image;
				int height;
				int colour;
				int shape;
				int consistency;
				int number;
				int status;

				int imageY = atoi(cropToSeparator(saveLine, &pos, ';'));
				int imageX = atoi(cropToSeparator(saveLine, &pos, ';'));
				image = creaCMatrice(imageY, imageX);

				int j = 0;
				while( j < imageY )
				{
					int k = 0;
					while( k < imageX )
					{
						scriviCMatrice(&image, j, k, (char)  atoi(cropToSeparator(saveLine, &pos, ';') ));
						k = k + 1;
					}
					j = j + 1;
				}

				height = atoi(cropToSeparator(saveLine, &pos, ';'));
				colour = atoi(cropToSeparator(saveLine, &pos, ';'));
				shape = atoi(cropToSeparator(saveLine, &pos, ';'));
				consistency = atoi(cropToSeparator(saveLine, &pos, ';'));
				number = atoi(cropToSeparator(saveLine, &pos, ';'));
				status = atoi(cropToSeparator(saveLine, &pos, ';'));

				pieces[i] = newPiece(image, height, colour, shape, consistency, number, status);
				i = i + 1;
			}

			counter = counter + 1;
		}
		else if( counter == 5 )
		{
			activePlayer = atoi(cropToSeparator(saveLine, &pos, ';'));
			activeStep = atoi(cropToSeparator(saveLine, &pos, ';'));
			turn = atoi(cropToSeparator(saveLine, &pos, ';'));
			counter = counter + 1;
		}
	}

	game = newGame(check, name, set, board, pieces, activePlayer, activeStep, turn);
	return game;
}

/***********************************************
 Nome: serializeGame;
 Input: Game game.
 Cosa fa: serializza il gioco Game e ritorna una stringa che lo rappresenta.
 	 	  La serializzazione, come la deserializzazione, procede nel convertire ogni campo
 	 	  di Game in un valore stringabile. Nel caso incontra una struct, procede a scrivere
 	 	  prima tutti i campi della sottostruct per poi continuare normalmente
 	 	  con i campi di Game.
 	 	  Ogni valore viene separato da un punto e virgola, per essere facilmente isolato.


 Ritorna: Una stringa contenente l'equivalente serializzato di game..
 ***********************************************/

char* serializeGame(Game game)
{
	char* serialization = calloc( MAXSERIAL, sizeof(char) );
	char* intBuffer = calloc( STD_STR_SIZE, sizeof(char) );
	Settings set = getSettings(game);
	Matrix board = getBoard(game);
	Piece* pieces = getPieces(game);

	int check = getCheck(game);
	char* name = getSaveName(game);
	int setPlayers = getPlayers(set);
	int setLevel = getLevel(set);
	int boardX = getXMatrice(board);
	int boardY = getYMatrice(board);

	appendSemicolon(serialization, itoa(check, intBuffer, 10));
	appendSemicolon(serialization, name);
	appendSemicolon(serialization, itoa(setPlayers, intBuffer, 10));
	appendSemicolon(serialization, itoa(setLevel, intBuffer, 10));
	appendSemicolon(serialization, itoa(boardY, intBuffer, 10));
	appendSemicolon(serialization, itoa(boardX, intBuffer, 10));

	int j = 0;
	int i = 0;
	while( i < getYMatrice(board) )
	{
		j = 0;
		while( j < getXMatrice(board) )
		{
			appendSemicolon(serialization, itoa(leggiMatrice(board, i, j), intBuffer, 10));
			j = j + 1;
		}
		i = i + 1;
	}

	i = 0;
	while( i < NUMPIECES )
	{
		Piece currPiece = pieces[i];
		CMatrix image = getImage(currPiece);
		int imageX = getXCMatrice(image);
		int imageY = getYCMatrice(image);

		int height = getHeight(currPiece);
		int colour = getColour(currPiece);
		int shape = getShape(currPiece);
		int consistency = getConsistency(currPiece);
		int number = getNumber(currPiece);
		int status = getStatus(currPiece);

		appendSemicolon(serialization, itoa(imageY, intBuffer, 10));
		appendSemicolon(serialization, itoa(imageX, intBuffer, 10));

		j = 0;
		while( j < imageY )
		{
			int k = 0;
			while( k < imageX )
			{
				appendSemicolon(serialization, itoa( (int) leggiCMatrice(getImage(currPiece), j, k), intBuffer, 10 ) );
				k = k + 1;
			}
			j = j + 1;
		}

		appendSemicolon(serialization, itoa(height, intBuffer, 10));
		appendSemicolon(serialization, itoa(colour, intBuffer, 10));
		appendSemicolon(serialization, itoa(shape, intBuffer, 10));
		appendSemicolon(serialization, itoa(consistency, intBuffer, 10));
		appendSemicolon(serialization, itoa(number, intBuffer, 10));
		appendSemicolon(serialization, itoa(status, intBuffer, 10));
		i = i + 1;
	}

	int activePlayer = getActivePlayer(game);
	int activeStep = getActiveStep(game);
	int turn = getTurn(game);

	appendSemicolon(serialization, itoa(activePlayer, intBuffer, 10));
	appendSemicolon(serialization, itoa(activeStep, intBuffer, 10));
	appendSemicolon(serialization, itoa(turn, intBuffer, 10));

	return serialization;
}

////

/***********************************************
 Nome: getSaveNames;
 Input: Nulla.
 Cosa fa: Legge i nomi dei salvataggi in file.

 Ritorna: Vettore di stringhe con i nomi dei salvataggi.
 ***********************************************/

SVector getSaveNames()
{
	char* name;
	SVector vect = creaSVettore(5);

	FILE* file = fopen(savesFile, "r");

	int i = 1;
	while( i <= 5 )
	{
		int pos = 0;
		char* currLine = strdup( getLinea(file, i) );

		int checker = atoi( cropToSeparator(currLine, &pos, ';') );
		if( checker )
		{
			name = strdup( cropToSeparator(currLine, &pos, ';') );
		}
		else
		{
			name = strdup("EMPTY");
		}

		scriviSVettore(&vect, i-1, name);
		i = i + 1;
	}
	fclose(file);

	return vect;
}

/***********************************************
 Nome: isLoadable;
 Input: Intero slot.
 Cosa fa: Ci dice se lo slot slot è caricabile.

 Ritorna: Valore deserializzato di check, il primo di ogni stringa.
 ***********************************************/

int isLoadable(int slot)
{
	FILE* file = fopen(savesFile, "r");
	int pos = 0;

	char* currLine = strdup( getLinea(file, slot) );
	fclose(file);
	return atoi( cropToSeparator(currLine, &pos, ';'));
}

////

/***********************************************
 Nome: loadGame;
 Input: Nulla.
 Cosa fa: Racchiude tutte le funzioni utili a caricare partite.

 Ritorna: Un Game caricabile e funzionante.
 ***********************************************/

Game loadGame()
{
	SVector names = getSaveNames();
	displayLoadGame(names);
	Game game = actionLoadGame();
	return game;
}

/***********************************************
 Nome: displayLoadGame;
 Input: Vettore di stringhe svector
 Cosa fa: Stampa a schermo il nome di ogni salvataggio caricabile.

 Ritorna: 1 a display terminato.
 ***********************************************/

int displayLoadGame(SVector svector)
{
	clear();
	printTitle();
	centerPrintString(5, "CARICA PARTITA");

	int i = 0;
	while( i < 5 )
	{
		move(LOADS_STARTING_ROW + i, LOADS_STARTING_COL);
		printw("%d) ", i + 1);
		char* tempName = leggiSVettore( svector, i );

		if( isLoadable(i + 1) )
		{
			addstr( tempName );
		}
		else
		{
			addstr("========EMPTY========");
		}

		i = i + 1;
	}
	refresh();

	return 1;
}

/***********************************************
 Nome: actionLoadGame;
 Input: Nulla.
 Cosa fa: Ti permette di selezionare uno slot valido da caricare.
 	 	  L'input è, come sempre, sanato. Si spera.

 Ritorna: Un Game, caricabile o meno.
 ***********************************************/

Game actionLoadGame()
{
	Game game;
	int selectedSlot;
	int escaper;
	int loadOK = 0;
	do
	{
		selectedSlot = getch();
		escaper = selectedSlot;
		selectedSlot = selectedSlot - '0';
		if( selectedSlot >= 1 && selectedSlot <= 5 )
		{
			if( isLoadable(selectedSlot) )
			{
				char* intBuff = calloc(7, sizeof(char));
				char* fullMsg = calloc(STD_STR_SIZE, sizeof(char));

				strcat( fullMsg, "Vuoi caricare lo slot " );
				strcat( fullMsg, itoa(selectedSlot, intBuff, 10) );
				strcat( fullMsg, "? ( Y/N )" );

				centerPrintString(20, fullMsg);
				loadOK = sceltaYN("");

				if( loadOK )
				{
					game = deserialize(selectedSlot);
					return game;
				}
				else
				{
					centerPrintString(20, "                                 ");
				}

			}

		}

	}
	while( escaper != 27 );

	setCheck(&game, 0);
	return game;
}

///////////////////////////////////////////////////
///////////////////////////////////////INCAPSULAMENTO

int getPlayers(Settings set)
{
	return set.players;
}

int getLevel(Settings set)
{
	return set.level;
}

int setPlayers(Settings* set, int val)
{
	set->players = val;
	return 1;
}

int setLevel(Settings* set, int val)
{
	set->level = val;
	return 1;
}

//

Piece newPiece(CMatrix image, int height, int colour, int shape, int consistency, int number, int status)
{
	Piece piece;
	setImage(&piece, image);
	setHeight(&piece, height);
	setColour(&piece, colour);
	setShape(&piece, shape);
	setConsistency(&piece, consistency);
	setNumber(&piece, number);
	setStatus(&piece, status);

	return piece;
}
CMatrix getImage(Piece piece)
{
	return piece.image;
}

int getHeight(Piece piece)
{
	return piece.height;
}

int getColour(Piece piece)
{
	return piece.colour;
}

int getShape(Piece piece)
{
	return piece.shape;
}

int getConsistency(Piece piece)
{
	return piece.consistency;
}

int getNumber(Piece piece)
{
	return piece.number;
}

int getStatus(Piece piece)
{
	return piece.status;
}

int setImage(Piece* piece, CMatrix image)
{
	piece->image = image;
	return 1;
}

int setHeight(Piece* piece, int height)
{
	piece->height = height;
	return 1;
}

int setColour(Piece* piece, int colour)
{
	piece->colour = colour;
	return 1;
}

int setShape(Piece* piece, int shape)
{
	piece->shape = shape;
	return 1;
}

int setConsistency(Piece* piece, int consistency)
{
	piece->consistency = consistency;
	return 1;
}

int setNumber(Piece* piece, int number)
{
	piece->number = number;
	return 1;
}

int setStatus(Piece* piece, int status)
{
	piece->status = status;
	return 1;
}

//

Game newGame(int check, char* saveName, Settings set, Matrix board, Piece* pieces, int startingPlayer, int activeStep, int turn)
{
	Game game;
	setCheck(&game, check);
	setSaveName(&game, saveName);
	setSettings(&game, set);
	setBoard(&game, board);
	setPieces(&game, pieces);
	setActivePlayer(&game, startingPlayer);
	setActiveStep(&game, activeStep);
	setTurn(&game, turn);
	return game;
}

int getCheck(Game game)
{
	return game.check;
}

char* getSaveName(Game game)
{
	return game.saveName;
}

Settings getSettings(Game game)
{
	return game.set;
}

Matrix getBoard(Game game)
{
	return game.board;
}

Piece* getPieces(Game game)
{
	return game.pieces;
}

int getActivePlayer(Game game)
{
	return game.activePlayer;
}

int getActiveStep(Game game)
{
	return game.activeStep;
}

int getTurn(Game game)
{
	return game.turn;
}

int setCheck(Game* game, int check)
{
	game->check = check;
	return 1;
}

int setSaveName(Game* game, char* name)
{
	game->saveName = name;
	return 1;
}

int setSettings(Game* game, Settings set)
{
	game->set = set;
	return 1;
}

int setBoard(Game* game, Matrix board)
{
	game->board = board;
	return 1;
}

int setPieces(Game* game, Piece* pieces)
{
	game->pieces = pieces;
	return 1;
}

int setActivePlayer(Game* game, int player)
{
	game->activePlayer = player;
	return 1;
}

int setActiveStep(Game* game, int step)
{
	game->activeStep = step;
	return 1;
}

int setTurn(Game* game, int turn)
{
	game->turn = turn;
	return 1;
}

///////////////////////////////////////////////////
///////////////////////////////////////////UTILITY

int writeSettings(Settings set)
{
	FILE* file = fopen(settingsFile, "wb");
	if( file == NULL )
	{
		printw("Non riesco ad aprire il file di configurazione!");
		exit(-1);
	}

	fwrite(&set, sizeof(Settings), 1, file);
	fclose(file);
	return 1;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
