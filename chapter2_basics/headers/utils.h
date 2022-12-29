#pragma once

static void onChange(int pos, void* userInput);
static void onMouse(int event, int x, int y, int, void* userInput);
static void blurCallback(int state, void* userData);
static void grayCallback(int state, void* userData);
static void bgrCallback(int state, void* userData);
static void sobelCallback(int state, void* userData);
void applyFilters();
