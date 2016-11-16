#ifndef G2_FIELD_CORE_INCLUDE_FIELD_CONSTANTS_HH_
#define G2_FIELD_CORE_INCLUDE_FIELD_CONSTANTS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   field_constants.hh

about:  A header file for constant parameters used across field team
        software.

\*===========================================================================*/

#include "TROOT.h"

// NMR literals
#define NMR_NUM_FIXED_PROBES 378
#define NMR_FID_LENGTH_ONLINE 100000
#define NMR_FID_LENGTH_RECORD 10000
#define NMR_KHZ_TO_PPM 61790.0 * 1.0e-6
#define NMR_SAMPLE_PERIOD 0.0001

//Trolley literals
#define TRLY_NMR_LENGTH 24000
#define TRLY_BARCODE_LENGTH 3000 //ALL CHANNELS
#define TRLY_BARCODE_CHANNELS 6
#define TRLY_MONITOR_LENGTH 3000

//Fluxgate literals
#define FLUX_NUM_CHANNELS 9 //3 fluxgates, all three channels each
#define FLUX_TRACE_PERIOD 60 //seconds
#define FLUX_RATE 8000 //samples per sec
#define FLUX_BINNED_RATE 2000 //samples per sec

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
