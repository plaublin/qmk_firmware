# chocofi

![chocofi](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Pavel Glushkov](https://github.com/pashutk/chocofi)
* Hardware Supported: Beekeeb's chocofi (sea picro)
* Hardware Availability: [Beekeeb](https://shop.beekeeb.com/product/chocofi-36-keys-kailh-low-profile-choc-v1-mechanical-ergonomic-hotswap-split-keyboard-diy-kit/)

To compile the keyboard:

    qmk compile -kb chocofi -km plaublin

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

