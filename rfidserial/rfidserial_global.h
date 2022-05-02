#ifndef RFIDSERIAL_GLOBAL_H
#define RFIDSERIAL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RFIDSERIAL_LIBRARY)
#  define RFIDSERIAL_EXPORT Q_DECL_EXPORT
#else
#  define RFIDSERIAL_EXPORT Q_DECL_IMPORT
#endif

#endif // RFIDSERIAL_GLOBAL_H
