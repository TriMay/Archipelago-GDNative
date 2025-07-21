#ifndef GODOTAPCLIENT_H
#define GODOTAPCLIENT_H


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


#include "apclient.hpp"



namespace godot {

    class GodotAPClient : public Object {
        GODOT_CLASS(GodotAPClient, Object)

    public:
        static void _register_methods();

        GodotAPClient();
        ~GodotAPClient();

        void _init();

        String hello_world();

    private:
        std::unique_ptr<APClient> ap;
    };

}




#endif