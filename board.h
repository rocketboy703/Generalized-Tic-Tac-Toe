#pragma once
#include "header.h"

using namespace std;

class Board
{
  private:

    static const int MAXROWS = 13;
    static const int MAXCOLUMNS = 16;
    int numRows;
    int numColumns;
    char board[MAXROWS][MAXCOLUMNS];

  public:

    /*---------------------------------------------------------
    Returns number of rows
    ---------------------------------------------------------*/
    int getNumRows()
    {
      return numRows;
    }

    /*---------------------------------------------------------
    Sets number of rows
    ---------------------------------------------------------*/
    void setNumRows(int NumRows)
    {
      numRows = NumRows;
    }

    /*---------------------------------------------------------
    Returns number of columns
    ---------------------------------------------------------*/
    int getNumColumns()
    {
      return numColumns;
    }

    /*---------------------------------------------------------
    Sets number of columns
    ---------------------------------------------------------*/
    void setNumColumns(int NumColumns)
    {
      numColumns = NumColumns;
    }

  public:

    /*---------------------------------------------------------
    Fills gameboard array with space characters
    ---------------------------------------------------------*/
    void emptyBoard()
    {
      for (int i = 0; i < numRows; i++)
      {
        for (int j = 0; j < numColumns; j++)
        {
          board[i][j] = ' ';
        }
      }
    }

    /*---------------------------------------------------------
    Prints out the current state of the gameboard
    ---------------------------------------------------------*/
    void printBoard()
    {
      cout << " ";
      
      for (int i = 0; i < numColumns; i++)
      {
        if (i < 9)
        {
          cout << "   " << i + 1;
        } 
          
        else
        {
          cout << "  " << i + 1;
        }
      }

      cout << endl;
      
      for (int i = 0; i < numRows; i++)
      {
        cout << "  ";
        
        for (int j = 0; j < numColumns; j++) 
        {
          cout << " " << "---";
        }

        cout << endl;
        cout << char('A' + i) << " " << "╎";
        
        for (int j = 0; j < numColumns; j++) 
        {
          cout << " " << board[i][j] << " " << "╎";
        }
        
        cout << " " << char('A' + i);
        cout << endl;
      }

      cout << "  ";
      
      for (int i = 0; i < numColumns; i++) 
      {
        cout << " " << "---";
      }

      cout << endl;
      cout << " ";
      
      for (int i = 0; i < numColumns; i++)
      {
        if (i < 9)
        {
          cout << "   " << i + 1;
        }
          
        else 
        {
          cout << "  " << i + 1;
        }
      }
      cout << endl << endl;
    }

    /*---------------------------------------------------------
    Checks if there is already a game piece on a gameboard 
    space
    ---------------------------------------------------------*/
    bool freeSpace(char rowInput, char columnInput)
    {
      int y = int(rowInput);
      int x = int(columnInput);

      if (board[(y - 65)][x - 1] == ' ')
      {
        return true;
      }
      return false;
    }

    /*---------------------------------------------------------
    Places the last move on the gameboard
    ---------------------------------------------------------*/
    void updateBoard(char rowInput, char columnInput, char gamePiece) 
    {
      int y = int(rowInput);
      int x = int(columnInput);

      board[(y - 65)][x - 1] = gamePiece;
    }

    /*---------------------------------------------------------
    Checks for horizontal win pattern
    ---------------------------------------------------------*/
    bool checkHorizontal()
    {
      for (int i = 0; i < numRows; i++)
      {
        for (int j = 1; j < numColumns - 1; j++)
        {
          if (board[i][j] == board[i][j-1] && board[i][j] == board[i][j+1] && board[i][j] != ' ')
          {
            board[i][j] = toupper(board[i][j]);
            board[i][j-1] = toupper(board[i][j-1]);
            board[i][j+1] = toupper(board[i][j+1]);
            return true;
          }
        }
      }
      return false;
    }

    /*---------------------------------------------------------
    Checks board for vertical win pattern
    ---------------------------------------------------------*/
    bool checkVertical()
    {
      for (int i = 1; i < numRows - 1; i++)
      {
        for (int j = 0; j < numColumns; j++)
        {
          if (board[i][j] == board[i-1][j] && board[i][j] == board[i+1][j] && board[i][j] != ' ')
          {
            board[i][j] = toupper(board[i][j]);
            board[i-1][j] = toupper(board[i-1][j]);
            board[i+1][j] = toupper(board[i+1][j]);
            return true;
          }
        }
      }
      return false;
    }

    /*---------------------------------------------------------
    Checks board for diagonal win pattern 1
    ---------------------------------------------------------*/
    bool checkDiagonal1()
    {
      for (int i = 1; i < numRows - 1; i++)
      {
        for (int j = 1; j < numColumns - 1; j++)
        {
          if (board[i][j] == board[i-1][j-1] && board[i][j] == board[i+1][j+1] && board[i][j] != ' ')
          {
            board[i][j] = toupper(board[i][j]);
            board[i-1][j-1] = toupper(board[i-1][j-1]);
            board[i+1][j+1] = toupper(board[i+1][j+1]);
            return true;
          }
        }
      }
      return false;
    }

    /*---------------------------------------------------------
    Checks board for diagonal win pattern 2
    ---------------------------------------------------------*/
    bool checkDiagonal2()
    {
      for (int i = 1; i < numRows - 1; i++)
      {
        for (int j = 1; j < numColumns - 1; j++)
        {
          if (board[i][j] == board[i+1][j-1] && board[i][j] == board[i-1][j+1] && board[i][j] != ' ')
          {
            board[i][j] = toupper(board[i][j]);
            board[i+1][j-1] = toupper(board[i+1][j-1]);
            board[i-1][j+1] = toupper(board[i-1][j+1]);
            return true;
          }
        }
      }
      return false;
    }

    /*---------------------------------------------------------
    Checks board for any winning configurations
    ---------------------------------------------------------*/
    bool checkBoard()
    {
      if (checkHorizontal() == true || checkVertical() == true || checkDiagonal1() == true || checkDiagonal2() == true)
      {
        return true;
      }
      return false;
    }

    /*---------------------------------------------------------
    Calculates the maximum number of moves possible in current 
    game
    ---------------------------------------------------------*/
    int maxMoves()
    {
      int maxMoves = numRows * numColumns;
      return maxMoves;
    }
};
