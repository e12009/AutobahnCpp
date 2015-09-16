#ifndef AUTOBAHN_WAMP_COMPONENT_HPP
#define AUTOBAHN_WAMP_COMPONENT_HPP

// http://stackoverflow.com/questions/22597948/using-boostfuture-with-then-continuations/
#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION
#define BOOST_THREAD_PROVIDES_FUTURE_WHEN_ALL_WHEN_ANY

#include "wamp_session.hpp"

#include <boost/asio/io_service.hpp>
#include <boost/thread/future.hpp>
#include <boost/noncopyable.hpp>
#include <memory>
#include <string>

namespace autobahn {

template <class Input, class Output>
class wamp_component : public boost::noncopyable
{
public:
    wamp_component(
            boost::asio::io_service& io_service,
            const std::string& realm,
            bool debug=false);
    virtual ~wamp_component();

    virtual boost::future<void> start() = 0;
    virtual boost::future<void> stop() = 0;

    boost::asio::io_service& io_service();
    const std::string& realm() const;
    bool is_debug() const;
    const std::shared_ptr<autobahn::wamp_session<Input, Output>>& session();

protected:
    void initialize(Input& input, Output& output);

private:
    boost::asio::io_service& m_io_service;
    const std::string m_realm;
    const bool m_debug;

    std::shared_ptr<autobahn::wamp_session<Input, Output>> m_session;
};

} // namespace autobahn

#include "wamp_component.ipp"

#endif // AUTOBAHN_WAMP_COMPONENT_HPP
