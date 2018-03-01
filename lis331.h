
#define CTRL_REG1        0x20
#define CTRL_REG2        0x21
#define CTRL_REG3        0x22
#define CTRL_REG4        0x23
#define CTRL_REG5        0x24
#define HP_FILTER_RESET  0x25
#define REFERENCE        0x26
#define STATUS_REG       0x27
#define OUT_X_L          0x28
#define OUT_X_H          0x29
#define OUT_Y_L          0x2A
#define OUT_Y_H          0x2B
#define OUT_Z_L          0x2C
#define OUT_Z_H          0x2D
#define INT1_CFG         0x30
#define INT1_SOURCE      0x31
#define INT1_THS         0x32
#define INT1_DURATION    0x33
#define INT2_CFG         0x34
#define INT2_SOURCE      0x35
#define INT2_THS         0x36
#define INT2_DURATION    0x37



  typedef enum {USE_I2C, USE_SPI} comm_mode;
  typedef enum {POWER_DOWN, NORMAL, LOW_POWER_0_5HZ, LOW_POWER_1HZ,
                LOW_POWER_2HZ, LOW_POWER_5HZ, LOW_POWER_10HZ} power_mode;
  typedef enum {DR_50HZ, DR_100HZ, DR_400HZ, DR_1000HZ} data_rate;
  typedef enum {HPC_8, HPC_16, HPC_32, HPC_64} high_pass_cutoff_freq_cfg;
  typedef enum {PUSH_PULL, OPEN_DRAIN} pp_od;
  typedef enum {INT_SRC, INT1_2_SRC, DRDY, BOOT} int_sig_src;
  typedef enum {LOW_RANGE, MED_RANGE, NO_RANGE, HIGH_RANGE} fs_range;
  typedef enum {X_AXIS, Y_AXIS, Z_AXIS} int_axis;
typedef enum {TRIG_ON_HIGH, TRIG_ON_LOW} trig_on_level;
