/*
** audio, 2022
** MusicPlayerImpl.cpp by 0xMemoryGrinder
*/


#include "polymorph/engine/core/component/AComponent_templated.hpp"
#include "MusicPlayerImpl.hpp"

polymorph::engine::audio::MusicPlayerComponent::MusicPlayerComponent(GameObject gameObject, std::shared_ptr<myxmlpp::Node> node)
    : AComponent(node, gameObject)
{

}

polymorph::engine::audio::MusicPlayerImpl::MusicPlayerImpl(
        polymorph::engine::GameObject gameObject,
        std::shared_ptr<myxmlpp::Node> node)
    : MusicPlayerComponent(gameObject, node)
{

}

void polymorph::engine::audio::MusicPlayerImpl::update()
{
    setLoop(looping);
    music->update();
}

void polymorph::engine::audio::MusicPlayerImpl::start()
{
    setVolume(volume);
    setLoop(looping);
    if (autoStart)
        play();
}

void polymorph::engine::audio::MusicPlayerImpl::play()
{
    music->play();
}

void polymorph::engine::audio::MusicPlayerImpl::stop()
{
    music->stop();
}

void polymorph::engine::audio::MusicPlayerImpl::pause()
{
    music->pause();
}

void polymorph::engine::audio::MusicPlayerImpl::resume()
{
    music->resume();
}

void polymorph::engine::audio::MusicPlayerImpl::setVolume(float volume)
{
    volume = volume;
    music->setVolume(volume);
}

float polymorph::engine::audio::MusicPlayerImpl::getVolume()
{
    return volume;
}

void polymorph::engine::audio::MusicPlayerImpl::setPitch(float pitch)
{
    music->setPitch(pitch);
}

float polymorph::engine::audio::MusicPlayerImpl::getPitch()
{
    return music->getPitch();
}

void polymorph::engine::audio::MusicPlayerImpl::setLoop(bool loop)
{
    looping = loop;
    music->setLoop(loop);
}

void polymorph::engine::audio::MusicPlayerImpl::build()
{
    _setProperty("volume", volume);
    _setProperty("looping", looping);
    _setProperty("autoStart", autoStart);
    _setProperty("music", music);
}

void polymorph::engine::audio::MusicPlayerImpl::saveAll()
{
    saveProperty("volume", volume);
    saveProperty("looping", looping);
    saveProperty("autoStart", autoStart);
    saveProperty("music", music);
}
