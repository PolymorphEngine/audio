/*
** audio, 2022
** SoundModule.hpp by 0xMemoryGrinder
*/

#pragma once

#include "polymorph/engine/api/scripting/AConfigurableSerializableObject.hpp"
#include "polymorph/engine/render-modules.hpp"

namespace polymorph::engine::audio
{
    class SoundModule;
    using Sound = std::shared_ptr<SoundModule>;
    class SoundModule: public api::AConfigurableSerializableObject
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SoundModule(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            SoundModule(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            explicit SoundModule(api::PluginManager &pluginManager);

            ~SoundModule() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            polymorph::audio::Symbols::createSoundDEF _c_sound = nullptr;

            std::string _filePath;
            std::unique_ptr<polymorph::audio::ISound> _sound;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void play() = 0;

            virtual void pause() = 0;

            virtual void resume() = 0;

            virtual void stop() = 0;

            virtual void setVolume(float volume) = 0;


            virtual std::string getFilePath() const = 0;

            virtual bool isSoundPlaying() const = 0;

            virtual void playMulti() = 0;

        private:


//////////////////////--------------------------/////////////////////////

    };
}