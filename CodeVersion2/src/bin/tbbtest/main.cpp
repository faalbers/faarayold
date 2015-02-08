//setenv LD_LIBRARY_PATH /dist/d2sets/fedora-11-x86_64/tools-base-02/lib
//export LD_LIBRARY_PATH="/home/frank/tbb41_20130116oss/lib/intel64/cc4.1.0_libc2.4_kernel2.6.16.21":${LD_LIBRARY_PATH}
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "tbb/task_scheduler_init.h"
#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"

using namespace std;
using namespace tbb;

void Foo(double &a)
{
    a = cos(rand());
}

void SerialApplyFoo( double a[], size_t n )
{
    for ( size_t i = 0; i < n; ++i )
        Foo(a[i]);
}

class ApplyFoo
{
public:
    ApplyFoo( double a[] );
    
    double *const my_a;
    
    void operator() ( const blocked_range<size_t> &r ) const;
};

ApplyFoo::ApplyFoo( double a[] )
    : my_a(a)
{
    cout << "Initialized ApplyFoo" << endl;
}

void ApplyFoo::operator() ( const blocked_range<size_t> &r ) const
{
    double *a = my_a;
    for ( size_t i = r.begin(); i != r.end(); ++i ) {
        Foo(a[i]);
    }
}

int main(int /*argv*/, char **/*args*/)
{
    cout << "I can use " << task_scheduler_init::default_num_threads() << " thread(s)" << endl;
    task_scheduler_init init;
    
    const char* test = "Holla";
    
    cout << test << endl;
    
    double *a = new double[1000000];
    
    cout << a[0] << endl;
    
    cout << "------" << endl;
    //SerialApplyFoo( a, 10 );
    parallel_for(blocked_range<size_t>(0, 1000), ApplyFoo( a ) );
    cout << "------" << endl;

    cout << a[0] << endl;
    
    delete[] a;

    return 0;
}
