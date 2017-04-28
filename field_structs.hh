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
  ULong64_t clock_sys_ns[num_ch];\
  ULong64_t clock_gps_ns[num_ch];\
  ULong64_t device_clock[num_ch];\
  Double_t device_rate_mhz[num_ch];\
  Double_t device_gain_vpp[num_ch];\
  Double_t fid_snr[num_ch];\
  Double_t fid_len[num_ch];\
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
const char * const name = "clock_sys_ns["#num_ch"]/l:"\
"clock_gps_ns["#num_ch"]/l:device_clock["#num_ch"]/l:"\
"device_rate_mhz["#num_ch"]/D:device_gain_vpp["#num_ch"]\D:"\
"fid_snr["#num_ch"]/D:fid_len["#num_ch"]/D:freq["#num_ch"]/D:"\
"ferr["#num_ch"]/D:freq_zc["#num_ch"]/D:ferr_zc["#num_ch"]/D:"\
"health["#num_ch"]/s:method["#num_ch"]/s:trace["#num_ch"]["#len_tr"]/s"

// NMR structs
MAKE_NMR_STRUCT(fixed_t, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_RECORD);
MAKE_NMR_STRING(fixed_str, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_RECORD);

MAKE_NMR_STRUCT(online_fixed_t, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_ONLINE);
MAKE_NMR_STRING(online_fixed_str, NMR_NUM_FIXED_PROBES, NMR_FID_LENGTH_ONLINE);

// Flexible struct built from the basic nmr attributes.
struct nmr_vector {
  std::vector<ULong64_t> clock_sys_ns;
  std::vector<ULong64_t> clock_gps_ns;
  std::vector<ULong64_t> device_clock;
  std::vector<Double_t> device_rate_mhz;
  std::vector<Double_t> device_gain_vpp;
  std::vector<Double_t> fid_snr;
  std::vector<Double_t> fid_len;
  std::vector<Double_t> freq;
  std::vector<Double_t> ferr;
  std::vector<Double_t> freq_zc;
  std::vector<Double_t> ferr_zc;
  std::vector<UShort_t> health;
  std::vector<UShort_t> method;
  std::vector< std::array<UShort_t, NMR_FID_LENGTH_ONLINE> > trace;

