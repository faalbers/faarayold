#ifndef FAARAY_GLOBAL_H
#define FAARAY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FAARAY_LIBRARY)
#  define FAARAYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define FAARAYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FAARAY_GLOBAL_H
