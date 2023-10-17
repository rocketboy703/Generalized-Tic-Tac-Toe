#pragma once
#include "header.h"

using namespace std;

class Game
{
  private:

    const static int MAXPLAYERS = 7;
    int numPlayers = 0;
    int numGames = 0;
    int numMoves = 0;
    int turn = 0;
    int counter = 0;
    int num = 0;
    string input;
    char playQuit;
    char gamePieces[MAXPLAYERS];
    Player players[MAXPLAYERS];
    Board board;
    
  public:

    /*---------------------------------------------------------
    Prints introduction prompts and requests basic game data
    ---------------------------------------------------------*/
    void intro() 
    {
      cout << "Welcome to Tic-Tac-Toe!" << endl << endl;
      cout << "Enter the number of players (3-7 Players allowed): ";

      do 
      {
        validateInt();
        storeInt();
        numPlayers = num;

        if (storeInt() == 0 || numPlayers < 3 || numPlayers > 7)
        {
          cout << endl << endl;
          cout << "That input is invalid. Please enter a number between 3 and 7: ";
        }
      } while (storeInt() == 0 || numPlayers < 3 || numPlayers > 7);
      
      num = 0;
      
      cout << endl;

      getNames();
      assignGamePieces();

      for (int i = 0; i < numPlayers; i++)
      {
        cout << players[i].getFullName() << " (" << gamePieces[i] << ")";
        cout << endl;
      }
      
      cout << endl;

      turn = 2;
    }

    /*---------------------------------------------------------
    Requests and stores the names of each player
    ---------------------------------------------------------*/
    void getNames()
    {
      for (int i = 0; i < numPlayers; i++)
      {
        cout << "Enter the first and last name of player " << i + 1 << ": ";
        
        players[i].setFirstName();
        players[i].setLastName();

        while (validateName(players[i].getFirstName()) == false || validateName(players[i].getLastName()) == false)
        {
          cout << "That input is invalid. Please only use alphabetical characters: ";

          players[i].setFirstName();
          players[i].setLastName();
        }
        
        players[i].setFullName(string(players[i].getFirstName() + " " + players[i].getLastName()));
        cout << endl;
      }
    }

    /*---------------------------------------------------------
    Creates gameboard based on user specification
    ---------------------------------------------------------*/
    void buildBoard()
    {
      cout << "Enter the number of rows (4-13 Rows allowed): ";
      
      do 
      {
        validateInt();
        storeInt();
        board.setNumRows(num);

        if (storeInt() == 0 || board.getNumRows() < 4 || board.getNumRows() > 13)
        {
          cout << endl << endl;
          cout << "That input is invalid. Please enter a number between 4 and 13: ";
        }
      } while (storeInt() == 0 || board.getNumRows() < 4 || board.getNumRows() > 13);
      
      num = 0;

      cout << endl;
      cout << "Enter number of columns (4-16 Columns allowed): ";
      
      do 
      {
        validateInt();
        storeInt();
        board.setNumColumns(num);

        if (storeInt() == 0 || board.getNumColumns() < 4 || board.getNumColumns() > 16)
        {
          cout << endl << endl;
          cout << "That input is invalid. Please enter a number between 4 and 16: ";
        }
      } while (storeInt() == 0 || board.getNumColumns() < 4 || board.getNumColumns() > 16);
      
      num = 0;
      
      cout << endl;

      board.emptyBoard();
    }

    /*---------------------------------------------------------
    Loops through each player and assigns a game piece
    ---------------------------------------------------------*/
    void assignGamePieces()
    {
      for (int i = 0; i < numPlayers; i++)
      {
        gamePieces[i] = char('a' + i);
        players[i].setGamePiece(gamePieces[i]);
      }
    }

