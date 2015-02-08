#ifndef __FAARAY_MATTEMATERIAL_H__
#define __FAARAY_MATTEMATERIAL_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "Material.h"
#include "GFA/GFA.h"
//==============================================================================
namespace FaaRay
{

class TraceThread;
class LambertianBRDF;

class FAARAY_DLL_PUBLIC MatteMaterial : public Material
{
    public:
        MatteMaterial();
        virtual ~MatteMaterial();

        void setCd(
            const GFA::Scalar &r,
            const GFA::Scalar &g,
            const GFA::Scalar &b) const;
        
        virtual const GFA::RGBColor & getDiffuseCd() const;
        virtual void shade(TraceThread &ttRef) const;
        virtual void diffuse(TraceThread &ttRef) const;
        
    private:
        LambertianBRDF *ambientBrdfPtr_;
        LambertianBRDF *diffuseBrdfPtr_;
};

typedef std::shared_ptr<MatteMaterial>  MatteMaterialSPtr;
typedef std::shared_ptr<const MatteMaterial>  ConstMatteMaterialSPtr;

}
//==============================================================================
#endif

