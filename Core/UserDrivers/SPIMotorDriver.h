/*
 * SPIDriver.h
 *
 *  Created on: Oct 4, 2022
 *      Author: jeremycote
 */

#ifndef USERDRIVERS_SPIMOTORDRIVER_H_
#define USERDRIVERS_SPIMOTORDRIVER_H_

// STM headers
#include "stm32l4xx_hal.h"

// Our headers
#include "ApplicationTypes.h"

#define TMC4671_CS 0
#define TMC6200_CS 1

// Motor 0 = Small Motor
#define MOTOR 1

// ===== TMC Motor Configuration =====
#if MOTOR == 0

	#define MAX_VELOCITY 4000
	#define MIN_VELOCITY 0

	#define TORQUE_FLUX_MAX 	(int32_t)10000
	#define POSITION_SCALE_MAX  (int32_t)65536

	#define MOTOR_LABEL "TMC4671"
	#define MOTOR_DRIVER_LABEL "TMC6200"

	#define MAX_TORQUE (uint32_t)0x7FFF0000
	#define MIN_TORQUE (uint32_t)0x0000FFFF

	// Motor type &  PWM configuration
	#define MOTOR_CONFIG_N_POLE_PAIRS (uint32_t)0x00030004
	#define MOTOR_CONFIG_PWM_POLARITIES (uint32_t)0x00000000
	#define MOTOR_CONFIG_PWM_MAXCNT (uint32_t)0x00000F9F

	#define MOTOR_CONFIG_PWM_BBM_H_BBM_L (uint32_t)0x00001919
	#define MOTOR_CONFIG_PWM_SV_CHOP (uint32_t)0x00000007

	// ADC configuration
	#define MOTOR_CONFIG_ADC_I_SELECT (uint32_t)0x24000100
	#define MOTOR_CONFIG_dsADC_MCFG_B_MCFG_A (uint32_t)0x00100010
	#define MOTOR_CONFIG_dsADC_MCLK_A (uint32_t)0x20000000
	#define MOTOR_CONFIG_dsADC_MCLK_B (uint32_t)0x00000000
	#define MOTOR_CONFIG_dsADC_MDEC_B_MDEC_A (uint32_t)0x014E014E
	#define MOTOR_CONFIG_ADC_I0_SCALE_OFFSET (uint32_t)0xFF007FE3
	#define MOTOR_CONFIG_ADC_I1_SCALE_OFFSET (uint32_t)0xFF0080E9

	// Digital hall settings
	#define MOTOR_CONFIG_HALL_MODE (uint32_t)0x00000001
	#define MOTOR_CONFIG_HALL_PHI_E_PHI_M_OFFSET (uint32_t)0x00000000

	// Feedback selection
	#define MOTOR_CONFIG_PHI_E_SELECTION (uint32_t)0x00000005
	#define MOTOR_CONFIG_VELOCITY_SELECTION (uint32_t)0x0000000C

	// Limits
	#define MOTOR_CONFIG_PID_TORQUE_FLUX_LIMITS (uint32_t) 1000 // in mA

	// PI settings
	#define MOTOR_CONFIG_PID_TORQUE_P_TORQUE_I (uint32_t)0x01000100
	#define MOTOR_CONFIG_PID_FLUX_P_FLUX_I (uint32_t)0x01000100

	// NEW
	#define MOTOR_CONFIG_TORQUE_MESUREMENT_FACTOR (uint32_t) 256

	// ===== Digital hall test drive =====
	// Set motor controller to velocity mode
	#define MOTOR_CONFIG_MODE_RAMP_MODE_MOTION (uint32_t)0x00000002

	// ===== TMC6200 Values ===== (See TMC6200 Datasheet for breakdown of each
	// parameter)

	/**
	 * General Configuration Flags for the TMC6200
	 * Bit 0: disable (Driver Disable). Cycle low to clear short conditions.
	 */
	#define MOTOR_CONFIG_DRIVER_GENERAL_CONFIG (uint32_t)0x00000000

	/**
	 * Short detection / Safety parameters
	 * 0x13010606 is the factory default value
	 */
	#define MOTOR_CONFIG_DRIVER_SHORT_CONFIG (uint32_t)0x13010606

	/**
	 * Drive parameters
	 * 0x00080004 is the factory default value
	 */
	#define MOTOR_CONFIG_DRIVER_DRIVE_CONFIG (uint32_t)0x00080004

