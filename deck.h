// Name: Ben Wilfong
// File Name: deck.h
// Date: 13 Oct 2014
// Program Description:
//    This file contains the declarations of the functions
//    used in prog2.cpp. It also contains the declaration
//    of the Card structure used in the linked list.

#ifndef DECK_H
#define DECK_H

#include<iostream>

using namespace std;

struct Card
{
    Card* link;
    int   number;
    char  suit;
};

void addCard(Card*&, int, char);
void removeCard(Card*&, Card*);
void moveCard(Card*, Card*&);
bool consolidate(Card*&);
void displayList(Card*);

#endif
