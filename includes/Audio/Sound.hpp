#pragma once

#include "ResourceHolder.hpp"

namespace SoundEffect
{
    enum ID
    {
        PlayerWalk,
        PlayerJump,
        PlayerAttack,
        PlayerDeath,
        PlayerHit,
        PlayerHitGround,

        EnemyWalk,
        EnemyJump,
        EnemyAttack,
        EnemyHit,

        TrapCollision,

        GoalReached,

        MenuButtonPressed,
    };
}

typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>
SoundBufferHolder;