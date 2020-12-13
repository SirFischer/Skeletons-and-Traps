#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(100.f)
{
    mFilenames[Music::MenuTheme]    = "assets/Audio/Sounnd effects/Music themes/extra_G#_122bpm_dripchord.wav";
    mFilenames[Music::GameTheme]    = "assets/Audio/Sounnd effects/Music themes/musicbyaden-rise.wav";
}

MusicPlayer::~MusicPlayer()
{
}

void    MusicPlayer::Play(Music:: ID theme)
{
    std::string filename = mFilenames[theme];

    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + "could no be loaded.");

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