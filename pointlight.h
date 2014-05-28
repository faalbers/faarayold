#ifndef POINTLIGHT_H
#define POINTLIGHT_H
//==============================================================================
#include "faaray_global.h"
#include "light.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class PointLight : public Light
{
public:
    PointLight();
};
typedef std::shared_ptr<PointLight>  PointLightSPtr;
}
#endif // POINTLIGHT_H
