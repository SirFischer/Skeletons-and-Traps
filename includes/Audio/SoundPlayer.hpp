#pragma once

#include <Sound.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "ResourceManager.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    std::map<SoundEffect::ID, std::string>     	mSoundNames;
	std::map<SoundEffect::ID, sf::Sound>		mSoundList;

    float                                      	mVolume;
public:
    SoundPlayer(/* args */);
    ~SoundPlayer();

    void            Play(SoundEffect::ID effect);

    void            StopSound(SoundEffect::ID effect);
    void            StopSound();

	void			SetPitch(SoundEffect::ID effect, float tPitch);
	void			SetVolume(SoundEffect::ID effect, float tVolume);

    sf::Sound       GetSound(SoundEffect::ID tEffect){return (mSoundList[tEffect]);}

};