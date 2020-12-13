#include "SoundPlayer.hpp"

SoundPlayer::SoundPlayer(/* args */)
{
    mSoundBuffers.load(SoundEffect::PlayerAttack,"assets/Sound effects/sword swing_01.wav");
    mSoundBuffers.load(SoundEffect::EnemyAttack,"assets/Sound effects/sword swing_04.wav");
}

SoundPlayer::~SoundPlayer()
{
}

void    SoundPlayer::Play(SoundEffect::ID effect)
{
   mSounds.push_back(sf::Sound(mSoundBuffers.get(effect)));
   mSounds.back().play();
}

void    SoundPlayer::RemoveStoppedSounds()
{
    mSounds.remove_if([] (const sf::Sound& s)
    {
        return s.getStatus() == sf::Sound::Stopped;
    });
}