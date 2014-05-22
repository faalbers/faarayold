#ifndef FAARAY_TRACETHREAD_H
#define FAARAY_TRACETHREAD_H
//==============================================================================
#include "faaray_global.h"
#include "faaray.h"
#include "gfa/gfa.h"
#include <iostream>
#include <random>
//==============================================================================
namespace FaaRay {
class FAARAYSHARED_EXPORT TraceThread
{
public:
    TraceThread();

    void        initRandom(const uint32_t &s);

    // viewplane data
    GFA::Size       width;
    GFA::Size       height;

private:
    uint32_t    seedValue_;
    MyRNG       rng_;
    std::uniform_real_distribution<GFA::Scalar> distribution;

};
}
#endif // FAARAY_TRACETHREAD_H
