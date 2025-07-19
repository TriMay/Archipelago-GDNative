#include "gdapclient.h"

using namespace godot;

void GDAPClient::_register_methods() {
    register_method("hello_world", &GDAPClient::hello_world);
}

GDAPClient::GDAPClient() {
}

GDAPClient::~GDAPClient() {
    // add your cleanup here
}

void GDAPClient::_init() {
    // initialize any variables here
}

String GDAPClient::hello_world() {
    return "Hello World";
}