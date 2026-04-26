This repository contains solutions to all problems covered in the **"Why Not DP? Digit DP Playlist"**.
All codes are tested on LeetCode and are organized according to the order of the videos in the playlist.

### State Definitions (Digit DP)

* **idx** → Current position in the digit string (index of the number)
* **tight** → Constraint flag:

  * `1` → The current prefix is restricted (you can only use digits from `0` to `s[i]`)
  * `0` → No restriction (you can use digits from `0` to `9`)
* **lz (leading zero)** → Indicates whether the number has started:

  * `1` → Still placing leading zeros (number not started yet)
  * `0` → Number has started (a non-zero digit has been placed)
