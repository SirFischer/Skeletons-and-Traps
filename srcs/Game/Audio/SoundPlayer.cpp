#include "SoundPlayer.hpp"

std::map<SoundEffect::ID, std::string>     	SoundPlayer::mSoundNames = std::map<SoundEffect::ID, std::string>();
std::map<SoundEffect::ID, sf::Sound>		SoundPlayer::mSoundList = std::map<SoundEffect::ID, sf::Sound>();
float                                      	SoundPlayer::mVolume = 50.f;



SoundPlayer::SoundPlayer(/* args */)
{
    
}

SoundPlayer::~SoundPlayer()
{
}

void	SoundPlayer::Init()
{
	SoundPlayer::mSoundNames[SoundEffect::PlayerAttack]              = "assets/Sound effects/sword swing_01.wav";
	SoundPlayer::mSoundNames[SoundEffect::PlayerWalk]                = "assets/Sound effects/footstep_grass_001.ogg";
	SoundPlayer::mSoundNames[SoundEffect::PlayerDeath]               = "assets/Sound effects/holnoo.wav";
	SoundPlayer::mSoundNames[SoundEffect::PlayerHit]                 = "assets/Sound effects/impactGlass_heavy_000.ogg";
	SoundPlayer::mSoundNames[SoundEffect::EntityImpact]				= "assets/Sound effects/impactPunch_medium_004.ogg";
	SoundPlayer::mSoundNames[SoundEffect::PlayerHitGround]           = "assets/Sound effects/Crouch_03.wav";
	SoundPlayer::mSoundNames[SoundEffect::PlayerJump]                = "assets/Sound effects/Crouch_01.wav";

	SoundPlayer::mSoundNames[SoundEffect::EnemyAttack]               = "assets/Sound effects/sword swing_04.wav";
	SoundPlayer::mSoundNames[SoundEffect::EnemyHit]                  = "assets/Sound effects/Door_Openning.wav";
	SoundPlayer::mSoundNames[SoundEffect::EnemyDeath]                = "assets/Sound effects/Rocks Moving.wav";
	SoundPlayer::mSoundNames[SoundEffect::EnemyShoot]				= "assets/Sound effects/drawKnife1.ogg";

	SoundPlayer::mSoundNames[SoundEffect::TrapCollision]             = "assets/Sound effects/Rocks Moving.wav";
	SoundPlayer::mSoundNames[SoundEffect::GoalReached]               = "assets/Sound effects/itempickup.wav";
	SoundPlayer::mSoundNames[SoundEffect::MenuButtonPressed]         = "assets/Sound effects/Lever.wav";
	SoundPlayer::mSoundNames[SoundEffect::PickUp]					= "assets/Sound effects/impactGlass_light_002.ogg";
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