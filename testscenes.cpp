#include "testscenes.h"

FaaRay::TestScenes::TestScenes(std::shared_ptr<Scene> sceneSPtr)
{
    sceneSPtr_.reset();
    sceneSPtr_ = sceneSPtr;
}
