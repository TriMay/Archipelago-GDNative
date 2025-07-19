#ifndef GDAPCLIENT_H
#define GDAPCLIENT_H


#include <inttypes.h>

#include "map"


#include "Godot.hpp"
#include "Object.hpp"
#include "OS.hpp"
#include "Engine.hpp"
#include "Texture.hpp"
#include "String.hpp"
#include "Reference.hpp"
#include "Dictionary.hpp"
#include "IP.hpp"
#include "Variant.hpp"



namespace godot {

    class GDAPClient : public Object {
        GODOT_CLASS(GDAPClient, Object)

    public:
        static void _register_methods();

        GDAPClient();
        ~GDAPClient();

        void _init();

        String hello_world();
    };

}




#endif