#pragma once
#include "header.h"

using namespace std;

class Player 
{
  private:

    string firstName;
    string lastName;
    string fullName;
    int numWins = 0;
    int numLosses = 0;
    int numDraws = 0;
    char rowInput;
    int columnInput = 0;
    char gamePiece;

  public:

    /*---------------------------------------------------------
    Returns the first name
    ---------------------------------------------------------*/
    string getFirstName()
    {
      return firstName;
    }

    /*---------------------------------------------------------
    Sets the first name
    ---------------------------------------------------------*/
    void setFirstName()
    {
      cin >> firstName;
    }

    /*---------------------------------------------------------
    Returns the last name
    ---------------------------------------------------------*/
    string getLastName()
    {
      return lastName;
    }

    /*---------------------------------------------------------
    Sets the last name
    ---------------------------------------------------------*/
    void setLastName()
    {
      cin >> lastName;
    }

    /*---------------------------------------------------------
    Returns the full name
    ---------------------------------------------------------*/
    string getFullName()
    {
      return fullName;
    }

    /*---------------------------------------------------------
    Sets the full name
    ---------------------------------------------------------*/
    void setFullName(string FullName)
    {
      fullName = FullName;
    }

    /*---------------------------------------------------------
    Returns the game piece
    ---------------------------------------------------------*/
    char getGamePiece()
    {
      return gamePiece;
    }

    /*---------------------------------------------------------
    Sets the game piece
    ---------------------------------------------------------*/
    void setGamePiece (char GamePiece)
    {
      gamePiece = GamePiece;
    }

    /*---------------------------------------------------------
    Returns number of wins
    ---------------------------------------------------------*/
    int getNumWins()
    {
      return numWins;
    }

    /*---------------------------------------------------------
    Sets number of wins
    ---------------------------------------------------------*/
    void setNumWins(int NumWins)
    {
      numWins = NumWins;
    }

    /*---------------------------------------------------------
    Returns number of losses
    ---------------------------------------------------------*/
    int getNumLosses()
    {
      return numLosses;
    }

    /*---------------------------------------------------------
    Sets number of losses
    ---------------------------------------------------------*/
    void setNumLosses(int NumLosses)
    {
      numLosses = NumLosses;
    }

    /*---------------------------------------------------------
    Returns number of draws
    ---------------------------------------------------------*/
    int getNumDraws()
    {
      return numDraws;
    }

    /*---------------------------------------------------------
    Sets number of draws
    ---------------------------------------------------------*/
    void setNumDraws(int NumDraws)
    {
      numDraws = NumDraws;
    }

    /*---------------------------------------------------------
    Returns row input
    ---------------------------------------------------------*/
    char getRowInput()
    {
      return rowInput;
    }

    /*---------------------------------------------------------
    Sets row input
    ---------------------------------------------------------*/
    void setRowInput()
    {
      cin >> rowInput;
      rowInput = toupper(rowInput);
    }

    /*---------------------------------------------------------
    Returns column input
    ---------------------------------------------------------*/
    int getColumnInput()
    {
      return columnInput;
    }

    /*---------------------------------------------------------
    Sets column input
    ---------------------------------------------------------*/
    void setColumnInput(int ColumnInput)
    {
      columnInput = ColumnInput;
    }
};
