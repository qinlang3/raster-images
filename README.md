# Computer Graphics – Raster Images

    mkdir build
    cd build
    cmake ..
    make

## Execution

    ./raster


![If you've implemented `src/rgba_to_rgb.cpp` correctly then `./raster
../data/dog.png` should produce this image in
`rgb.ppm`.](images/rgb.png) 

### `reflect`

![If you've implemented `src/write_ppm.cpp` correctly then `./raster
../data/dog.png` should produce this image in
`reflected.ppm`.](images/reflected.png) 

### `rotate`

![`./raster
../data/dog.png` should produce this image in
`rotated.ppm`.](images/rotated.png) 

### `rgb_to_gray`

Convert a 3-channel RGB image to a 1-channel grayscale image.

![`./raster
../data/dog.png` should produce this image in
`gray.ppm`.](images/gray.png) 

### `simulate_bayer_mosaic`

Simulate an image acquired from the Bayer mosaic by taking a 3-channel rgb image
and creating a single channel grayscale image composed of interleaved
red/green/blue channels. The output image should be the same size as the input but only one
channel.

![`./raster
../data/dog.png` should produce this image in
`bayer.ppm`. **Zoom in** to see interleaving.](images/bayer.png) 

### `demosaic`

Given a mosaiced image (interleaved GBRG colors in a single channel), created a
3-channel rgb image.

![`./raster ../data/dog.png` should produce this image in
`demosaicked.ppm`.](images/demosaicked.png) 


### `hue_shift`

Shift the hue of a color rgb image. 

![`./raster
../data/dog.png` should produce this image in
`shifted.ppm`.](images/shifted.png) 

### `desaturate`

Desaturate a given rgb color image by a given factor.

![`./raster
../data/dog.png` should produce this image in
`desaturated.ppm`.](images/desaturated.png) 

### `over`

Compute C = A Over B, where A and B are semi-transparent rgba images and
"Over" is the Porter-Duff Over operator.

![`./raster
../data/{dog,glasses,laser-beams,sparkles}.png` should produce this image in
`composite.ppm`.](images/composite.png) 


