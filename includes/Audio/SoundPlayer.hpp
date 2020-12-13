#pragma once

#include <Sound.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include "Animation.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    SoundBufferHolder        mSoundBuffers;
    std::list<sf::Sound>     mSounds;
public:
    SoundPlayer(/* args */);
    ~SoundPlayer();

    void            Play(SoundEffect::ID effect);
    void            Play(SoundEffect::ID effect,
                         sf::Vector2f position);

    void             RemoveStoppedSounds();
    void             SetListenerPosition(sf::Vector2f position);
    sf::Vector2f     GetListenerPosition() const; 

};