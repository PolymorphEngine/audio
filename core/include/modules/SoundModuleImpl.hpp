/*
** audio, 2022
** SoundModuleImpl.hpp by 0xMemoryGrinder
*/

#pragma once


#include "SoundModule.hpp"

namespace polymorph::engine::audio
{
    class SoundModuleImpl : public SoundModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            SoundModuleImpl(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            SoundModuleImpl(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            explicit SoundModuleImpl(api::PluginManager &pluginManager);

            ~SoundModuleImpl() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void play() final;

            void pause() final;

            void resume() final;

            void stop() final;

            void setVolume(float volume) final;


            std::string getFilePath() const final;

            bool isSoundPlaying() const final;

            void playMulti() final;

            void build() final;

            void saveAll() final;


        private:
            void _loadModule();


//////////////////////--------------------------/////////////////////////

    };
}