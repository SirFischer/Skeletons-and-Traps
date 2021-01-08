#include "SoundPlayer.hpp"

SoundPlayer::SoundPlayer(/* args */)
:mSoundNames()
,mVolume(50.f)
{
    mSoundNames[SoundEffect::PlayerAttack]              = "assets/Sound effects/sword swing_01.wav";
    mSoundNames[SoundEffect::PlayerWalk]                = "assets/Sound effects/Footstep_01.wav";
    mSoundNames[SoundEffect::PlayerDeath]               = "assets/Sound effects/holnoo.wav";
    mSoundNames[SoundEffect::PlayerHit]                 = "assets/Sound effects/waterdrop_01.wav";
	mSoundNames[SoundEffect::EntityImpact]				= "assets/Sound effects/hit_084.wav";
    mSoundNames[SoundEffect::PlayerHitGround]           = "assets/Sound effects/Crouch_03.wav";
    mSoundNames[SoundEffect::PlayerJump]                = "assets/Sound effects/Crouch_01.wav";

    mSoundNames[SoundEffect::EnemyAttack]               = "assets/Sound effects/sword swing_04.wav";
    mSoundNames[SoundEffect::EnemyHit]                  = "assets/Sound effects/Door_Openning.wav";
    mSoundNames[SoundEffect::EnemyDeath]                = "assets/Sound effects/Rocks Moving.wav";

    mSoundNames[SoundEffect::TrapCollision]             = "assets/Sound effects/Rocks Moving.wav";
    mSoundNames[SoundEffect::GoalReached]               = "assets/Sound effects/itempickup.wav";
    mSoundNames[SoundEffect::MenuButtonPressed]         = "assets/Sound effects/Lever.wav";
}

SoundPlayer::~SoundPlayer()
{
}

void    SoundPlayer::Play(SoundEffect::ID effect)
{
    std::string SoundName = mSoundNames[effect];

    mSoundList[effect].setBuffer(*ResourceManager::LoadSoundBuffer(SoundName));
    mSoundList[effect].setVolume(mVolume);
    mSoundList[effect].setLoop(false);
    mSoundList[effect].play();
}

void    SoundPlayer::StopSound(SoundEffect::ID effect)
{
    mSoundList[effect].stop();
}

void    SoundPlayer::StopSound()
{
	for (auto &sound : mSoundList)
		sound.second.stop();
}