import numpy as np
from rtlsdr import RtlSdr
import time
# ---------------- CONFIG ----------------
START_FREQ = 88e6
END_FREQ = 108e6
STEP = 0.2e6 # 200 kHz FM spacing
SAMPLE_COUNT = 4096 # Larger = more stable
SAMPLE_RATE = 2.4e6
GAIN = 35 # Fixed gain
DELAY = 0.02 # Delay between hops
# ----------------------------------------
print("Opening RTL-SDR...")
sdr = RtlSdr()
sdr.sample_rate = SAMPLE_RATE
sdr.gain = GAIN
print("\nScanning FM Band 88–108 MHz...\n")
results = []
freq = START_FREQ
# ---------------- SCANNING LOOP ----------------
while freq <= END_FREQ:
sdr.center_freq = freq
samples = sdr.read_samples(SAMPLE_COUNT)
# TRUE SIGNAL POWER (Energy Detection)
energy = np.mean(np.abs(samples) ** 2)
results.append((freq / 1e6, energy))
freq += STEP
time.sleep(DELAY)
print("\nScan Complete.\n")
sdr.close()
# ---------------- PROCESSING ----------------
energies = np.array([r[1] for r in results])
# Automatic threshold using median
threshold = np.median(energies)
free_list = []
occupied_list = []
for f, e in results:
if e > threshold:
occupied_list.append((f, e))
else:
free_list.append((f, e))
# Sort by frequency
free_list = sorted(free_list, key=lambda x: x[0])
occupied_list = sorted(occupied_list, key=lambda x: x[0])
# ---------------- PRINT OUTPUT ----------------
print(f"Auto Threshold Power = {threshold:.6f}\n")
print("========= OCCUPIED CHANNELS =========\n")
for f, e in occupied_list:
print(f"{f:.1f} MHz | Power = {e:.6f}")
print("\nTotal OCCUPIED Channels:", len(occupied_list))
print("\n=========================================\n")
print("========= FREE CHANNELS =========\n")
for f, e in free_list:
print(f"{f:.1f} MHz | Power = {e:.6f}")
print("\nTotal FREE Channels:", len(free_list))
print("\n=========================================\n")
print("Scan Finished Successfully ")