#ifndef G2_FIELD_CORE_INCLUDE_FIELD_CONSTANTS_HH_
#define G2_FIELD_CORE_INCLUDE_FIELD_CONSTANTS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   field_constants.hh

about:  A header file for constant parameters used across field team
        software.

\*===========================================================================*/


// NMR literals
#define NMR_NUM_FIXED_PROBES 378
#define NMR_FID_LENGTH_ONLINE 100000
#define NMR_FID_LENGTH_RECORD 10000
#define NMR_KHZ_TO_PPM 61790.0 * 1.0e-6
#define NMR_SAMPLE_PERIOD 0.0001

namespace g2field {

// General constants
constexpr double kMagicRadius = 7112.0;
constexpr double kPoleGapZ = 180.0;

// NMR constants
constexpr int kNmrNumFixedProbes = NMR_NUM_FIXED_PROBES;
constexpr int kNmrFidLengthOnline = NMR_FID_LENGTH_ONLINE;
constexpr int kNmrFidLengthRecord = NMR_FID_LENGTH_RECORD;
constexpr double kNmrKhzToPpm = NMR_KHZ_TO_PPM;
constexpr double kNmrSamplePeriod = NMR_SAMPLE_PERIOD;

// Trolley constants
constexpr int kNumTrolleyProbes = 17;
constexpr double kTrolleyRadius = 3.5;

} // ::g2field

#endif
