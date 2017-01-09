#ifndef G2_FIELD_CORE_INCLUDE_FIELD_STRUCTS_HH_
#define G2_FIELD_CORE_INCLUDE_FIELD_STRUCTS_HH_

/*===========================================================================*\

author: Matthias W. Smith
email:  mwsmith2@uw.edu
file:   field_constants.hh

about:  A header file for constant parameters used across field team
        software.

\*===========================================================================*/

//--- project includes  -----------------------------------------------------//
#include <vector>

//--- project includes  -----------------------------------------------------//
#include "field_constants.hh"

namespace g2field {

// A macro to define nmr structs since they are very similar.
#define MAKE_NMR_STRUCT(name, num_ch, len_tr)\
struct name {\
  Double_t sys_clock[num_ch];\
  Double_t gps_clock[num_ch];\
  Double_t dev_clock[num_ch];\
  Double_t snr[num_ch];\
  Double_t len[num_ch];\
  Double_t freq[num_ch];\
  Double_t ferr[num_ch];\
  Double_t freq_zc[num_ch];\
  Double_t ferr_zc[num_ch];\
  UShort_t health[num_ch];\
  UShort_t method[num_ch];\
  UShort_t trace[num_ch][len_tr];\
};

// Might as well define a root branch string for the struct.
#define MAKE_NMR_STRING(name, num_ch, len_tr) NMR_HELPER(name, num_ch, len_tr)

#define NMR_HELPER(name, num_ch, len_tr) \
const char * const name = "sys_clock["#num_ch"]/D:gps_clock["#num_ch"]/D:"\
"dev_clock["#num_ch"]/D:snr["#num_ch"]/D:len["#num_ch"]/D:freq["#num_ch"]/D:"\
"ferr["#num_ch"]/D:freq_zc["#num_ch"]/D:ferr_zc["#num_ch"]/D:"\
"health["#num_ch"]/s:method["#num_ch"]/s:trace["#num_ch"]["#len_tr"]/s"

// NMR structs
MAKE_NMR_STRUCT(fixed_t, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_RECORD);
MAKE_NMR_STRING(fixed_str, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_RECORD);

MAKE_NMR_STRUCT(online_fixed_t, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_ONLINE);
MAKE_NMR_STRING(online_fixed_str, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_ONLINE);

// Flexible struct built from the basic nmr attributes.
struct nmr_vector {
  std::vector<Double_t> sys_clock;
  std::vector<Double_t> gps_clock;
  std::vector<Double_t> dev_clock;
  std::vector<Double_t> snr;
  std::vector<Double_t> len;
  std::vector<Double_t> freq;
  std::vector<Double_t> ferr;
  std::vector<Double_t> freq_zc;
  std::vector<Double_t> ferr_zc;
  std::vector<UShort_t> health;
  std::vector<UShort_t> method;
  std::vector< std::array<UShort_t, NMR_FID_LENGTH_ONLINE> > trace;

  inline void Resize(int size) {
    sys_clock.resize(size);
    gps_clock.resize(size);
    dev_clock.resize(size);
    snr.resize(size);
    len.resize(size);
    freq.resize(size);
    ferr.resize(size);
    freq_zc.resize(size);
    ferr_zc.resize(size);
    health.resize(size);
    method.resize(size);
    trace.resize(size);
  }
};

//Trolley data structs
struct trolley_nmr_t{
  unsigned long int gps_clock;
  unsigned short probe_index;
  unsigned short length;
  short trace[TRLY_NMR_LENGTH];
};

#define MAKE_TLNMR_STRING(len) HELPER_TLNMR_STRING(len)
#define HELPER_TLNMR_STRING(len) \
const char * const trolley_nmr_str = "gps_clock/l:probe_index/s:len/s:trace["#len"]/s"
MAKE_TLNMR_STRING(TRLY_NMR_LENGTH);

struct trolley_barcode_t{
  unsigned long int gps_clock;
  unsigned short length_per_ch;
  unsigned short traces[TRLY_BARCODE_LENGTH]; //All channels
};

#define MAKE_BARCODE_STRING(len) HELPER_BARCODE_STRING(len)
#define HELPER_BARCODE_STRING(len) \
const char * const trolley_barcode_str = "gps_clock/l:len_per_ch/s:traces["#len"]/s"
MAKE_BARCODE_STRING(TRLY_BARCODE_LENGTH);

struct trolley_monitor_t{
  unsigned long int gps_clock_cycle_start;
  unsigned int PMonitorVal;
  unsigned int PMonitorTemp;
  unsigned int RFPower1;
  unsigned int RFPower2;
  unsigned int NMRCheckSum;
  unsigned int FrameCheckSum;
  unsigned int FrameSum;
  unsigned int FrameIndex;
  unsigned short StatusBits;
  unsigned short TMonitorIn;
  unsigned short TMonitorExt1;
  unsigned short TMonitorExt2;
  unsigned short TMonitorExt3;
  unsigned short V1Min;
  unsigned short V1Max;
  unsigned short V2Min;
  unsigned short V2Max;
  unsigned short length_per_ch;
  unsigned short trace_VMonitor1[TRLY_MONITOR_LENGTH];
  unsigned short trace_VMonitor2[TRLY_MONITOR_LENGTH];
};

#define MAKE_MONITOR_STRING(len) HELPER_MONITOR_STRING(len)
#define HELPER_MONITOR_STRING(len) \
const char * const trolley_monitor_str = "gps_clock_cycle_start/l:PMonitorVal/i:PMonitorTemp/i:RFPower1/i:RFPower2/i:"\
"NMRCheckSum/i:FrameCheckSum/i:FrameSum/i:StatusBits/s:"\
"TMonitorIn/s:TMonitorExt1/s:TMonitorExt2/s:TMonitorExt3/s:V1Min/s:V1Max/s:V2Min/s:V2Max/s:len_per_ch/s:"\
"trace_VMonitor1["#len"]/s:trace_VMonitor2["#len"]/s"
MAKE_MONITOR_STRING(TRLY_MONITOR_LENGTH);

//Surface coil struct
struct surface_coil_t{
  Double_t sys_clock;
  Double_t bot_coil_currents[SC_NUM_COILS];
  Double_t top_coil_currents[SC_NUM_COILS];
  Double_t bot_coil_temps[SC_NUM_COILS];
  Double_t top_coil_temps[SC_NUM_COILS];
};

#define MAKE_SC_STRING(name,num_coils) SC_HELPER(name,num_coils)

#define SC_HELPER(name,num_coils)\
const char * const name = "sys_clock/D:bot_coil_currents["#num_coils"]/D:top_coil_currents["#num_coils"]/D:bot_coil_temps["#num_coils"]/D:top_coil_temps["#num_coils"]/D"
  
MAKE_SC_STRING(sc_str,SC_NUM_COILS);

} // ::g2field

#endif
