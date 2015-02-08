#ifndef __FAARAY_MATERIAL_H__
#define __FAARAY_MATERIAL_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "GFA/RGBColor.h"
//==============================================================================
namespace FaaRay
{
    
class TraceThread;

class FAARAY_DLL_PUBLIC Material
{
    public:
        Material();
        virtual ~Material();

        virtual const GFA::RGBColor & getDiffuseCd() const { return color_; }
        virtual void shade(TraceThread &ttRef) const = 0;
        virtual void diffuse(TraceThread &ttRef) const = 0;

        void setColor() { color_.r = 0.0;}
    
    protected:
        GFA::RGBColor color_;
};

typedef std::shared_ptr<Material>  MaterialSPtr;
typedef std::shared_ptr<const Material>  ConstMaterialSPtr;

}
//==============================================================================
#endif

