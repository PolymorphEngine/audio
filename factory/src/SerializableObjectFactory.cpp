/*
** EPITECH PROJECT, 2022
** SerializableObjectFactory.cpp
** File description:
** SerializableObjectFactory.cpp
*/

#include "SerializableObjectFactory.hpp"
#include "modules/MusicModuleImpl.hpp"
#include "modules/SoundModuleImpl.hpp"

polymorph::engine::api::SerializableObjectFactory::SerializableObjectFactory()
: ASerializableObjectFactory()
{
}

void polymorph::engine::api::SerializableObjectFactory::_registerEmptyBuildables(
        std::unordered_map<std::string, std::function<std::shared_ptr<ASerializableObject>(
                PluginManager&)>> &emptyBuildables)
{
    emptyBuildables.emplace("Music", makeEmpty<audio::MusicModuleImpl>());
    emptyBuildables.emplace("Sound", makeEmpty<audio::SoundModuleImpl>());
}

void polymorph::engine::api::SerializableObjectFactory::_registerCObjectBuildables(
        std::unordered_map <std::string, std::function<std::shared_ptr<ASerializableObject>(
                safe_ptr<AComponent>,
                std::shared_ptr<myxmlpp::Node>)>> &componentBuildables)
{
    componentBuildables.emplace("Music", makeCObject<audio::MusicModuleImpl>());
    componentBuildables.emplace("Sound", makeCObject<audio::SoundModuleImpl>());
}

void polymorph::engine::api::SerializableObjectFactory::_registerPObjectBuildables(
        std::unordered_map <std::string, std::function<std::shared_ptr<ASerializableObject>(
                safe_ptr<APluginConfig>,
                std::shared_ptr<myxmlpp::Node>)>> &configBuildables)
{
    configBuildables.emplace("Music", makePObject<audio::MusicModuleImpl>());
    configBuildables.emplace("Sound", makePObject<audio::SoundModuleImpl>());
}
