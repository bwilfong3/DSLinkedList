// Name: Ben Wilfong
// File Name: deck.h
// Date: 13 Oct 2014
// Program Description: 
//     This file contains the definitions for all functions
//     used in prog2.cpp

#include<iostream>

using namespace std;

#include "deck.h"


/* addCard() adds a new card at the beginning of
   the linked list. It is done by creating a new
   card that points to what the head pointer is pointing to.
   The data of the card is set, then the head pointer is pointed
   to the new card.
*/

void addCard(Card*& head, int number, char suit)
{
    Card* pNew   = new Card;
    pNew->link   = head;
    pNew->number = number;
    pNew->suit   = suit;
    head = pNew;   
}//end addcard()



/* displayList() accepts the head pointer of the linked list
   and displays each Card with a space in between. Since the
   numbers are all stored as integers (even the J,Q,K,A cards)
   a switch statement is used to reprocess the numbers and 
   display them according to card standards. The same is
   done for the suits, which are initially being stored as
   characters. The suit character is run thru a switch statement
   and displayed as its unicode-equivalent suit symbol.
   After each card is displayed, the walker pointer is
   set to the next available Card until it reaches the end of
   the linked list.
*/

void displayList(Card* head)
{
    Card* walker = head;
    while(walker != NULL)
    {
         switch(walker->number)
         {
             case 1  : cout << "10";
                 break;
             case 11 : cout << "J";
                 break;
             case 12 : cout << "Q";
                 break;
             case 13 : cout << "K";
                 break;
             case 14 : cout << "A";
                 break;
             default : cout << walker->number;
         }//end switch

         switch(walker->suit)
         {
             case 'H' : cout << "\u2665";
                 break;
             case 'S' : cout << "\u2660";
                 break;
             case 'C' : cout << "\u2663";
                 break;
             case 'D' : cout << "\u2666";
                 break;
         }//end switch
                   
         if (walker->link != NULL)
             cout << " ";

         walker = walker->link;
    }//end while
    
    cout << endl;
}//end displayList()




/* consolidate() accepts the head pointer by reference (so the list
   can be changed). It checks every possible match for each card,
   starting at the head pointer, which points to the first card.
   The card is pointed to by a 'walker' pointer that first checks
   if there is a following card available to be checked. If so,
   then we check to see if the following card is a match. If that
   condition is met, the card pointed to by walker's data is moved
   to the matching card (using moveCard()), and then the removeCard()
   function is called to delete the card pointed to by walker. In this
   case, the function returns true, because a consolidation is done.
   If the first card is not a match, then the third card will be checked
   to see if it exists, and if it does, if it is a match. The same 
   technique is used for the third card. After the 1st and 3rd are checked,
   the walker is moved to the next card and the loop repeats. If no matches
   are ever found, the function returns false meaning no consolidations 
   were performed. 
*/

bool consolidate(Card*& head)
{
    Card* walker = head;

    while (walker != NULL) //traverses linked list until the end
    {
        if (walker->link != NULL) //checks to see if following card exists (1st)
        {
            if ((walker->number == (walker->link)->number)|| //if suit or number is equal
                (walker->suit   == (walker->link)->suit))
            {
                moveCard(walker, walker->link); //move the drawn card to the matching card
                removeCard(head, walker);       //delete the Card that has been moved
                return true;                    //return true for successful consolidation
            }

        else if (walker->link != NULL &&
                (walker->link)->link != NULL &&
                ((walker->link)->link)->link != NULL) //checks to see if 3rd following card exists.
                {
                    if ((walker->number == (((walker->link)->link)->link)->number)||
                        (walker->suit   == (((walker->link)->link)->link)->suit))
                    {
                        moveCard(walker, ((walker->link)->link)->link);
                        removeCard(head, walker);
                        return true;
                    }
                }
        }    
        walker = walker->link;//traverse to next Card
    }//end while

    return false; //returns false if no consolidation was performed    
}//end consolidate()



/* This function is quite simple. moveCard() accepts the
   current card and its matching card. The data from the
   current card is moved over to the destination card.
*/

void moveCard(Card* current, Card*& destination)
{
    destination->number = current->number;
    destination->suit   = current->suit;
}//end moveCard()



/* The removeCard() function accepts the head pointer
   to the linked list and the pointer to the card
   to be removed as arguments. If the removed card
   is the first on the list, the head is pointed
   to the following card and then the removal 
   card is deleted. The pointer to the removal
   card is set to null. 

   If the card to be removed is NOT the 1st card,
   then a preCard pointer is to traverse the list
   until it finds the Card just before the removal.
   The preCard is pointed to the Card that removal
   was pointing to and then removal is deallocated
   and then set to null.
*/

void removeCard(Card*& head, Card* removal)
{

    if (head == removal)
    {
        head = removal->link;
        delete removal;
        removal = NULL;
    }
    
    else
    {
        Card* preCard = head;

        while((preCard->link != removal) && (preCard->link != NULL)) // find the card before the target
            preCard = preCard->link;

        preCard->link = removal->link;
    
        delete removal;
        removal = NULL;
    }    
}//end removeCard()


