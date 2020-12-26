#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(100.f)
{
    mFilenames[Music::MenuTheme]    = "assets/Music/MenuState.wav";
    mFilenames[Music::GameTheme]    = "assets/Music/Gamestate.wav";
}

MusicPlayer::~MusicPlayer()
{
}

void    MusicPlayer::Play(Music:: ID theme)
{
    std::string filename = mFilenames[theme];

    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + "could no be loaded.");
    mVolume = 20.f;
    mMusic.setVolume(mVolume);
    mMusic.setLoop(true);
    mMusic.play();
}

void    MusicPlayer::Stop()
{
    mMusic.stop();
}

void    MusicPlayer::SetPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}