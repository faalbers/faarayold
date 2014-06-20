#ifndef FAARAY_GLOBAL_H
#define FAARAY_GLOBAL_H

/*!
 * \mainpage FaaRay Ray Tracing Library
 * \author Frank Aalbers
 *
 * \section intro_sec Introduction
 *
 * This Library contains a Ray Tracing system created for sole purpouse of
 * learning to program in C++. It is by no means intended to become a next big
 * Ray Tracing system.
 * It is Still in progress.
 *
 */

#include <QtCore/qglobal.h>

#if defined(FAARAY_LIBRARY)
#  define FAARAYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define FAARAYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FAARAY_GLOBAL_H
