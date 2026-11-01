# Blink — built-in LED

## Goal

Confirm the Arduino toolchain and board are working by blinking the board's built-in LED. This experiment requires no external components or jumper wires.

## Hardware

- An Arduino-compatible board that defines LED_BUILTIN.
- USB cable suitable for data and power.

## Upload

1. Open blink.ino in Arduino IDE.
2. Select the exact board model and port.
3. Compile, then upload.
4. The built-in LED should turn on and off at roughly one-second intervals.

Alternatively, with Arduino CLI, install/select the board's core first, then compile and upload using the FQBN and port for your board:

```bash
arduino-cli compile --fqbn <YOUR_BOARD_FQBN> experiments/blink
arduino-cli upload -p <YOUR_PORT> --fqbn <YOUR_BOARD_FQBN> experiments/blink
```

Replace the placeholders with the values for your board. No external LED or power supply should be connected for this experiment.
