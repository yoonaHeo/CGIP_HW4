#ifndef __LIGHT__
#define __LIGHT__

#include <glm/glm.hpp>

using namespace glm;

class Point_light {
public:
    vec3 position = vec3(-4, 4, -3);
    float intensity = 1.0f;
    vec3 color = vec3(1, 1, 1);
};

class Ambient_light {
public:
    float ia = 0.2f;
    vec3 color = vec3(1, 1, 1);
};

#endif // __LIGHT__