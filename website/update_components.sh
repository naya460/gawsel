#!/bin/bash

mkdir -p ./src/components

mkdir -p ./src/components/Minesweeper
cp -r ../Next.js/Minesweeper/components/* ./src/components/Minesweeper

mkdir -p ./src/components/LightsOut
cp -r ../Next.js/LightsOut/components/* ./src/components/LightsOut
