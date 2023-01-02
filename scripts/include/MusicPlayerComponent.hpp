/*
** audio, 2022
** MusicPlayerComponent.hpp by 0xMemoryGrinder
*/

#pragma once

#include "polymorph/engine/core/component/AComponent.hpp"
#include "../core/include/modules/MusicModule.hpp"

namespace polymorph::engine::audio
{
    class MusicPlayerComponent;
    using MusicPlayer = safe_ptr<MusicPlayerComponent>;

    class MusicPlayerComponent : public AComponent
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MusicPlayerComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node);

            ~MusicPlayerComponent() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Music music;
            bool looping = false;
            bool autoStart = false;
            float volume;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void play()= 0;

            virtual void stop()= 0;

            virtual void pause()= 0;

            virtual void resume()= 0;

            virtual void setVolume(float volume)= 0;

            virtual float getVolume()= 0;

            virtual void setPitch(float pitch)= 0;

            virtual float getPitch()= 0;

            virtual void setLoop(bool loop)= 0;

        private:


//////////////////////--------------------------/////////////////////////

    };


}