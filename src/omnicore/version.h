#ifndef OMNICORE_VERSION_H
#define OMNICORE_VERSION_H

#if defined(HAVE_CONFIG_H)
#include "config/bitcoin-config.h"
#else

//
// Omni Core version information are also to be defined in configure.ac.
//
// During the configuration, this information are used for other places.
//

// Even greater than major versions
#define OMNICORE_VERSION_MILESTONE   0

// Increase with every consensus affecting change
#define OMNICORE_VERSION_MAJOR       0

// Increase with every non-consensus affecting feature
#define OMNICORE_VERSION_MINOR       11

// Increase with every patch, which is not a feature or consensus affecting
#define OMNICORE_VERSION_PATCH       1

// Non-public build number/revision (usually zero)
#define OMNICORE_VERSION_BUILD       0

// Use "dev" for development versions, switch to "rc" for release candidates
#define OMNICORE_VERSION_STATUS      rel


#endif // HAVE_CONFIG_H

#if !defined(WINDRES_PREPROC)

//
// *-res.rc includes this file, but it cannot cope with real c++ code.
// WINDRES_PREPROC is defined to indicate that its pre-processor is running.
// Anything other than a define should be guarded below:
//

#include <string>

//! Omni Core client version
static const int OMNICORE_VERSION =
                    +100000000000 * OMNICORE_VERSION_MILESTONE
                    +   100000000 * OMNICORE_VERSION_MAJOR
                    +      100000 * OMNICORE_VERSION_MINOR
                    +         100 * OMNICORE_VERSION_PATCH
                    +           1 * OMNICORE_VERSION_BUILD;

//! Returns formatted Omni Core version, e.g. "0.0.9.1-dev"
const std::string OmniCoreVersion();

//! Returns formatted Bitcoin Core version, e.g. "0.10", "0.9.3"
const std::string BitcoinCoreVersion();

//! Returns build date
const std::string BuildDate();

//! Returns commit identifier, if available
const std::string BuildCommit();


#endif // WINDRES_PREPROC

#endif // OMNICORE_VERSION_H
