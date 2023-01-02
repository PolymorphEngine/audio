/*
** EPITECH PROJECT, 2022
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "MusicPlayerImpl.hpp"
#include "SoundPlayerImpl.hpp"

polymorph::engine::api::ComponentFactory::ComponentFactory() : AComponentFactory()
{
}

void polymorph::engine::api::ComponentFactory::_registerBuildables(
        std::unordered_map<std::string, polymorph::engine::api::AComponentFactory::FactoryLambda> &buildables)
{
    buildables.emplace("MusicPlayer", make<audio::MusicPlayerImpl>());
    buildables.emplace("SoundPlayer", make<audio::SoundPlayerImpl>());
}