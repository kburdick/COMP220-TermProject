//
// Created by Kurt Burdick on 11/18/19.
//

#include <stdexcept>
#include <sstream>
#include "Song.h"

Song::Song() {
    this->title = "";
    this->artist = "";
    this->duration = 0;
    this->playCount = 0;
}


Song::Song(std::string title, std::string artist, int duration) {
    this->title = title;
    this->artist = artist;
    this->duration = duration;
    this->playCount = 0;
}


Song::Song(std::string songString) {

    std::stringstream splitter(songString);
    std::string songInfo = "";
    std::string titleString;
    std::string artistString;
    int durationString = 0;
    int playCountString = 0;

    //TODO: clean up this if statement with more concise code
    // it works... but looks bad
    if(splitter) {
        getline(splitter, songInfo, ',');
        titleString = songInfo;
        songInfo = "";
        getline(splitter, songInfo, ',');
        artistString = songInfo;
        songInfo = "";
        getline(splitter, songInfo, ',');
        durationString = stoi(songInfo);
        songInfo = "";
        getline(splitter, songInfo, ',');
        playCountString = stoi(songInfo);
        songInfo = "";
    }

    this->title = titleString;
    this->artist = artistString;
    this->duration = durationString;
    this->playCount = playCountString;

}

// copy constructor
Song::Song(const Song& songToCopy) {

    this->title = songToCopy.title;
    this->artist = songToCopy.artist;
    this->duration = songToCopy.duration;
    this->playCount = songToCopy.playCount;

}

Song& Song::operator=(const Song& songToCopy) {

    if(this != &songToCopy) {

        this->title = songToCopy.title;
        this->artist = songToCopy.artist;
        this->duration = songToCopy.duration;
        this->playCount = songToCopy.playCount;

    }

    //needs a return value that is a reference to another object
    return *this;
}

Song::~Song(){
    //again can use the default destructor because no data is dynamically allocated
}


//setters start
void Song::updateSongTitle(std::string title) {
    this->title = title;
}

void Song::updateSongArtist(std::string artist) {
    this->artist = artist;
}

void Song::updateSongDuration(int duration) {
    this->duration = duration;
}

void Song::updatePlayCount(int num) {
    this->playCount = playCount + num;
}
//setters end

//getters start
std::string  Song::getSongTitle() {
    return this->title;
}

std::string Song::getSongArtist() {
    return this->artist;
}

int Song::getSongDuration() {
    return this->duration;
}

int Song::getPlayCount() {
    return this->playCount;
}
//getters end


std::string Song::toString() {
    std::string songString = "";

    //example of a CSV style string
    songString = title + ", " + artist + ", " + std::to_string(duration) + ", " + std::to_string(playCount) + ",";

    return songString;
}
