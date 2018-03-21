## Simp
A WIP simple pixel art editor. I could not find a simple editor that let me draw pixel art for a tiled game in Linux without a complicated mess of a user interface, so here we are...

### Controls

 * left-click - draw current color
 * Left-control (held) + left-click - eye dropper/color picking tool
 * Left-control-S - saves.
 * scroll-wheel-button - drag the canvas
 * scroll-wheel - zoom in/out
 * S then left-click (hold) - region select
 * S then A - reset region select to entire image
 * M then left-click (hold) inside selected region - grab selected pixels
 * L - toggle pixel grid

### Required Packages (Linux)

 * xorg-dev
 * gtk+-3.0-dev

### Build
```
cmake .
cmake --build .
```

### Usage
`simp [filename]`
