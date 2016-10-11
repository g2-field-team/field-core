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

namespace g2field {

// NMR structs
MAKE_NMR_STRUCT(fixed_t, nmr_num_fixed_probes, nmr_fid_length_record);
MAKE_NMR_STRING(fixed_str, nmr_num_fixed_probes, nmr_fid_length_record);

MAKE_NMR_STRUCT(online_fixed_t, nmr_num_fixed_probes, nmr_fid_length_online);
MAKE_NMR_STRING(online_fixed_str, nmr_num_fixed_probes, nmr_fid_length_online);

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
  std::vector< std::array<UShort_t, nmr_> > trace;

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

} // ::g2field

#endif
