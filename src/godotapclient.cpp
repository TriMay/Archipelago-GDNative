#include "godotapclient.h"

using namespace godot;

void GodotAPClient::_register_methods() {
    register_method("connect_to_host", &GodotAPClient::connect_to_host);
    register_method("poll", &GodotAPClient::poll);
}

GodotAPClient::GodotAPClient() { }

GodotAPClient::~GodotAPClient() { }

void GodotAPClient::connect_to_host(String game, String url) {
    std::string uuid = "e321d079-0848-4f83-8694-dc5d9bf2f764"; // TODO
    // Look i know
    // I'll figure this out later

    ap.reset(new APClient(uuid, "YOMI Hustle"));
}

void GodotAPClient::poll() {
    if (ap) ap->poll();
}

