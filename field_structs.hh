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
  ULong64_t gps_clock;
  UShort_t probe_index;
  UShort_t length;
  Short_t trace[TRLY_NMR_LENGTH];
};

#define MAKE_TLNMR_STRING(len) HELPER_TLNMR_STRING(len)
#define HELPER_TLNMR_STRING(len) \
const char * const trolley_nmr_str = "gps_clock/l:probe_index/s:len/s:trace["#len"]/S"
MAKE_TLNMR_STRING(TRLY_NMR_LENGTH);

struct trolley_barcode_t{
  ULong64_t gps_clock;
  UShort_t length_per_ch;
  UShort_t traces[TRLY_BARCODE_LENGTH]; //All channels
};

#define MAKE_BARCODE_STRING(len) HELPER_BARCODE_STRING(len)
#define HELPER_BARCODE_STRING(len) \
const char * const trolley_barcode_str = "gps_clock/l:len_per_ch/s:traces["#len"]/s"
MAKE_BARCODE_STRING(TRLY_BARCODE_LENGTH);

struct trolley_monitor_t{
  ULong64_t gps_clock_cycle_start;
  UInt_t PMonitorVal;
  UInt_t PMonitorTemp;
  UInt_t RFPower1;
  UInt_t RFPower2;
  UInt_t NMRCheckSum;
  UInt_t FrameCheckSum;
  UInt_t FrameSum;
  UInt_t FrameIndex;
  UShort_t StatusBits;
  UShort_t TMonitorIn;
  UShort_t TMonitorExt1;
  UShort_t TMonitorExt2;
  UShort_t TMonitorExt3;
  UShort_t V1Min;
  UShort_t V1Max;
  UShort_t V2Min;
  UShort_t V2Max;
  UShort_t length_per_ch;
  UShort_t trace_VMonitor1[TRLY_MONITOR_LENGTH];
  UShort_t trace_VMonitor2[TRLY_MONITOR_LENGTH];
};

#define MAKE_MONITOR_STRING(len) HELPER_MONITOR_STRING(len)
#define HELPER_MONITOR_STRING(len) \
const char * const trolley_monitor_str = "gps_clock_cycle_start/l:PMonitorVal/i:PMonitorTemp/i:RFPower1/i:RFPower2/i:"\
"NMRCheckSum/i:FrameCheckSum/i:FrameSum/i:StatusBits/s:"\
"TMonitorIn/s:TMonitorExt1/s:TMonitorExt2/s:TMonitorExt3/s:V1Min/s:V1Max/s:V2Min/s:V2Max/s:len_per_ch/s:"\
"trace_VMonitor1["#len"]/s:trace_VMonitor2["#len"]/s"
MAKE_MONITOR_STRING(TRLY_MONITOR_LENGTH);

//Galil Data structs
struct galil_data_t{
  ULong64_t TimeStamp;
  Int_t Tensions[2];
  Int_t Positions[3];
  Int_t Velocities[3];
  Int_t OutputVs[3];
};

const char * const galil_data_str = "TimeStamp/l:Tensions[2]/I:Positions[3]/I:Velocities[3]/I:OutputVs[3]/I";

//This struct is auxiliary
struct galil_data_d_t{
  Double_t Tensions[2];
  Double_t Positions[3];
  Double_t Velocities[3];
  Double_t OutputVs[3];
};

//Absolute probe data struct
struct absolute_nmr_info_t{
  ULong64_t time_stamp;
  UInt_t length;
  Int_t Pos[4]; //Coordinate X,Y,Z,S
  UShort_t flay_run_number;
  UShort_t probe_index;
  //Because the length of the trace varies too much, it is not included in this struct
};

#define MAKE_ABSNMR_STRING() HELPER_ABSNMR_STRING()
#define HELPER_ABSNMR_STRING() \
const char * const absolute_nmr_info_str = "time_stamp/l:length/i:Pos[4]/i:flay_run_number/s:probe_index/s"
MAKE_ABSNMR_STRING();

// Absolute calibration NMR structs
MAKE_NMR_STRUCT(abs_fixed_t, ABS_NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_RECORD);
MAKE_NMR_STRING(abs_fixed_str, ABS_NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_RECORD);

MAKE_NMR_STRUCT(abs_online_fixed_t, ABS_NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_ONLINE);
MAKE_NMR_STRING(abs_online_fixed_str, ABS_NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_ONLINE);

//Surface coil struct
struct surface_coil_t{
  Double_t bot_sys_clock[SC_NUM_COILS];
  Double_t top_sys_clock[SC_NUM_COILS];
  Double_t bot_coil_currents[SC_NUM_COILS];
  Double_t top_coil_currents[SC_NUM_COILS];
  Double_t bot_coil_temps[SC_NUM_COILS];
  Double_t top_coil_temps[SC_NUM_COILS];
};

#define MAKE_SC_STRING(name,num_coils) SC_HELPER(name,num_coils)

#define SC_HELPER(name,num_coils)\
const char * const name = "sys_clock["#num_coils"]/D:bot_coil_currents["#num_coils"]/D:top_coil_currents["#num_coils"]/D:bot_coil_temps["#num_coils"]/D:top_coil_temps["#num_coils"]/D"
  
MAKE_SC_STRING(sc_str,SC_NUM_COILS);

// Yokogawa struct 
struct yokogawa_t{
   ULong64_t sys_clock;   // system clock
   ULong64_t gps_clock;   // GPS clock 
   Int_t mode;            // device mode (0 = voltage, 1 = current)  
   Int_t is_enabled;      // is the output enabled (0 = false, 1 = true) 
   Double_t current;      // current setting (in mA) 
   Double_t voltage;      // voltage setting (in V) 
};

#define MAKE_YOKO_STRING() HELPER_YOKO_STRING() 
#define HELPER_YOKO_STRING() \
const char * const yokogawa_str = "sys_clock/l:gps_clock/l:is_enabled/i:current/D"
MAKE_YOKO_STRING();

} // ::g2field

#endif
