This repository contains solutions to all problems covered in the ***[Why Not DP? Digit DP Playlist]([https://www.youtube.com/playlist?list=YOUR_PLAYLIST_LINK_HERE](https://youtube.com/playlist?list=PLN2s9sIPkFC9HAF_8Os7pIbE8ZAwlA-uF&si=t2kKb5QUXbg3EeHK))***.
All codes are tested on LeetCode and are organized according to the order of the videos in the playlist.

### State Definitions (Digit DP)

* **idx** → Current position in the digit string (index of the number)
* **tight** → Constraint flag:

  * `1` → The current prefix is restricted (you can only use digits from `0` to `s[i]`)
  * `0` → No restriction (you can use digits from `0` to `9`)
* **lz (leading zero)** → Indicates whether the number has started:

  * `1` → Still placing leading zeros (number not started yet)
  * `0` → Number has started (a non-zero digit has been placed)

**[Why Not DP? [By Piyush Raj]](https://www.youtube.com/@whynotdp)** in his ***[Digit DP Playlist([https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1(https://youtube.com/playlistlist=PLN2s9sIPkFC9HAF_8Os7pIbE8ZAwlA-uF&si=5JUzxeKP6fTLb79U))]]***.
