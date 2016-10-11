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
constexpr double r_magic = 7112.0;
constexpr double d_gap = 180.0;

// NMR constants
constexpr double nmr_khz_to_ppm = 61790.0 * 1.0e-6;
constexpr double nmr_sample_period = 0.0001;
constexpr double nmr_fid_length_online = 100000;
constexpr double nmr_fid_length_record = 10000;

// Trolley constants
constexpr int trolley_nprobes = 17;
constexpr double trolley_rad = 3.5;

} // ::g2field

#endif
