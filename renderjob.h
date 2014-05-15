//==============================================================================
#ifndef FAARAY_RENDERJOB_H
#define FAARAY_RENDERJOB_H
//==============================================================================
#include "faaray_global.h"
#include <memory>
//==============================================================================
namespace FaaRay {
class FAARAYSHARED_EXPORT RenderJob
{
public:
    RenderJob();

private:
    //std::shared_ptr<ViewPlane>  viewPlaneSPtr_;
    //std::shared_ptr<Scene>      sceneSPtr_;
    bool                        multiThread_;
};
}

#endif // FAARAY_RENDERJOB_H
