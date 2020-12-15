#pragma once

#include <Sound.hpp>
#include <SFML/Audio.hpp>
#include <map>

class SoundPlayer : sf::NonCopyable
{
private:
    sf::Sound                                  mSound;
    sf::SoundBuffer                            mBuffer;
    std::map<SoundEffect::ID, std::string>     mSoundNames;
    float                                      mVolume;
public:
    SoundPlayer(/* args */);
    ~SoundPlayer();

    void            Play(SoundEffect::ID effect);

    void             RemoveStoppedSounds();
    void             SetListenerPosition(sf::Vector2f position);

};