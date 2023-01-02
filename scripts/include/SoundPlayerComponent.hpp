/*
** audio, 2022
** SoundPlayerComponent.hpp by 0xMemoryGrinder
*/

#pragma once

#include "polymorph/engine/core/component/AComponent.hpp"
#include "modules/SoundModule.hpp"

namespace polymorph::engine::audio
{
    class SoundPlayerComponent;
    using SoundPlayer = safe_ptr<SoundPlayerComponent>;

    class SoundPlayerComponent : public AComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SoundPlayerComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

            ~SoundPlayerComponent() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Sound sound;
            float volume;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void play() = 0;

            virtual void stop() = 0;

            virtual void pause() = 0;

            virtual void resume() = 0;

            virtual void setVolume(float volume) = 0;

            virtual float getVolume() = 0;

            virtual void changeAndPlay(Sound sound) = 0;


        private:


//////////////////////--------------------------/////////////////////////

    };
}