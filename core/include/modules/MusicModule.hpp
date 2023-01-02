/*
** plugin-template, 2022
** MusicModule.hpp by 0xMemoryGrinder
*/

#pragma once

#include "polymorph/engine/api/scripting/AConfigurableSerializableObject.hpp"
#include "polymorph/engine/render-modules.hpp"

namespace polymorph::engine::audio
{
    class MusicModule;
    using Music = std::shared_ptr<MusicModule>;

    class MusicModule : public api::AConfigurableSerializableObject
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MusicModule(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            MusicModule(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            explicit MusicModule(api::PluginManager &pluginManager);

            ~MusicModule() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            polymorph::audio::Symbols::createMusicDEF _c_music = nullptr;

            float _pitch = 1;
            std::string _filePath;
            std::unique_ptr<polymorph::audio::IMusic> _music;


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void play() = 0;

            virtual void stop() = 0;

            virtual void pause() = 0;

            virtual void resume() = 0;

            virtual void update() = 0;

            virtual void setVolume(float volume) = 0;

            virtual void setPitch(float pitch) = 0;


            virtual float getPitch() const = 0;

            virtual void setLoop(bool loop) = 0;

            virtual std::string getFilePath() const = 0;

        private:


//////////////////////--------------------------/////////////////////////

    };


}