#pragma once

#include <Sound.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "ResourceManager.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    static std::map<SoundEffect::ID, std::string>     	mSoundNames;
	static std::map<SoundEffect::ID, sf::Sound>			mSoundList;

    static float                                      	mVolume;
	
	SoundPlayer(/* args */);
public:
    ~SoundPlayer();

	static void											Init();

    static void            								Play(SoundEffect::ID effect);

    static void            								StopSound(SoundEffect::ID effect);
    static void            								StopSound();

	static void											SetPitch(SoundEffect::ID effect, float tPitch);
	static void											SetVolume(SoundEffect::ID effect, float tVolume);

    static sf::Sound       								GetSound(SoundEffect::ID tEffect){return (mSoundList[tEffect]);}

};