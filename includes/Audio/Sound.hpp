#pragma once

#include "SFML/Audio.hpp"

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