    /*---------------------------------------------------------
    Checks name for usage of only alphabetical characters
    ---------------------------------------------------------*/
    bool validateName(string name)
    {
      for (int i = 0; i < name.length(); i++)
      {
        if (name[i] < 'A' || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z')
        {
          return false;
        }
      }
      return true;
    }

    /*---------------------------------------------------------
    Checks user input for a valid integer
    ---------------------------------------------------------*/
    bool validateInt()
    {
      cin >> input;
      
      for (int i = 0; i < input.length(); i++)
      {
        for (int k = 0; k < 9; k++)
        {
          if (int(input[i]) == (k + 49))
          {
            counter++;
            
            if (counter == 2 || counter == 1)
            {
              return true;
            }
          }
        }
      }
      counter = 0;
      
      return false;
    }

    /*---------------------------------------------------------
    Takes an int stored in a string and attempts to store it 
    in an int
    ---------------------------------------------------------*/
    bool storeInt()
    {
      try
      {
        num = stoi(input);
        
        return true;
      }
        
      catch (const exception& e)
      {
        return false;
      }
    }

    /*---------------------------------------------------------
    Asks current player for move and stores the input
    ---------------------------------------------------------*/
    void getMove()
    {
      do
      {
        cout << players[turn].getFirstName() << " (" << players[turn].getGamePiece() << ")" << " enter your move: ";

        players[turn].setRowInput();
        
        validateInt();
        storeInt();
        players[turn].setColumnInput(num);
        
        
        if (int(players[turn].getRowInput()) < 65 || int(players[turn].getRowInput()) > (board.getNumRows() + 64) ||       
            players[turn].getColumnInput() < 1 || players[turn].getColumnInput() > board.getNumColumns() || storeInt() == 0 || 
            board.freeSpace(players[turn].getRowInput(), players[turn].getColumnInput()) == 0)
          {
            cout << endl;
            cout << "That input is invalid. Please try again." << endl << endl;
          }
        
        } while (int(players[turn].getRowInput()) < 65 || int(players[turn].getRowInput()) > (board.getNumRows() + 64) || 
          players[turn].getColumnInput() < 1 || players[turn].getColumnInput() > board.getNumColumns() || storeInt() == 0 ||     
          board.freeSpace(players[turn].getRowInput(), players[turn].getColumnInput()) == 0);
      cout << endl;
    }

    /*---------------------------------------------------------
    Rotates the player turns
    ---------------------------------------------------------*/
    void switchTurn()
    {
      if (turn < numPlayers - 1)
      {
        turn++;
      }
        
      else
      {
        turn = 0;
      }
    }

    /*---------------------------------------------------------
    Updates the scores of each player
    ---------------------------------------------------------*/
    void updateScore() 
    {
      if (board.checkBoard() == true)
      {
        players[turn - 1].setNumWins(players[turn - 1].getNumWins() + 1);

        for (int i = 0; i < numPlayers; i++)
        {
          if (i != turn - 1)
          players[i].setNumLosses(players[i].getNumLosses() + 1);
        }
      }
        
      else
      {
        for (int i = 0; i < numPlayers; i++) 
        {
          players[i].setNumDraws(players[i].getNumDraws() + 1);
        }
      }
    }

    /*---------------------------------------------------------
    Formats the game stat numbers to fit in a thousands place 
    box
    ---------------------------------------------------------*/
    string thousand(int num) 
    {
      string temp;
    
      if (num < 10)
      {
        temp = "   " + to_string(num);
      }
        
      else if (num > 9 && num < 100 )
      {
        temp = "  " + to_string(num);
      }
        
      else if (num > 99 && num < 1000 )
      {
        temp = " " + to_string(num);
      }
        
      else if (num == 1000 )
      {
        temp = "" + to_string(num);
      }
      return temp;
      }

    /*---------------------------------------------------------
    Prints player stats
    ---------------------------------------------------------*/
    void gameStats()
    {
      cout << setw(117) << "Total games played: " << numGames << endl << endl;
      
      cout << setw(140) << right << " ------ ------ ------ " << endl;
      cout << setw(148) << right << "╎  WIN ╎ LOSS ╎ DRAW ╎" << endl;
      cout << setw(140) << right << " ------ ------ ------ " << endl;
  
      for (int i = 0; i < numPlayers; i++)
      {
        cout << setw(117) << right << players[i].getFullName() << " ╎ " << thousand(players[i].getNumWins()) <<  " ╎ " <<           
        thousand(players[i].getNumLosses()) <<  " ╎ " << thousand(players[i].getNumDraws()) <<  " ╎" << endl;
        cout << setw(140) << right << " ------ ------ ------ " << endl;
      }
      cout << endl << endl;
    }

    /*---------------------------------------------------------
    Asks user to type “Y” or “N” and returns the character
    ---------------------------------------------------------*/
    char playOrQuit()
    {
      cout << "Do you want to play again? (Y/N) ";
      cin >> playQuit;

      while (toupper(playQuit) != 'Y' && toupper(playQuit) != 'N') 
      {
        cout << endl << endl;
        cout << "That intput is invalid. Please enter 'Y' or 'N': ";
        cin >> playQuit;
      }
      
      cout << endl;

      return playQuit;
    }

    /*---------------------------------------------------------
    Performs the bulk of the programs procedures
    ---------------------------------------------------------*/
    void runGame()
    {
      do
      {
        buildBoard();
        board.printBoard();

        while (board.checkBoard() == false && numMoves < (board.maxMoves()))
        {
          getMove();
          board.updateBoard(players[turn].getRowInput(), players[turn].getColumnInput(), players[turn].getGamePiece());
          board.printBoard();
          switchTurn();

          numMoves++;
        }
        numGames++;
        updateScore();
        board.printBoard();
        board.emptyBoard();
        gameStats();
        playOrQuit();

        numMoves = 0;
        
      } while (toupper(playQuit) == 'Y');
    }

    /*---------------------------------------------------------
    Prints end program statement
    ---------------------------------------------------------*/
    void outro()
    {
      cout << "Thank you for playing!";
    }
};
