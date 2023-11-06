#include <phpcpp.h>

Php::Value sayHello() {
    return "Hello, World!\n";
}

extern "C" {
 PHPCPP_EXPORT void *get_module() {
        static Php::Extension extension("hello_world_extension", "1.0");
        
        extension.add("sayHello", sayHello);
        
        return extension;
    }
}

