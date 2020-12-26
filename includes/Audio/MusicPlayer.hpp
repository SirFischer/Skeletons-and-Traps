#pragma once

#include "Music.hpp"
#include "SFML/Audio.hpp"
#include <map>

class MusicPlayer : sf::NonCopyable
{
private:
    sf::Music                         mMusic;
    std::map<Music::ID, std::string>  mFilenames;
    float                             mVolume;
public:
    MusicPlayer(/* args */);
    ~MusicPlayer();

    void    Play(Music::ID theme);
    void    Stop();

    void    SetPaused(bool paused);
    void    SetVolume(float volume);
};
