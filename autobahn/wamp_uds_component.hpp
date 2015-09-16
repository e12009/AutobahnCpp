#ifndef AUTOBAHN_WAMP_UDS_COMPONENT_HPP
#define AUTOBAHN_WAMP_UDS_COMPONENT_HPP

#include "wamp_network_component.hpp"

#include <boost/asio/io_service.hpp>
#include <boost/asio/local/stream_protocol.hpp>
#include <memory>
#include <string>

namespace autobahn {

using wamp_uds_component =
        wamp_network_component<
                boost::asio::local::stream_protocol::socket,
                boost::asio::local::stream_protocol::endpoint>;

} // namespace autobahn

#endif // AUTOBAHN_WAMP_UDS_COMPONENT_HPP
