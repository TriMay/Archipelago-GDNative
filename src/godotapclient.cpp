#include "godotapclient.h"

using namespace godot;

void GodotAPClient::_register_methods() {
    register_method("connect_to_host", &GodotAPClient::connect_to_host);
    register_method("poll", &GodotAPClient::poll);
    register_method("connect_slot", &GodotAPClient::connect_slot);
}

GodotAPClient::GodotAPClient() {
}

GodotAPClient::~GodotAPClient() {
    // add your cleanup here
}

void GodotAPClient::_init() {
    // initialize any variables here
}

void GodotAPClient::connect_to_host(String game, String uri) {
    std::string uuid = "e321d079-0848-4f83-8694-dc5d9bf2f764"; // TODO

    ap.reset(new APClient(uuid, game.utf8().get_data(), uri.utf8().get_data()));

    ap->set_socket_connected_handler([this]() {
        on_socket_connected();
    });
    ap->set_socket_disconnected_handler([this]() {
        on_socket_disconnected();
    });
    ap->set_socket_error_handler([this](const std::string& error) {
        on_socket_error(error);
    });
}

void GodotAPClient::poll() {
    if (ap) ap->poll();
}


void GodotAPClient::connect_slot(const String& name, const String& password, int items_handling) {
    if (ap) {
        //std::list<std::string> tags_list;
        //
        //for (int i = 0; i < tags.size(); ++i) {
        //    godot::String gd_string = tags[i];
        //
        //    std::string cpp_string = gd_string.utf8().get_data();
        //
        //    tags_list.push_back(cpp_string);
        //}

        ap->ConnectSlot(name.utf8().get_data(), password.utf8().get_data(), items_handling);
    }
}



void GodotAPClient::on_socket_connected() {
    Godot::print("Socket Connected");
}

void GodotAPClient::on_socket_disconnected() {
    Godot::print("Socket Connected");
}

void GodotAPClient::on_socket_error(const std::string& error) {
    Godot::print("Socket Error");
    Godot::print(error.data());
}