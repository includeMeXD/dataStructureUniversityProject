#include "header.h"

// --- PARENT LIST (GENRE) OPERATIONS ---

void createListGenre(ListGenre &L) {
    first(L) = Nil;
}

adrGenre alokasiGenre(string name) {
    adrGenre P = new ElmGenre;
    info(P) = name;
    next(P) = Nil;
    createListMovie(movies(P)); // Initialize the child list
    return P;
}

void insertLastGenre(ListGenre &L, adrGenre P) {
    if (first(L) == Nil) {
        first(L) = P;
    } else {
        adrGenre Q = first(L);
        while (next(Q) != Nil) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrGenre findGenre(ListGenre L, string name) {
    adrGenre P = first(L);
    while (P != Nil) {
        if (info(P) == name) {
            return P;
        }
        P = next(P);
    }
    return Nil;
}

void showGenres(ListGenre L) {
    adrGenre P = first(L);
    int i = 1;
    cout << "\n=== GENRE LIST ===" << endl;
    if (P == Nil) {
        cout << "No genres available." << endl;
    } else {
        while (P != Nil) {
            cout << i << ". " << info(P) << endl;
            P = next(P);
            i++;
        }
    }
    cout << "==================" << endl;
}

// --- CHILD LIST (MOVIE) OPERATIONS (DLL) ---

void createListMovie(ListMovie &L) {
    first(L) = Nil;
    last(L) = Nil;
}

adrMovie alokasiMovie(string title, string desc) {
    adrMovie P = new ElmMovie;
    info(P).title = title;
    info(P).description = desc;
    next(P) = Nil;
    prev(P) = Nil;
    return P;
}

void insertLastMovie(ListMovie &L, adrMovie P) {
    if (first(L) == Nil) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

// --- MLL CONNECTION ---

void connectMovieToGenre(ListGenre &L, string genreName, adrMovie M) {
    adrGenre G = findGenre(L, genreName);
    if (G != Nil) {
        insertLastMovie(movies(G), M);
    } else {
        cout << "Genre '" << genreName << "' not found!" << endl;
    }
}

// --- APP LOGIC ---

void watchMovie(adrMovie M) {
    cout << "\n-------------------------------------------------" << endl;
    cout << "   WATCHING: " << info(M).title << endl;
    cout << "   " << info(M).description << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "   [Playing...] " << endl;
    // Simulate delay or interaction
    cout << "   Movie Finished!" << endl;
    cout << "-------------------------------------------------" << endl;
}

void showMovieNavigator(adrGenre G) {
    if (first(movies(G)) == Nil) {
        cout << "\n[!] No movies in " << info(G) << " genre yet." << endl;
        return;
    }

    adrMovie current = first(movies(G));
    char choice;
    bool inMovieMenu = true;

    while (inMovieMenu) {
        cout << "\n=== " << info(G) << " MOVIE LIST ===" << endl;
        cout << "Current Movie: " << info(current).title << endl;
        cout << "Description  : " << info(current).description << endl;
        cout << "------------------------" << endl;

        // Navigation Options
        cout << "[W] Watch Movie" << endl;

        if (next(current) != Nil) cout << "[N] Next Movie" << endl;
        if (prev(current) != Nil) cout << "[P] Previous Movie" << endl;

        cout << "[B] Back to Genre List" << endl;
        cout << "Select > ";
        cin >> choice;

        if (choice == 'w' || choice == 'W') {
            watchMovie(current);
        }
        else if ((choice == 'n' || choice == 'N') && next(current) != Nil) {
            current = next(current);
        }
        else if ((choice == 'p' || choice == 'P') && prev(current) != Nil) {
            current = prev(current);
        }
        else if (choice == 'b' || choice == 'B') {
            inMovieMenu = false;
        }
        else {
            cout << "Invalid selection or end of list." << endl;
        }
    }
}
