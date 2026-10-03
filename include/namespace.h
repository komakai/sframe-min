#pragma once

// Configurable top-level namespace. Upstream's CMake generates this file from
// cmake/namespace.h.in; webrtc-min uses the fixed "sframe" namespace, as
// Chromium's third_party/sframe/namespace.h does.
#define SFRAME_NAMESPACE sframe
