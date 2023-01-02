

/*
** audio, 2022
** SoundPlayerImpl.hpp by 0xMemoryGrinder
*/

#pragma once

#include "SoundPlayerComponent.hpp"

namespace polymorph::engine::audio
{
    class SoundPlayerImpl : public SoundPlayerComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SoundPlayerImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

            ~SoundPlayerImpl() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() final;

            void play() final;

            void stop() final;

            void pause() final;

            void resume() final;

            void setVolume(float volume) final;

            float getVolume() final;

            void changeAndPlay(Sound sound) final;

            void build() override;

            void saveAll() override;

        private:


//////////////////////--------------------------/////////////////////////

    };
}