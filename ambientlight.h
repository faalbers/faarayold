#ifndef FAARAY_AMBIENTLIGHT_H
#define FAARAY_AMBIENTLIGHT_H
//==============================================================================
#include "faaray_global.h"
#include "light.h"
#include "gfa/gfa.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class FAARAYSHARED_EXPORT AmbientLight : public Light
{
public:
    AmbientLight();

    virtual void L(TraceThread &ttRef) const;

};
typedef std::shared_ptr<AmbientLight>  AmbientLightSPtr;
AmbientLightSPtr FAARAYSHARED_EXPORT MakeAmbientLightSPtr();
}
#endif // FAARAY_AMBIENTLIGHT_H
