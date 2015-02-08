#ifndef __FAARAY_RENDERJOB_H__
#define __FAARAY_RENDERJOB_H__
//==============================================================================
#include <memory>
#include "FaaRay/FaaRay.h"
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"
//==============================================================================
namespace FaaRay
{

class Scene;
class ViewPlane;
class TraceThread;

class FAARAY_DLL_PUBLIC RenderJob
{
public:
    RenderJob();
    ~RenderJob();

    std::shared_ptr<Scene>      getSceneSPtr() const;
    std::shared_ptr<ViewPlane>  getViewPlaneSPtr() const;

    void setViewPlaneSPtr(std::shared_ptr<ViewPlane> viewPlaneSPtr);

    void setMultiThread();
    
    void render() const;

    void operator() (const tbb::blocked_range<std::size_t> &r) const;

private:
    std::shared_ptr<ViewPlane>  viewPlaneSPtr_;
    std::shared_ptr<Scene>      sceneSPtr_;
    bool                        multiThread_;
    

    
    void renderOneThread_() const;
    void renderMultiThread_() const;
    void setupTraceThread_(TraceThread &rt) const;
};
}
//==============================================================================
#endif

