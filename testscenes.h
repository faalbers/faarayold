#ifndef FAARAY_TESTSCENES_H
#define FAARAY_TESTSCENES_H
//==============================================================================
#include "faaray_global.h"
#include "scene.h"
//==============================================================================
namespace FaaRay {

class FAARAYSHARED_EXPORT TestScenes
{
public:
    TestScenes(std::shared_ptr<Scene> sceneSPtr);

    void addSetA() const;
    void addSetB() const;
    void addSetC() const;

private:
    std::shared_ptr<Scene> sceneSPtr_;
};
}
#endif // FAARAY_TESTSCENES_H
