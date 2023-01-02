/*
** audio, 2022
** MusicPlayerImpl.hpp by 0xMemoryGrinder
*/

#pragma once

#include "MusicPlayerComponent.hpp"

namespace polymorph::engine::audio
{

    class MusicPlayerImpl : public MusicPlayerComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MusicPlayerImpl(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

            ~MusicPlayerImpl() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() override;

            void start() override;

            void play() override;

            void stop() override;

            void pause() override;

            void resume() override;

            void setVolume(float volume) override;

            float getVolume() override;

            void setPitch(float pitch) override;

            float getPitch() override;

            void setLoop(bool loop) override;

            void build() override;

            void saveAll() override;

        private:


//////////////////////--------------------------/////////////////////////

    };
}