#endif

#if MOTOR == 1

#define MAX_VELOCITY 4000
	#define MIN_VELOCITY 0

	#define TORQUE_FLUX_MAX 	(int32_t)10000
	#define POSITION_SCALE_MAX  (int32_t)65536

	#define MOTOR_LABEL "TMC4671"
	#define MOTOR_DRIVER_LABEL "TMC6200"

	#define MAX_TORQUE (uint32_t)0x7FFF0000
	#define MIN_TORQUE (uint32_t)0x0000FFFF

	// Motor type &  PWM configuration
	#define MOTOR_CONFIG_N_POLE_PAIRS (uint32_t)0x00030004
	#define MOTOR_CONFIG_PWM_POLARITIES (uint32_t)0x00000000
	#define MOTOR_CONFIG_PWM_MAXCNT (uint32_t)0x00000F9F

	#define MOTOR_CONFIG_PWM_BBM_H_BBM_L (uint32_t)0x00001919
	#define MOTOR_CONFIG_PWM_SV_CHOP (uint32_t)0x00000007

	// ADC configuration
	#define MOTOR_CONFIG_ADC_I_SELECT (uint32_t)0x24000100
	#define MOTOR_CONFIG_dsADC_MCFG_B_MCFG_A (uint32_t)0x00100010
	#define MOTOR_CONFIG_dsADC_MCLK_A (uint32_t)0x20000000
	#define MOTOR_CONFIG_dsADC_MCLK_B (uint32_t)0x00000000
	#define MOTOR_CONFIG_dsADC_MDEC_B_MDEC_A (uint32_t)0x014E014E
	#define MOTOR_CONFIG_ADC_I0_SCALE_OFFSET (uint32_t)0xFF007FE3
	#define MOTOR_CONFIG_ADC_I1_SCALE_OFFSET (uint32_t)0xFF0080E9

	// Digital hall settings
	#define MOTOR_CONFIG_HALL_MODE (uint32_t)0x00000001
	#define MOTOR_CONFIG_HALL_PHI_E_PHI_M_OFFSET (uint32_t)0x00000000

	// Feedback selection
	#define MOTOR_CONFIG_PHI_E_SELECTION (uint32_t)0x00000003 // Use ABN encoder as PHI E selection
	#define MOTOR_CONFIG_VELOCITY_SELECTION (uint32_t)0x00000003 // Use ABN encoder for velocity selection

	// Limits
	#define MOTOR_CONFIG_PID_TORQUE_FLUX_LIMITS (uint32_t) 1000 // in mA

	// PI settings
	#define MOTOR_CONFIG_PID_TORQUE_P_TORQUE_I 256 //(uint32_t)0x01000100
	#define MOTOR_CONFIG_PID_FLUX_P_FLUX_I 256 //(uint32_t)0x01000100

	// NEW
	#define MOTOR_CONFIG_TORQUE_MESUREMENT_FACTOR (uint32_t) 256

	// ===== Digital hall test drive =====
	// Set motor controller to velocity mode
	#define MOTOR_CONFIG_MODE_RAMP_MODE_MOTION (uint32_t)0x00000002

	// ===== TMC6200 Values ===== (See TMC6200 Datasheet for breakdown of each
	// parameter)

	/**
	 * General Configuration Flags for the TMC6200
	 * Bit 0: disable (Driver Disable). Cycle low to clear short conditions.
	 */
	#define MOTOR_CONFIG_DRIVER_GENERAL_CONFIG (uint32_t)0x00000000

	/**
	 * Short detection / Safety parameters
	 * 0x13010606 is the factory default value
	 */
	#define MOTOR_CONFIG_DRIVER_SHORT_CONFIG (uint32_t)0x13010606

	/**
	 * Drive parameters
	 * 0x00080004 is the factory default value
	 */
	#define MOTOR_CONFIG_DRIVER_DRIVE_CONFIG (uint32_t)0x00080004

	#define ABN

	#define MOTOR_CONFIG_ABN_DECODER_MODE (uint32_t)0x00000000 //0x25: Polarity of A pulse.
	#define MOTOR_CONFIG_ABN_DECODER_PPR (uint32_t) 0x00000B40 //0x26: Decoder pulses per mechanical revolution.
	#define MOTOR_CONFIG_ABN_DECODER_COUNT (uint32_t) 0x00000A26 //0x27: Raw decoder count; the digital decoder engine counts modulo (decoder_ppr).
	#define MOTOR_CONFIG_ABN_DECODER_COUNT_N (uint32_t) 0x0000096C //0x28: Decoder count latched on N pulse, when N pulse clears decoder_count also decoder_count_n is 0.
	#define MOTOR_CONFIG_ABN_DECODER_PHI_E_PHI_M_OFFSET 0x00000000 //0x29: ABN_DECODER_PHI_M_OFFSET to shift (rotate) angle DECODER_PHI_M.
	#define MOTOR_CONFIG_ABN_DECODER_PHI_E_PHI_M 0x5FA417E9 //0x2A: ABN_DECODER_PHI_M = ABN_DECODER_COUNT * 2^16 / ABN_DECODER_PPR + ABN_DECODER_PHI_M_OFFSET;
