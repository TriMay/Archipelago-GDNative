#include "godotapclient.h"

using namespace godot;

void GodotAPClient::_register_methods() {
    register_method("hello_world", &GodotAPClient::hello_world);
}

GodotAPClient::GodotAPClient() {
}

GodotAPClient::~GodotAPClient() {
    // add your cleanup here
}

void GodotAPClient::_init() {
    // initialize any variables here
}

String GodotAPClient::hello_world() {
    return "Hello World";
}