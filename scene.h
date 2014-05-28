#ifndef FAARAY_SCENE_H
#define FAARAY_SCENE_H
//==============================================================================
#include "faaray_global.h"
#include <memory>
//==============================================================================
namespace FaaRay {
class FAARAYSHARED_EXPORT Scene
{
public:
    Scene();
};
typedef std::shared_ptr<Scene> SceneSPtr;
typedef std::shared_ptr<const Scene> ConstSceneSPtr;
}
//==============================================================================
#endif // FAARAY_SCENE_H
