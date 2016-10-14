#ifndef G2_FIELD_CORE_INCLUDE_FIELD_CONSTANTS_HH_
#define G2_FIELD_CORE_INCLUDE_FIELD_CONSTANTS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   field_constants.hh

about:  A header file for constant parameters used across field team
        software.

\*===========================================================================*/


//--- std includes  ---------------------------------------------------------//

namespace g2field {

// General constants
constexpr double MAGIC_RADIUS = 7112.0;
constexpr double POLE_GAP_Z = 180.0;

// NMR constants
constexpr int NMR_NUM_FIXED_PROBES = 378;
constexpr int NMR_FID_LENGTH_ONLINE = 100000;
constexpr int NMR_FID_LENGTH_RECORD = 10000;
constexpr double NMR_KHZ_TO_PPM = 61790.0 * 1.0e-6;
constexpr double NMR_SAMPLE_PERIOD = 0.0001;

// Trolley constants
constexpr int TROLLEY_PROBES = 17;
constexpr double TROLLEY_RADIUS = 3.5;

} // ::g2field

#endif
