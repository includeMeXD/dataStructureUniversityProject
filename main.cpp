#include "header.h"

int main() {
    ListGenre L;
    createListGenre(L);

    // --- 1. DATA INITIALIZATION ---
    // Creating Genres
    insertLastGenre(L, alokasiGenre("Action"));
    insertLastGenre(L, alokasiGenre("Sci-Fi"));
    insertLastGenre(L, alokasiGenre("Drama"));
    insertLastGenre(L, alokasiGenre("Horror"));

    // Creating Movies and connecting to Action
    connectMovieToGenre(L, "Action", alokasiMovie("Mad Max: Fury Road", "A high-octane post-apocalyptic chase."));
    connectMovieToGenre(L, "Action", alokasiMovie("John Wick", "A retired hitman seeks vengeance."));
    connectMovieToGenre(L, "Action", alokasiMovie("The Dark Knight", "Batman faces the Joker in Gotham."));
    connectMovieToGenre(L, "Action", alokasiMovie("Die Hard", "An NYPD officer tries to save his wife and several others taken hostage."));
    connectMovieToGenre(L, "Action", alokasiMovie("Gladiator", "A former Roman General sets out to exact vengeance against the corrupt emperor."));


    // Creating Movies and connecting to Sci-Fi
    connectMovieToGenre(L, "Sci-Fi", alokasiMovie("Interstellar", "Explorers travel through a wormhole in space."));
    connectMovieToGenre(L, "Sci-Fi", alokasiMovie("Inception", "A thief steals secrets through dreams."));
    connectMovieToGenre(L, "Sci-Fi", alokasiMovie("Blade Runner 2049", "A new blade runner unearths a long-buried secret."));
    connectMovieToGenre(L, "Sci-Fi", alokasiMovie("The Matrix", "A computer hacker learns about the true nature of his reality."));

    // Creating Movies and connecting to Drama
    connectMovieToGenre(L, "Drama", alokasiMovie("The Shawshank Redemption", "Two imprisoned men bond over a number of years."));
    connectMovieToGenre(L, "Drama", alokasiMovie("Forrest Gump", "The life story of a man with a low IQ who achieved great things."));
    connectMovieToGenre(L, "Drama", alokasiMovie("The Godfather", "The aging patriarch of an organized crime dynasty transfers control to his son."));

    // Creating Movies and connecting to Horror
    connectMovieToGenre(L, "Horror", alokasiMovie("The Shining", "A family heads to an isolated hotel for the winter where a sinister presence influences the father into violence."));
    connectMovieToGenre(L, "Horror", alokasiMovie("Get Out", "A young African-American man visits his white girlfriend's parents for the weekend, where his simmering uneasiness about their reception eventually reaches a boiling point."));

    // --- 2. MAIN CLI LOOP ---
    string inputGenre;
    bool running = true;

    while (running) {
        showGenres(L);
        cout << "Type the genre name to enter (or 'exit' to quit): ";
        cin >> inputGenre;

        if (inputGenre == "exit") {
            running = false;
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            // Find the genre
            adrGenre selectedGenre = findGenre(L, inputGenre);
            if (selectedGenre != Nil) {
                // Enter Movie Navigator for that genre
                showMovieNavigator(selectedGenre);
            } else {
                cout << "\n[!] Genre not found. Please type exactly as shown." << endl;
            }
        }
    }

    return 0;
}
