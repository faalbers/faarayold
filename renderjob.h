//==============================================================================
#ifndef FAARAY_RENDERJOB_H
#define FAARAY_RENDERJOB_H
//==============================================================================
#include "faaray_global.h"
#include "viewplane.h"
#include "scene.h"
#include <memory>
//==============================================================================
namespace FaaRay {

class TraceThread;

class FAARAYSHARED_EXPORT RenderJob
{
public:
    RenderJob();

    void setViewPlaneSPtr(std::shared_ptr<ViewPlane> viewPlaneSPtr);
    void setMultiThread();
    void render() const;

private:
    std::shared_ptr<ViewPlane>  viewPlaneSPtr_;
    std::shared_ptr<Scene>      sceneSPtr_;
    bool                        multiThread_;

    void renderOneThread_() const;
    void renderMultiThread_() const;
    void setupTraceThread_(TraceThread &rt) const;
};
}

#endif // FAARAY_RENDERJOB_H
