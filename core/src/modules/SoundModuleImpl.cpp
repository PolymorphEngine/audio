/*
** audio, 2022
** SoundModuleImpl.cpp by 0xMemoryGrinder
*/


#include <utility>
#include "modules/SoundModuleImpl.hpp"

polymorph::engine::audio::SoundModule::SoundModule(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node)
        : AConfigurableSerializableObject(component, std::move(node))
{

}

polymorph::engine::audio::SoundModule::SoundModule(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node)
        : AConfigurableSerializableObject(config, std::move(node))
{

}

polymorph::engine::audio::SoundModule::SoundModule(api::PluginManager &pluginManager)
        : AConfigurableSerializableObject(pluginManager)
{

}

polymorph::engine::audio::SoundModuleImpl::SoundModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::AComponent> component,
        std::shared_ptr<myxmlpp::Node> node)
    : SoundModule(component, node)
{
    build();
    _loadModule();
}

polymorph::engine::audio::SoundModuleImpl::SoundModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::api::APluginConfig> config,
        std::shared_ptr<myxmlpp::Node> node)
    : SoundModule(config, node)
{
    build();
    _loadModule();
}

polymorph::engine::audio::SoundModuleImpl::SoundModuleImpl(
        polymorph::engine::api::PluginManager &pluginManager)
    : SoundModule(pluginManager)
{
    build();
    _loadModule();
}

void polymorph::engine::audio::SoundModuleImpl::play()
{
    _sound->play();
}

void polymorph::engine::audio::SoundModuleImpl::pause()
{
    _sound->pause();
}

void polymorph::engine::audio::SoundModuleImpl::resume()
{
    _sound->resume();
}

void polymorph::engine::audio::SoundModuleImpl::stop()
{
    _sound->stop();
}

void polymorph::engine::audio::SoundModuleImpl::setVolume(float volume)
{
    _sound->setVolume(volume);
}

std::string polymorph::engine::audio::SoundModuleImpl::getFilePath() const
{
    return _filePath;
}

bool polymorph::engine::audio::SoundModuleImpl::isSoundPlaying() const
{
    return _sound->isSoundPlaying();
}

void polymorph::engine::audio::SoundModuleImpl::playMulti()
{
    _sound->playMulti();
}

void polymorph::engine::audio::SoundModuleImpl::_loadModule()
{
    _c_sound = _plugin.getSymbol<polymorph::audio::Symbols::createSoundDEF>(polymorph::audio::Symbols::createSound);
    _sound = std::unique_ptr<polymorph::audio::ISound>(_c_sound(_filePath));
}

void polymorph::engine::audio::SoundModuleImpl::build()
{
    _setProperty("filePath", _filePath);
}

void polymorph::engine::audio::SoundModuleImpl::saveAll()
{
    saveProperty("filePath", _filePath);
}
