#ifndef FAARAY_MATERIAL_H
#define FAARAY_MATERIAL_H
//==============================================================================
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

/*!
 * \brief The Material base class
 */
class Material
{
public:
    Material();

    virtual void shade(TraceThread &ttRef) const = 0;
    virtual void shadeLight(TraceThread &ttRef) const = 0;
};
typedef std::shared_ptr<Material>  MaterialSPtr;
typedef std::shared_ptr<const Material>  ConstMaterialSPtr;
}
#endif // FAARAY_MATERIAL_H
