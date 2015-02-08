#ifndef __FAARAY_AMBIENTLIGHT_H__
#define __FAARAY_AMBIENTLIGHT_H__
//==============================================================================
#include "Light.h"
#include <memory>
#include "FaaRay/FaaRay.h"
#include "GFA/GFA.h"
#include "GFA/RGBColor.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;

class FAARAY_DLL_PUBLIC AmbientLight : public Light
{
public:
    AmbientLight();
    virtual ~AmbientLight();

    virtual void getDirection(TraceThread &ttRef) const;
    virtual void L(TraceThread &ttRef) const;
    virtual void inShadow(TraceThread &ttRef) const;    
    
    void setLs(const GFA::Scalar &ls);

private:
    GFA::Scalar     ls_;     // light strength
    GFA::RGBColor   color_;  // light color
};

typedef std::shared_ptr<AmbientLight>  AmbientLightSPtr;
AmbientLightSPtr FAARAY_DLL_PUBLIC MakeAmbientLightSPtr();

}
//==============================================================================
#endif

