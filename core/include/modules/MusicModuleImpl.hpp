/*
** plugin-template, 2022
** MusicModule.hpp by 0xMemoryGrinder
*/

#pragma once

#include "polymorph/engine/api/scripting/ASerializableObject.hpp"
#include "polymorph/engine/render-modules.hpp"
#include "MusicModule.hpp"

namespace polymorph::engine::audio
{
    class MusicModuleImpl : public MusicModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            MusicModuleImpl(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            MusicModuleImpl(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            explicit MusicModuleImpl(api::PluginManager &pluginManager);

            ~MusicModuleImpl() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:



        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void play() final;

            void stop() final;

            void pause() final;

            void resume() final;

            void update() final;

            void setVolume(float volume) final;

            void setPitch(float pitch) final;


            float getPitch() const final;

            void setLoop(bool loop) final;

            std::string getFilePath() const final;

            void build() override;

            void saveAll() override;

        private:
            void _loadModule();


//////////////////////--------------------------/////////////////////////

    };
}