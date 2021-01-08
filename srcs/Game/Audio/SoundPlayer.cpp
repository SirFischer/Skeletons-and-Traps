#include "SoundPlayer.hpp"

SoundPlayer::SoundPlayer(/* args */)
:mSoundNames()
,mVolume(50.f)
{
    mSoundNames[SoundEffect::PlayerAttack]              = "assets/Sound effects/sword swing_01.wav";
    mSoundNames[SoundEffect::PlayerWalk]                = "assets/Sound effects/footstep_grass_001.ogg";
    mSoundNames[SoundEffect::PlayerDeath]               = "assets/Sound effects/holnoo.wav";
    mSoundNames[SoundEffect::PlayerHit]                 = "assets/Sound effects/impactGlass_heavy_000.ogg";
	mSoundNames[SoundEffect::EntityImpact]				= "assets/Sound effects/impactPunch_medium_004.ogg";
    mSoundNames[SoundEffect::PlayerHitGround]           = "assets/Sound effects/Crouch_03.wav";
    mSoundNames[SoundEffect::PlayerJump]                = "assets/Sound effects/Crouch_01.wav";

    mSoundNames[SoundEffect::EnemyAttack]               = "assets/Sound effects/sword swing_04.wav";
    mSoundNames[SoundEffect::EnemyHit]                  = "assets/Sound effects/Door_Openning.wav";
    mSoundNames[SoundEffect::EnemyDeath]                = "assets/Sound effects/Rocks Moving.wav";
	mSoundNames[SoundEffect::EnemyShoot]				= "assets/Sound effects/drawKnife1.ogg";

    mSoundNames[SoundEffect::TrapCollision]             = "assets/Sound effects/Rocks Moving.wav";
    mSoundNames[SoundEffect::GoalReached]               = "assets/Sound effects/itempickup.wav";
    mSoundNames[SoundEffect::MenuButtonPressed]         = "assets/Sound effects/Lever.wav";
	mSoundNames[SoundEffect::PickUp]					= "assets/Sound effects/impactGlass_light_002.ogg";
}

SoundPlayer::~SoundPlayer()
{
}

void    SoundPlayer::Play(SoundEffect::ID effect)
{
	if (mSoundList[effect].getStatus() == sf::Sound::Playing)
		return ;
    std::string SoundName = mSoundNames[effect];

    mSoundList[effect].setBuffer(*ResourceManager::LoadSoundBuffer(SoundName));
    mSoundList[effect].setLoop(false);
    mSoundList[effect].play();
}

void    SoundPlayer::StopSound(SoundEffect::ID effect)
{
    mSoundList[effect].stop();
}

void	SoundPlayer::SetPitch(SoundEffect::ID effect, float tPitch)
{
	mSoundList[effect].setPitch(tPitch);
}

void	SoundPlayer::SetVolume(SoundEffect::ID effect, float tVolume)
{
	mSoundList[effect].setVolume(tVolume * mVolume);
}



void    SoundPlayer::StopSound()
{
	for (auto &sound : mSoundList)
		sound.second.stop();
}