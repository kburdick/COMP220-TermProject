//
// Created by Kurt Burdick on 12/4/19.
//

#include <iostream>
#include "UserInterface.h"
#include "MusicLibrary.h"
#include "Playlist.h"

int main() {

    MusicLibrary* musicLibrary = new MusicLibrary();
    Playlist* playListsMade = new Playlist[20]; //not efficient, and not the proper way to do this... SHOULD MAKE USER INTERFACE OBJECTS TO INTERFACE WITH THE MUSIC LIBRARY CLASS?
    //Make the playlist pointer array that can hold onto our new playlists, and make the playlist names a property of the list like front/end

    std::cout << "\n#################################" << std::endl;
    std::cout << "### Welcome to the Virtual DJ ###" << std::endl;
    std::cout << "#################################\n" << std::endl;
    std::cout << "### Authors: ###\n" << "- Kurt Burdick\n" << "- Wyatt Vigilante\n" << "- Robert Melikyan\n" << std::endl;

    std::cout << "Enter 'help' for a list of the available commands\n" << std::endl;

    std::string inputString = "";
    std::string selectionString = "";


    while(inputString != "quit"){

        std::string playlistIn = "";
        std::string artistIn = "";
        std::string titleIn = "";

        std::cout << "\nEnter a command key to search or edit by: \n" << std::endl;
        getline (std::cin, inputString);

        if(inputString == "help"){

            help();
        }

        if(inputString == "library") {

            std::cout << "Listing all the songs in your Library: \n" << std::endl;
            library(musicLibrary);
        }

        if(inputString == "artist") {

            std::cout << "Enter an artist: \n" << std::endl;
            getline(std::cin, artistIn);

            std::cout << "Displaying all songs for the given artist: \n" << std::endl;
            //artist(artistIn, musicLibrary);

            //call function to display all songs by artist
            //TODO algorithm that goes through the library array and makes a copy of each song into another array that matches the
            // desired artist and then  prints the contents of that array and deletes it
        }

        if(inputString == "song") {

            std::cout << "Enter a song: \n" << std::endl;
            getline(std::cin, selectionString);

            std::cout << "Displaying song information: \n" << std::endl;
            //do something else song(selectionString);

        }


        if(inputString == "import"){
            std::cout << "Enter the file to be loaded: \n" << std::endl;
            getline(std::cin, selectionString);

            import(selectionString, musicLibrary);

            //TODO how do we hold onto the library and playlists for use by the user?
            // create the pointers in here and only allow the user to access them through the interface?
        }

        if(inputString == "discontinue") {

            std::cout << "Enter a file name: \n" << std::endl;
            getline(std::cin, selectionString);

            discontinue(selectionString, musicLibrary);
            //discontinue(selectionString); called on the music library again inside of the user interface??

        }

        if(inputString == "playlists") {

            std::cout << "Listing all available playlists: \n" << std::endl;
            playlists(); //should just print an array of the playlist names that were made by the user
        }

        if(inputString == "playlist") {

            std::cout << "Enter a playlist name: \n" << std::endl;
            getline(std::cin, selectionString);
            std::cout << "Listing songs left in the playlist: \n" << std::endl;
            playlist(selectionString); //printing all songs left in the playlists
        }

        if(inputString == "new") {

            std::cout << "Enter a name for the playlist: \n" << std::endl;
            getline(std::cin, selectionString);
            //new(selectionString); makes a new empty playlist, and adds to the available playlists
        }

        if(inputString == "add"){

            std::cout << "Enter the name of the playlist: \n" << std::endl;
            getline(std::cin, playlistIn);

            std::cout << "Enter the name of the artist: \n" << std::endl;
            getline(std::cin, artistIn);

            std::cout << "Enter the name of the title: \n" << std::endl;
            getline(std::cin, titleIn);

            //add(playlistIn, artistIn, titleIn, 0); //update function to add songs to playlist
        }

        if(inputString == "remove"){

            std::cout << "Enter the name of the playlist: \n" << std::endl;
            getline(std::cin, playlistIn);

            std::cout << "Enter the name of the artist: \n" << std::endl;
            getline(std::cin, artistIn);

            std::cout << "Enter the name of the title: \n" << std::endl;
            getline(std::cin, titleIn);

            //remove(playlistIn, artistIn, titleIn); // update function to add songs to playlist
        }

        if(inputString == "playnext"){

            std::cout << "Enter playlist to play song from: \n" << std::endl;
            getline(std::cin, playlistIn);

            //playNext(playlistIn); //update function to play next song from the playlist

        }

        if(inputString == "newrandom"){

            std::cout << "Enter new playlist name: \n" << std::endl;
            getline(std::cin, playlistIn);

            std::cout << "Enter desired length of the playlist (in seconds): \n" << std::endl;
            getline(std::cin, selectionString);

            newRandom(playlistIn, stoi(selectionString));
        }

        if(inputString == "quit"){
            quit(playlistIn, musicLibrary);
        }
    }

    return 0;
}
