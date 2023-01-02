/*
** audio, 2022
** SoundPlayerImpl.cpp by 0xMemoryGrinder
*/

#include "polymorph/engine/core/component/AComponent_templated.hpp"
#include "SoundPlayerImpl.hpp"

polymorph::engine::audio::SoundPlayerComponent::SoundPlayerComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
    : AComponent(node, gameObject)
{

}

polymorph::engine::audio::SoundPlayerImpl::SoundPlayerImpl(
        polymorph::engine::GameObject gameObject,
        std::shared_ptr<myxmlpp::Node> node)
    : SoundPlayerComponent(gameObject, node)
{

}

void polymorph::engine::audio::SoundPlayerImpl::update()
{
    sound->setVolume(volume);
}

void polymorph::engine::audio::SoundPlayerImpl::play()
{
    sound->play();
}

void polymorph::engine::audio::SoundPlayerImpl::stop()
{
    sound->stop();
}

void polymorph::engine::audio::SoundPlayerImpl::pause()
{
    sound->pause();
}

void polymorph::engine::audio::SoundPlayerImpl::resume()
{
    sound->resume();
}

void polymorph::engine::audio::SoundPlayerImpl::setVolume(float volume)
{
    volume = volume;
    sound->setVolume(volume);
}

float polymorph::engine::audio::SoundPlayerImpl::getVolume()
{
    return volume;
}

void polymorph::engine::audio::SoundPlayerImpl::changeAndPlay(Sound sound)
{
    this->sound = sound;
    this->sound->play();
}

void polymorph::engine::audio::SoundPlayerImpl::build()
{
    _setProperty("volume", volume);
    _setProperty("sound", sound);
}

void polymorph::engine::audio::SoundPlayerImpl::saveAll()
{
    saveProperty("volume", volume);
    saveProperty("sound", sound);
}
