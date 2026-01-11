#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
#define movies(P) (P)->movies

// --- DEFINITION OF TYPES ---

// Child: Movie (Doubly Linked List)
struct MovieData {
    string title;
    string description;
};

typedef MovieData infotypeMovie;
typedef struct ElmMovie *adrMovie;

struct ElmMovie {
    infotypeMovie info;
    adrMovie next;
    adrMovie prev;
};

struct ListMovie {
    adrMovie first;
    adrMovie last;
};

// Parent: Genre (Singly Linked List)
typedef string infotypeGenre;
typedef struct ElmGenre *adrGenre;

struct ElmGenre {
    infotypeGenre info;
    adrGenre next;
    ListMovie movies; // Child list attached to parent node
};

struct ListGenre {
    adrGenre first;
};

// --- PRIMITIVE FUNCTIONS ---

// Genre Operations (Parent - SLL)
void createListGenre(ListGenre &L);
adrGenre alokasiGenre(string name);
void insertLastGenre(ListGenre &L, adrGenre P);
adrGenre findGenre(ListGenre L, string name);
void showGenres(ListGenre L);

// Movie Operations (Child - DLL)
void createListMovie(ListMovie &L);
adrMovie alokasiMovie(string title, string desc);
void insertLastMovie(ListMovie &L, adrMovie P);

// MLL Utilities
void connectMovieToGenre(ListGenre &L, string genreName, adrMovie M);

// Application Logic
void showMenuGenres(ListGenre L);
void showMovieNavigator(adrGenre G);
void watchMovie(adrMovie M);

#endif // HEADER_H_INCLUDED
