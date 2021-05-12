//
// Created by al_sah on 05.03.21.
//



#ifndef BASIC_MODULE_RESOURCES_H
#define BASIC_MODULE_RESOURCES_H

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/common/connection_hdl.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/thread.hpp>
#include <websocketpp/common/memory.hpp>

#include <string>
#include <memory>

typedef websocketpp::config::asio_client::message_type::ptr MessagePtr;

typedef websocketpp::client<websocketpp::config::asio_client> WSClient;
typedef websocketpp::lib::shared_ptr<websocketpp::lib::thread> Thread;
typedef websocketpp::close::status::value CloseStatusCode;
typedef websocketpp::lib::error_code ErrorCode;

#ifndef no_headers_includes
#define no_headers_includes
#endif

struct ConnectionMetainfo{

    /// Errors handling
    ErrorCode lastErrorCode;
    std::string lastErrorReason;

    websocketpp::connection_hdl hdl;

    std::string statusDetails;
    std::string status;

    std::string myID;
    std::string uri;

    CloseStatusCode  closeStatusCode;
};

struct WSRunnerProperties{


    std::string myID = "NEW";
    std::string uris[2] = {"ws://localhost:8080/bot", "ws://localhost:8888/bot"};

    uint32_t accessLoggingLevel = websocketpp::log::alevel::all;
    uint32_t errorsLoggingLevel = websocketpp::log::elevel::all;

    //uint32_t reconnectTime = 5;

};


namespace command {

    struct delimiters{
        char section = '#';
        char value = ':';
    };

    struct full_args_id {
        std::string response_type = "RESPONSE_TYPE";
        std::string package_type = "PACKAGE_TYPE";
        std::string recipient_id = "RECIPIENT_ID";
        std::string request_id = "REQUEST_ID";
        std::string module = "MODULE";
        std::string is_last = "LAST";
    };

    struct short_args_id {
        std::string response_type = "RT";
        std::string package_type = "PT";
        std::string target_id = "TID";
        std::string request_id = "RID";
        std::string module = "TM";
        std::string is_last = "L";
        std::string full_payload_size = "FS";
    };

}


struct CommandsManagerProperties{
    bool enable_args_id = true;
    command::delimiters delimiters;
    command::full_args_id full_args_id;
    command::short_args_id short_args_id;

};

struct ModulesManagerProperties{

};


enum payload_type{
    text = 1,
    file_hath = 2
};



#endif //BASIC_MODULE_RESOURCES_H