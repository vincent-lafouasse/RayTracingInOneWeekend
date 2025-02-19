#!/bin/sh

cmake -B build && cmake --build build &&./build/RayTracer > img.ppm && open img.ppm
