# adjoon QMK ARDUX Fork

This personal fork is set up to build ardux for a left handed paintbrush, compiling to .uf2 format (for RP2040 controllers).

It includes my own personal remix files, which are still somewhat WIP, but should be working at least. 

My remix implements a new base layer, based on a comment from purple_rw, which is supposed to reduce SFB, with my own modification to move space to the base layer.
```
  O    N    I    S
Space  R    E    T
```
The remix also implements my own custom combos for the rest of the alpha keys. Layout map coming soon™.

These combos are roughly based on matching the easiest to input combos with the most frequent English letters. Additionally, I matched combo placement on the top vs bottom row with the placement of the key on the base colemak layout, which I found made things more intuitive to pick up, without having to compromise much on the ergonomics.

Beyond that, I am in the process of implementing my own custom num/sym/nav etc layers, but these are still a WIP. 

## Compiling to .uf2 and forking this repo
I think the main change to make this work was just to the .yaml in the `.github/workflows/` directory. If you are building your own RP2040 paintbrush, you might be able to just copy my .yaml to get it working.

Feel free to fork this whole repo as a jumping off point for your own remix. Ideally when remixing, all changes are contained within the remixes folder, so you should be able to just gitignore/remove the whole `/users/ardux/layout/remixes/` folder to return to a vanilla implementation. **HOWEVER,** this repo also currently contains modification to the `/users/ardux/layout/ardux_thepaintbrush.json` file. To restore to vanilla, remove or rename this file and replace it with the `ardux_thepaintbrush_ORIGINAL.json` I preserved in the same folder.

## More remixing info
I have been working on notes about the remixing process as I go, these are found in the [`/users/ardux/layout/remixes/README.md`](/users/ardux/layout/remixes/README.md).

## Personal thoughts

### Background about the base layer changes
My original plan was a fully colemak inspired base layer of
```
O I E N
A R S T
```
(left handed), but I found the muscle memory a bit uncanny, and decided to try something more distinct. One factor that was confusing was the fact that I was pressing eg both 'T' and 'N' with the same order of finger as usual, but on two different rows. Because my left hand naturally mirrored the muscle memory to hit the right hand homerow keys, as well as the usual left hand ones, it started getting confused which row it was on.

This new layout broke up all the same finger pairs from the original homerow, and is helping me build a distinct muscle memory for the ardux board.

Moving space to the base layer makes sense for typing since space is essentially in every word. For my intended use case it may not be as important, but I am doing typing practice to build familiarity with the layout, and hitting a combo for space after every single word just didn't make sense.



# QMK ARDUX Implementation

This repo contains the [QMK](https://qmk.fm/) ARDUX implementation and pre-built firmware for boards that have been setup to use ARDUX by the core ARDUX development team.

## Prebuilt Firmware

The `Releases` area of this repository contains the latest builds of the QMK ARDUX implementation. You can click on the most recent release and download the appropriate artifact for your MCU + board combination.

### Firmware Files

The firmware files are auto built for a variety of common boards as well as community requested/supported boards. Our builds do *NOT* override default mcu/bootloader/architecture. Please mind this fact if you've tweaked your board in any way relative to the official QMK sources.

### Flashing

We recommend Windows and OSX users download the pre-built hex files and use [QMK Toolbox](https://github.com/qmk/qmk_toolbox). 

If you are on Linux, you'll need to use the `qmk flash` command with the same options as we use to compile. The compile options can be found in  `DEVELOPMENT.md` and are compatible with the `qmk flash` command. If there is an alternative thats easier to use, please let us know on Discord or GitHub Issue.

**We are NOT responsible for any failed firmware flashes!**

## Adding ARDUX support to an existing qmk board

See [DEVELOPMENT.md](DEVELOPMENT.md)

## Tweaking and Remixing

See [REMIXING.md]

## Inspiraion

A lot of this work wouldn't be possible with outside inspiration. In no particular order:

- The ARDUX community for their help ensuring our code is maximally accessible
- [filterpaper's QMK userspace](https://github.com/filterpaper/qmk_userspace)
- [sungo's QMK userspace](https://git.sr.ht/~sungo/qmk_userspace)

## Licensing

Unless otherwise stated all source code is licensed under the [Apache 2 License](LICENSE-APACHE-2.0.txt).

Unless otherwise stated the non source code contents of this repository are licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE-CC-Attribution-NonCommercial-ShareAlike-4.0-International.txt)
