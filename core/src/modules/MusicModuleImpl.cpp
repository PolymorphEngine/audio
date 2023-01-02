/*
** audio, 2022
** MusicModuleImpl.cpp by 0xMemoryGrinder
*/

#include "modules/MusicModuleImpl.hpp"

#include <utility>

polymorph::engine::audio::MusicModule::MusicModule(safe_ptr<AComponent> component,
                                                   std::shared_ptr<myxmlpp::Node> node)
    : AConfigurableSerializableObject(component, std::move(node))
{

}

polymorph::engine::audio::MusicModule::MusicModule(safe_ptr<api::APluginConfig> config,
                                                   std::shared_ptr<myxmlpp::Node> node)
    : AConfigurableSerializableObject(config, std::move(node))
{

}

polymorph::engine::audio::MusicModule::MusicModule(api::PluginManager &pluginManager)
    : AConfigurableSerializableObject(pluginManager)
{

}

polymorph::engine::audio::MusicModuleImpl::MusicModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::AComponent> component,
        std::shared_ptr<myxmlpp::Node> node)
        : MusicModule(component, std::move(node))
{
    build();
    _loadModule();
}

polymorph::engine::audio::MusicModuleImpl::MusicModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::api::APluginConfig> config,
        std::shared_ptr<myxmlpp::Node> node) : MusicModule(config, node)
{
    build();
    _loadModule();
}

polymorph::engine::audio::MusicModuleImpl::MusicModuleImpl(
        polymorph::engine::api::PluginManager &pluginManager)
        : MusicModule(pluginManager)
{
    build();
    _loadModule();
}

void polymorph::engine::audio::MusicModuleImpl::play()
{
    _music->play();
}

void polymorph::engine::audio::MusicModuleImpl::stop()
{
    _music->stop();
}

void polymorph::engine::audio::MusicModuleImpl::pause()
{
    _music->pause();
}

void polymorph::engine::audio::MusicModuleImpl::resume()
{
    _music->resume();
}

void polymorph::engine::audio::MusicModuleImpl::update()
{
    _music->update();
}

void polymorph::engine::audio::MusicModuleImpl::setVolume(float volume)
{
    _music->setVolume(volume);
}

void polymorph::engine::audio::MusicModuleImpl::setPitch(float pitch)
{
    _pitch = pitch;
    _music->setPitch(pitch);
}

float polymorph::engine::audio::MusicModuleImpl::getPitch() const
{
    return _pitch;
}

void polymorph::engine::audio::MusicModuleImpl::setLoop(bool loop)
{
    _music->setLoop(loop);
}

std::string polymorph::engine::audio::MusicModuleImpl::getFilePath() const
{
    return _filePath;
}

void polymorph::engine::audio::MusicModuleImpl::build()
{
    _setProperty("_filePath", _filePath);
    _setProperty("_pitch", _pitch);
}

void polymorph::engine::audio::MusicModuleImpl::saveAll()
{
    saveProperty("_filePath", _filePath);
    saveProperty("_pitch", _pitch);
}

void polymorph::engine::audio::MusicModuleImpl::_loadModule()
{
    _c_music = _plugin.getSymbol<polymorph::audio::Symbols::createMusicDEF>(polymorph::audio::Symbols::createMusic);
    _music = std::unique_ptr<polymorph::audio::IMusic>(_c_music(_filePath));
}
