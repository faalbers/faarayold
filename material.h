#ifndef FAARAY_MATERIAL_H
#define FAARAY_MATERIAL_H
//==============================================================================
#include <memory>
//==============================================================================
namespace FaaRay {

class Material
{
public:
    Material();
};
typedef std::shared_ptr<Material>  MaterialSPtr;
typedef std::shared_ptr<const Material>  ConstMaterialSPtr;
}
#endif // FAARAY_MATERIAL_H
