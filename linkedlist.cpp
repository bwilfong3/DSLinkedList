// Name: Ben Wilfong
// File Name: linkedlist.cpp
// Date: 13 Oct 2014
// Program Description:
//     This program simulates a skip-3 style solitaire game.
//
//     The program will read and process card data from a text file
//     card-by-card, until there are no more cards to be
//     processed. Each time a card is read, it is added
//     to the left hand side of a linked list, then the
//     list is displayed, with a number preceding to
//     indicate how many cards have been dealt. After
//     a card is added to a linked list, a consolidation
//     function is called within a while loop, returning
//     a true value each time a consolidation is done.
//     Each time the consolidation is done, the list
//     of cards is displayed again, reordered from the
//     consolidation. After no more consolidations can
//     be done, the next card is drawn, until no more cards
//     are available.



#include <iostream>
#include <fstream>
#include <iomanip>

#include "deck.h"

using namespace std;

int main(int argc, char* argv[])
{
    Card* head = NULL;
    int   dealCount = 0;
    char  temp, cardChar;
    int   cardNumber;

    ifstream myFile;
    myFile.open(argv[1]); //open file passed in command line

    if (!myFile)
        cout << "File open failed" << endl;  //check to see if file opened

    while (myFile >> temp)
    {
        switch(temp)
        {
            case '1':
                cardNumber = 10;    // Because there is no number 1 in playing cards,
                break;              // a 1 must indicate the first digit in the number 10.
            case 'J':
                cardNumber = 11;    //anything higher than 10 is stored as an integer
                break;
            case 'Q':
                cardNumber = 12;
                break;
            case 'K':
                cardNumber = 13;
                break;
            case 'A':
                cardNumber = 14;
                break;
            default:
                cardNumber = temp - 48;// All numbers that aren't a special case
        }

        myFile >> temp;      //get the suit after the number is processed

        if (temp == '0')     // This code takes care of the number 10,
            myFile >> temp;  // the only case where the number would be
                             // more than one character


        cardChar = temp; //If a number is processed, then the following character will have to be the suit

        addCard(head, cardNumber, cardChar); //add the card to the list
        dealCount++;                         //increment the deal count to be displayed

        cout << setw(2) << dealCount << ": "; //A bit of formatting here..
        displayList(head);                    //display the list with the added card

        while(consolidate(head))    //loop to performed all consolidations needed
        {
            cout << "    ";         //more formatting
            displayList(head);      //displays the new linked list each time a consolidation is done
        }//end while
    }//end while
}//end main

