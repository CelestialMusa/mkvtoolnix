/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL v2
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   definitions and helper functions for DTS data

   Written by Peter Niemayer <niemayer@isg.de>.
   Modified by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef MTX_COMMON_DTS_H
#define MTX_COMMON_DTS_H

namespace mtx { namespace dts {

enum class sync_word_e {
    core = 0x7ffe8001
  , hd   = 0x64582025
};

enum class frametype_e {
  // Used to extremely precisely specify the end-of-stream (single PCM
  // sample resolution).
    termination = 0
  , normal
 };

enum class extension_audio_descriptor_e {
    xch = 0                      // channel extension
  , unknown1
  , x96k                         // frequency extension
  , xch_x96k                     // both channel and frequency extension
  , unknown4
  , unknown5
  , unknown6
  , unknown7
};

enum class lfe_type_e {
    none
  , lfe_128 // 128 indicates the interpolation factor to reconstruct the lfe channel
  , lfe_64  //  64 indicates the interpolation factor to reconstruct the lfe channel
  , invalid
};

enum class multirate_interpolator_e {
    non_perfect
  , perfect
};

enum class hd_type_e {
    none
  , high_resolution
  , master_audio
};

enum class source_pcm_resolution_e {
    spr_16 = 0
  , spr_16_ES  //_ES means: surround channels mastered in DTS-ES
  , spr_20
  , spr_20_ES
  , spr_invalid4
  , spr_24_ES
  , spr_24
  , spr_invalid7
};

static const int64_t max_packet_size = 15384;

struct header_t {
  frametype_e frametype;

  // 0 for normal frames, 1 to 30 for termination frames. Number of PCM
  // samples the frame is shorter than normal.
  unsigned int deficit_sample_count;

  // If true, a CRC-sum is included in the data.
  bool crc_present;

  // number of PCM core sample blocks in this frame. Each PCM core sample block
  // consists of 32 samples. Notice that "core samples" means "samples
  // after the input decimator", so at sampling frequencies >48kHz, one core
  // sample represents 2 (or 4 for frequencies >96kHz) output samples.
  unsigned int num_pcm_sample_blocks;

  // Number of bytes this frame occupies (range: 95 to 16 383).
  unsigned int frame_byte_size;

  // Number of audio channels, -1 for "unknown".
  int audio_channels;

  // String describing the audio channel arrangement
  const char *audio_channel_arrangement;

  // -1 for "invalid"
  unsigned int core_sampling_frequency;

  // in bit per second, or -1 == "open", -2 == "variable", -3 == "lossless"
  int transmission_bitrate;

  // if true, sub-frames contain coefficients for downmixing to stereo
  bool embedded_down_mix;

  // if true, sub-frames contain coefficients for dynamic range correction
  bool embedded_dynamic_range;

  // if true, a time stamp is embedded at the end of the core audio data
  bool embedded_time_stamp;

  // if true, auxiliary data is appended at the end of the core audio data
  bool auxiliary_data;

  // if true, the source material was mastered in HDCD format
  bool hdcd_master;

  extension_audio_descriptor_e extension_audio_descriptor; // significant only if extended_coding == true

  // if true, extended coding data is placed after the core audio data
  bool extended_coding;

  // if true, audio data check words are placed in each sub-sub-frame
  // rather than in each sub-frame, only
  bool audio_sync_word_in_sub_sub;

  lfe_type_e lfe_type;

  // if true, past frames will be used to predict ADPCM values for the
  // current one. This means, if this flag is false, the current frame is
  // better suited as an audio-jump-point (like an "I-frame" in video-coding).
  bool predictor_history_flag;

  // which FIR coefficients to use for sub-band reconstruction
  multirate_interpolator_e multirate_interpolator;

  // 0 to 15
  unsigned int encoder_software_revision;

  // 0 to 3 - "top-secret" bits indicating the "copy history" of the material
  unsigned int copy_history;

  // 16, 20 or 24 bits per sample, or -1 == invalid
  int source_pcm_resolution;

  // if true, source surround channels are mastered in DTS-ES
  bool source_surround_in_es;

  // if true, left and right front channels are encoded as
  // sum and difference (L = L + R, R = L - R)
  bool front_sum_difference;

  // same as front_sum_difference for surround left and right channels
  bool surround_sum_difference;

  // gain in dB to apply for dialog normalization
  int dialog_normalization_gain;

  bool hd;
  hd_type_e hd_type;
  int hd_part_size;

public:
  inline int get_packet_length_in_core_samples() const {
    // computes the length (in time, not size) of the packet in "samples".
    int r = num_pcm_sample_blocks * 32;
    if (frametype_e::termination == frametype)
      r -= deficit_sample_count;

    return r;
  }

  inline double get_packet_length_in_nanoseconds() const {
    // computes the length (in time, not size) of the packet in "samples".
    auto samples = get_packet_length_in_core_samples();

    return static_cast<double>(samples) * 1000000000.0 / core_sampling_frequency;
  }

  unsigned int get_total_num_audio_channels() const;
  void print() const;
};

int find_sync_word(const unsigned char *buf, unsigned int size);
int find_header(const unsigned char *buf, unsigned int size, struct header_t *header, bool allow_no_hd_search = false);
int find_consecutive_headers(const unsigned char *buf, unsigned int size, unsigned int num);

bool operator ==(header_t const &h1, header_t const &h2);
bool operator!=(header_t const &h1, header_t const &h2);

void convert_14_to_16_bits(const unsigned short *src, unsigned long srcwords, unsigned short *dst);

bool detect(const void *src_buf, int len, bool &convert_14_to_16, bool &swap_bytes);

}}

#endif // MTX_COMMON_DTS_H
