
# fract-ol

![Mandelbrot](https://github.com/user-attachments/assets/00af210f-6644-4e2d-9799-f6b0e2c9fb62)

A fractal renderer written in C using MiniLibX. Supports the Mandelbrot set and Julia sets with real-time zoom, pan, and iteration control.

## Build

```bash
make
```

The binary is output to `build/fractol`.

## Usage

```bash
./build/fractol mandelbrot
./build/fractol julia <real> <imaginary>
```

**Julia examples:**
```
./build/fractol julia 0 0.8
./build/fractol julia 0.37 0.1
./build/fractol julia -0.4 -0.59
```

## Controls

| Key / Input     | Action              |
|-----------------|---------------------|
| `+` / `-`       | Increase / decrease iteration depth |
| Arrow keys      | Pan                 |
| Mouse scroll    | Zoom in / out       |
| `ESC`           | Quit                |

## Screenshots

<img width="804" height="804" alt="Julia set" src="https://github.com/user-attachments/assets/b51babc6-ce94-4af4-b325-e26380f2c9b7" />


<img width="800" height="874" alt="fractol" src="https://github.com/user-attachments/assets/b2c90d07-8cf4-4fab-8497-211584dae4e2" />

## Dependencies

- [MiniLibX](minilibx-linux/) — lightweight X11 graphics library
- [libft](libft/) — custom C standard library (42 school)
