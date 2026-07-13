#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(ShipFix, PlayerObject) {
    virtual std::string m_gameMode() {
        if (this->m_isShip) return "Ship";
    }

    virtual void update(float dt) {
        PlayerObject::update(dt);
        PlayLayer* playLayer = PlayLayer::get();

        if (!this || !playLayer) return;
        this->m_gravityMod = 1.0f;

        if (this->m_isShip && this->m_isUpsideDown) {
            this->m_gravityMod = 0.875f;
        }

        //     if (this && this->m_isShip && playLayer && playLayer->m_gameState.m_isDualMode) {
        //         this->m_gravityMod = 0.800f;
        //     }
        //     else {
        //         this->m_gravityMod = 1.0f;
        //     }
        // }
        // else {
        //     this->m_gravityMod = 1.0f;
        // }
    }

    void debug() {
        log::info(

            "gravityMod {:2f}, gravity {:2f}, yVelocity {:2f}", m_gravityMod, m_gravity, m_yVelocity,

        );

        debug();
    }
};
