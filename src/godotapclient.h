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
#include "JSON.hpp"
#include "JSONParseResult.hpp"


#include "apclient.hpp"
// include "apuuid.hpp" TODO FIXME for some reason this compile errors



namespace godot {

    class GodotAPClient : public Object {
        GODOT_CLASS(GodotAPClient, Object)

    public:
        static void _register_methods();

        GodotAPClient();
        ~GodotAPClient();

        void _init();

        void connect_to_host(String game, String url);

        void poll();

        void connect_slot(const String& name, const String& password, int items_handling, PoolStringArray tags);

        void send_say(const String& text);

        void send_location_checks(Array locations_array);

        //void connect_update();


    private:
        std::unique_ptr<APClient> ap;
    };

}




#endif