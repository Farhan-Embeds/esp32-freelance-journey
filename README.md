@"
# esp32-freelance-journey

Daily ESP32 practice. Polished projects get pulled out into their own repos later.

**Board:** DOIT ESP32 DEVKIT V1 (PlatformIO, Arduino framework)

## Days

| Day | Folder | What it does | Date |
|-----|--------|--------------|------|
| 1 | [day01-blink-uptime](day01-blink-uptime) | Blinks the onboard LED (GPIO 2) and prints `Uptime: N s` over Serial at 115200 baud, using `millis()` with no `delay()` | 2026-10-02 |
| 2 | [day02-button-debounce](day02-button-debounce) | Reads the BOOT button (GPIO 0) with a 30 ms `millis()` debounce, switches the LED, and prints "LED is on" and "LED is off" on each change | 2026-10-04 |

Each day is its own PlatformIO project. Open that folder in VS Code and build from there.
"@ | Set-Content -Encoding utf8 README.md