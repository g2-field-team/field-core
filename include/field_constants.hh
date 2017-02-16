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

// Fixed Probe literals
#define FIXED_NMR_NUM_PROBES 378
#define FIXED_NMR_FULL_FID_LENGTH 100000
#define FIXED_NMR_SAVE_FID_LENGTH 10000
#define FIXED_NMR_KHZ_TO_PPM 61790.0 * 1.0e-6
#define FIXED_NMR_SAMPLE_PERIOD_MS 0.0001

// Trolley literals
#define TRLY_NMR_LENGTH 24000
#define TRLY_BARCODE_LENGTH 3000 //ALL CHANNELS
#define TRLY_BARCODE_CHANNELS 6
#define TRLY_MONITOR_LENGTH 3000

// Absolute probe literals
#define ABS_NMR_LENGTH 8000010
#define ABS_NMR_NUM_FIXED_PROBES 8
#define ABS_NMR_KHZ_TO_PPM 61679.0 * 1.0e-6

// Surface coil literals
#define SC_NUM_COILS 100

// Galil literal
#define GALILREADGROUPSIZE 50

namespace g2field {

// General constants
constexpr double kMagicRadius = 7112.0;

// Fixed Prob constants
constexpr int kFixedNmrNumFixedProbes = FIXED_NMR_NUM_PROBES;
constexpr int kFixedNmrFullFidLength = FIXED_NMR_FULL_FID_LENGTH;
constexpr int kFixedNmrSaveFidLength = FIXED_NMR_SAVE_FID_LENGTH;
constexpr double kFixedNmrKhzToPpm = FIXED_NMR_KHZ_TO_PPM;
constexpr double kFixedNmrSamplePeriodMs = FIXED_NMR_SAMPLE_PERIOD_MS;

// Trolley constants
constexpr int kNumTrolleyProbes = 17;
constexpr double kTrolleyRadius = 3.5;

// Absolute calibration constants 
constexpr int kAbsNmrNumFixedProbes = ABS_NMR_NUM_FIXED_PROBES;
constexpr double kAbsNmrKhzToPpm = ABS_NMR_KHZ_TO_PPM;

//Surface coil constants
constexpr int kNumSCoils = SC_NUM_COILS;

} // ::g2field

#endif