#endif

PRIVATE typedef struct {
	uint16_t  startVoltage;
	uint16_t  initWaitTime;
	uint16_t  actualInitWaitTime;
	uint8_t   initState;
	uint8_t   initMode;
	uint16_t  torqueMeasurementFactor;  // uint8_t.uint8_t
	uint32_t  maximumCurrent;
	uint8_t	  motionMode;
	int32_t   actualVelocityPT1;
	int64_t	  akkuActualVelocity;
	int16_t   actualTorquePT1;
	int64_t   akkuActualTorque;
	int16_t   actualFluxPT1;
	int64_t   akkuActualFlux;
	int32_t   positionScaler;
	int32_t   linearScaler;
	int16_t   hall_phi_e_old;
	int16_t   hall_phi_e_new;
	int16_t   hall_actual_coarse_offset;
	uint16_t  last_Phi_E_Selection;
	uint32_t  last_UQ_UD_EXT;
	int16_t   last_PHI_E_EXT;
	uint8_t	  enableVelocityFeedForward;
} MotorDriverConfig_t;

/**
 * Read Write a single byte over SPI.
 * CS is held low until function is called with lastTransfer == 12.
 */
PUBLIC uint8_t tmc4671_readwriteByte(uint8_t motor, uint8_t data, uint8_t lastTransfer);

/**
 * Set the Chip Select (CS) pin for a particular slave to state
 */
PRIVATE void MotorSetCS(uint8_t cs, GPIO_PinState state);

PUBLIC uint32_t MotorValidateSPI();

// ===== Functions for interacting with motor =====
/**
 * Rotate the motor
 */
PUBLIC uint32_t MotorRotate(int32_t velocity);

PUBLIC uint32_t MotorPeriodicJob(uint32_t actualSystick);

PUBLIC uint32_t MotorEnableDriver(Enable_t enabled);

PUBLIC velocity_t MotorGetActualVelocity();
/**
 * Initialize registers in the TMC4671 and TMC6200. Must be called before motor
 * will function properly. Returns true if motor init was successful.
 */
PUBLIC uint32_t MotorInit();
PUBLIC uint32_t MotorDeInit();


#endif /* USERDRIVERS_SPIMOTORDRIVER_H_ */