  inline void Resize(int size) {
    clock_sys_ns.resize(size);
    clock_gps_ns.resize(size);
    device_clock.resize(size);
    device_rate_mhz.resize(size);
    device_gain_vpp.resize(size);
    fid_snr.resize(size);
    fid_len.resize(size);
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
  ULong64_t local_clock;
  UShort_t probe_index;
  UShort_t length;
  UShort_t TS_OffSet;
  UShort_t RF_Prescale;
  UShort_t Probe_Command;	
  UShort_t Preamp_Delay;
  UShort_t Preamp_Period;
  UShort_t ADC_Gate_Delay;
  UShort_t ADC_Gate_Offset;
  UShort_t ADC_Gate_Period;
  UShort_t TX_On;
  UShort_t TX_Delay;
  UShort_t TX_Period;
  UShort_t UserDefinedData;
  Short_t trace[TRLY_NMR_LENGTH];
};

#define MAKE_TLNMR_STRING(len) HELPER_TLNMR_STRING(len)
#define HELPER_TLNMR_STRING(len) \
const char * const trolley_nmr_str = "local_clock/l:probe_index/s:len/s:TS_Offset/s:RF_Prescale/s:Probe_Command/s:Preamp_Delay/s:Preamp_Period/s:ADC_Gate_Delay/s:ADC_Gate_Offset/s:ADC_Gate_Period/s:TX_On/s:TX_Delay/s:TX_Period/s:UserDefinedData/s:trace["#len"]/S"
MAKE_TLNMR_STRING(TRLY_NMR_LENGTH);

struct trolley_barcode_t{
  ULong64_t local_clock;
  UShort_t length_per_ch;
  UShort_t Sampling_Period;
  UShort_t Acquisition_Delay;
  UShort_t DAC_1_Config;	
  UShort_t DAC_2_Config;
  UShort_t Ref_CM;
  UShort_t traces[TRLY_BARCODE_LENGTH]; //All channels
};

#define MAKE_BARCODE_STRING(len) HELPER_BARCODE_STRING(len)
#define HELPER_BARCODE_STRING(len) \
const char * const trolley_barcode_str = "local_clock/l:len_per_ch/s:Sampling_Period/s:Acquisition_Delay/s:DAC_1_Config/s:DAC_2_Config/s:Ref_CM/s:traces["#len"]/s"
MAKE_BARCODE_STRING(TRLY_BARCODE_LENGTH);

struct trolley_monitor_t{
  ULong64_t local_clock_cycle_start;
  UInt_t PMonitorVal;
  UInt_t PMonitorTemp;
  UInt_t RFPower1;
  UInt_t RFPower2;
  UInt_t NMRCheckSum;
  UInt_t ConfigCheckSum;
  UInt_t FrameCheckSum;
  UInt_t NMRFrameSum;
  UInt_t ConfigFrameSum;
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
  UShort_t Trolley_Command;
  UShort_t TIC_Stop;
  UShort_t TC_Start;
  UShort_t TD_Start;
  UShort_t TC_Stop;
  UShort_t Switch_RF;	
  UShort_t PowerEnable;
  UShort_t RF_Enable;
  UShort_t Switch_Comm;
  UShort_t TIC_Start;
  UShort_t Cycle_Length;
  UShort_t Power_Control_1;
  UShort_t Power_Control_2;
  UShort_t trace_VMonitor1[TRLY_MONITOR_LENGTH];
  UShort_t trace_VMonitor2[TRLY_MONITOR_LENGTH];
};

#define MAKE_MONITOR_STRING(len) HELPER_MONITOR_STRING(len)
#define HELPER_MONITOR_STRING(len) \
const char * const trolley_monitor_str = "local_clock_cycle_start/l:PMonitorVal/i:PMonitorTemp/i:RFPower1/i:RFPower2/i:"\
"NMRCheckSum/i:ConfigCheckSum/i:FrameCheckSum/i:NMRFrameSum/i:ConfigFrameSum/i:FrameSum/i:FrameIndex/i:StatusBits/s:"\
"TMonitorIn/s:TMonitorExt1/s:TMonitorExt2/s:TMonitorExt3/s:V1Min/s:V1Max/s:V2Min/s:V2Max/s:len_per_ch/s:"\
"Trolley Command/s:TIC_Stop/s:TC_Start/s:TD_Start/s:TC_Stop/s:Switch_RF/s:PowerEnable/s:RF_Enable/s:"\
"Switch_Comm/s:TIC_Start/s:Cycle_Length/s:Power_Control_1/s:Power_Control_2/s:"\
"trace_VMonitor1["#len"]/s:trace_VMonitor2["#len"]/s"
MAKE_MONITOR_STRING(TRLY_MONITOR_LENGTH);

struct trolley_interface_t{
  ULong64_t gps_clock_cycle_start;
  ULong64_t local_clock_cycle_start;
  ULong64_t local_clock_iv;
  UInt_t rf_power0;
  UInt_t rf_power1;
  UShort_t rf_switch_offset;
  UShort_t comm_switch_offset;
  UShort_t n_iv_samples;
  UShort_t power_protection_trip;
  UShort_t power_status;
  UShort_t ldo_temp_monitor_min;
  UShort_t ldo_temp_monitor_max;
  UShort_t v_15neg_min;
  UShort_t v_15neg_max;
  UShort_t v_15pos_min;
  UShort_t v_15pos_max;
  UShort_t v_5_min;
  UShort_t v_5_max;
  UShort_t v_33_min;
  UShort_t v_33_max;
  UShort_t trace_v_monitor[TRLY_INTERFACE_MONITOR_LENGTH];
  UShort_t trace_i_monitor[TRLY_INTERFACE_MONITOR_LENGTH];
};

#define MAKE_INTERFACE_STRING(len) HELPER_INTERFACE_STRING(len)
#define HELPER_INTERFACE_STRING(len) \
const char * const trolley_interface_str = "gps_clock_cycle_start/l:local_clock_cycle_start/l:local_clock_iv/l:"\
"rf_power0/i:rf_power1/i:rf_switch_offset/s:comm_switch_offset/s:n_iv_samples/s:power_protection_trip/s:power_status/s:"\
"ldo_temp_monitor_min/s:ldo_temp_monitor_max/s:v_15neg_min/s:v_15neg_max/s:v_15pos_min/s:v_15pos_max/s:"\
"v_5_min/s:v_5_max/s:v_33_min/s:v_33_max/s:trace_v_monitor["#len"]/s:trace_i_monitor["#len"]/s"
MAKE_INTERFACE_STRING(TRLY_INTERFACE_MONITOR_LENGTH);

struct trolley_extra_t{
  Double_t GalilTime;
  Int_t Source;
  Int_t GalilPos[2];
  Int_t GalilVel[2];
};

#define MAKE_TRLYEXTRA_STRING() HELPER_TRLYEXTRA_STRING()
#define HELPER_TRLYEXTRA_STRING() \
const char * const trolley_extra_str = "GalilTIME/D:GalilPos[2]/I:GalilVel[2]/I"
MAKE_TRLYEXTRA_STRING();

//Galil Data structs
struct galil_trolley_t{
  ULong64_t TimeStamp;
  Int_t Tensions[2];
  Int_t Temperatures[2];
  Int_t Positions[3];
  Int_t Velocities[3];
  Int_t OutputVs[3];
};

const char * const galil_trolley_str = "TimeStamp/l:Tensions[2]/I:Temperatures[2]:Positions[3]/I:Velocities[3]/I:OutputVs[3]/I";

struct galil_plunging_probe_t{
  ULong64_t TimeStamp;
  Int_t Positions[3];
  Int_t Velocities[3];
  Int_t OutputVs[3];
};

const char * const galil_plunging_probe_str = "TimeStamp/l:Positions[3]/I:Velocities[3]/I:OutputVs[3]/I";

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
