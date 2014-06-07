#ifndef FAARAY_MATTEMATERIAL_H
#define FAARAY_MATTEMATERIAL_H
//==============================================================================
#include "material.h"
#include <memory>
#include "gfa/gfa.h"
//==============================================================================
namespace FaaRay {

class MatteMaterial : public Material
{
public:
    MatteMaterial();

    void setCd(
        const GFA::Scalar &r,
        const GFA::Scalar &g,
        const GFA::Scalar &b) const;
};
typedef std::shared_ptr<MatteMaterial>  MatteMaterialSPtr;
}
#endif // FAARAY_MATTEMATERIAL_H
