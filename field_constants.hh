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

//Midas EventID for each equipment
#define EVENTID_FIXED_PROBES 0x0001
#define EVENTID_TROLLEY 0x0002
#define EVENTID_GALIL_FERMI 0x0004
#define EVENTID_ABS_PROBE 0x0008
#define EVENTID_SURFACE_COIL 0x0010
#define EVENTID_FLUXGATE 0x0020
#define EVENTID_GALIL_PLATFORM 0x4000

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

//Absolute probe literals
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

// Absolute calibration constants 
constexpr int kAbsNmrNumFixedProbes = ABS_NMR_NUM_FIXED_PROBES;
constexpr double kAbsNmrKhzToPpm = ABS_NMR_KHZ_TO_PPM;

//Surface coil constants
constexpr int kNumSCoils = SC_NUM_COILS;

} // ::g2field

#endif
