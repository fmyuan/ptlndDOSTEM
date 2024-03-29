#ifndef SOIL_ENV_H_
#define SOIL_ENV_H_

#include "Stefan.h"  
#include "Richard.h"

#include "../data/EnvData.h"
#include "../data/FirData.h"
#include "../data/RestartData.h"

#include "layer/Layer.h"
#include "layer/SoilLayer.h"
#include "layer/PeatLayer.h"

#include "../inc/parameters.h"
#include "../lookup/CohortLookup.h"
#include "../inc/layerconst.h"

#include "Moss.h"
#include "Peat.h"
#include "Mineral.h"
#include "../inc/ErrorCode.h"
#include "../util/Exception.h"

#ifdef FEN
#ifdef CONTROL
const double wtb2005[116] = {6, 6.2, 7.3, 5.7, 5.5, 5.3, 11, 11.3, 11.2, 12,
	11, 8.8, 10.3, 7.7, 7.1, 7, 6.5, 7.9, 9.2, 8.8, 10.4, 11.7, 12.6, 13.5,
	6.3, 0, 0, 0, 0.5, 1, 1, 1.5, 2, 2.3, 2.9, 3, 0.6, 0.5, 0.4, 0.8, 1,
	1.3, 2, 2, 2.4, 3, 3.5, 4.3, 5, 5.4, 6, 6.4, 7.3, 8, 8, 8.5, 9.4, 10,
	10, 10.1, 10.5, 11, 11.3, 12, 12.7, 13, 11.8, 12.1, 13, 13.2, 13.9, 14,
	14, 14.3, 14, 11.4, 9.8, 9.5, 9.3, 10, 10.4, 11.3, 12, 12, 12.2, 13,
	12.3, 10.3, 11, 11.6, 11.1, 9, 7.4, 6.3, 7, 7, 6.6, 5.6, 6, 6.6, 7.6,
	8, 8.6, 9, 9.3, 10, 10.2, 11, 11.5, 12.7, 13.6, 14.1, 15, 15, 15, 15};

const double wtb2006[134] = {0, 0, 0, 0, 0, 0.5, 1.5, 2, 2.8, 4.4, 5, 6.3, 7,
	7.8, 8.8, 10.3, 10.7, 11.8, 13.3, 14, 14.4, 16.5, 23.9, 19.8, 19, 20.7,
	21.4, 24.8, 26.5, 27.4, 25.5, 24, 25.9, 20.3, 21.8, 24.4, 30, 30.7, 31,
	31.5, 25.3, 27.9, 29.4, 19, 18.4, 18.4, 21.5, 24.5, 27.7, 27.2, 27.7,
	27.7, 27.3, 27.2, 27.7, 27.2, 27.3, 30.1, 33, 36.5, 41.6, 37.5, 39.3,
	41.5, 44, 45.8, 46.8, 44.5, 42, 43.8, 50.3, 54.6, 59.6, 62.4, 64.7,
	66.5, 62.1, 61.1, 57.2, 55.6, 45.5, 38, 35.3, 33.8, 31.3, 27.4, 21.3,
	16.7, 13.5, 8, 4, 1.4, 1, 1, 1, 1, 0.8, 0.7, 2.8, 1.2, 2.2, 3.3, 4.3,
	5.4, 6.4, 7.5, 8.5, 9.6, 10.6, 11.7, 12.8, 13.8, 14.9, 15.9, 17, 18,
	19.1, 20.1, 21.2, 22.2, 23.3, 22.3, 22.8, 21.2, 27.2, 29.5, 29.8, 29.6,
	25.2, 19, 19.3, 19.3, 17.4, 16.9};

const double wtb2007[105] = {14.7, 16.4, 21.3, 21.5, 21.6, 21.1, 20.6, 20.1,
	21.1, 19.4, 17.7, 16, 14.3, 12.5, 10.8, 9.1, 7.3, 5.5, 3.7, 1.8, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0.4, 0.9, 1.3, 1.7, 2.3, 2.9, 3.4, 3, 2.6,
	2.2, 1.8, 1.4, 1, 5.7, 5.7, 5.7, 5.6, 5.6, 7.1, 8.2, 9.3, 10.4, 11.5,
	12.7, 13.8, 14.9, 16, 17.6, 18.3, 19, 19.7, 20.3, 19.7, 19.4, 20.2,
	17.7, 15.1, 12.6, 10.1, 5.6, 1.1, 0.9, 0.8, 0.6, 0.5, 0.3, 0.2, 0, 0.1,
	0.2, 0.3, 0.4, 0.6, 0.7, 0.8, 0.9, 1, 0.7, 0.3, 0, 0.9, 1.8, 0.9, 0,
	0.9, 1.8, 2.7, 3.7, 4.6, 4.8, 5, 5.2, 5.4, 5.6};

const double wtb2008[77] = {19.1, 20.3, 21.5, 19.1, 16.7, 14.2, 11.8, 11.3,
	10.8, 10.3, 9.8, 9.6, 9.3, 9, 8.8, 8.5, 7.8, 7.1, 3.3, 2.8, 2.2, 1.7,
	1.1, 0.6, 0, 0, 0, 0, 0, 0, 2.9, 2.6, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8,
	1.4, 0, 0, 0, 0.1, 0.1, 0.1, 0.2, 1.1, 2, 1.2, 1.2, 1.3, 1.1, 1.7, 0.1,
	0.1, 0.1, 0.1, 0.1, 0, 1.4, 2.8, 4.2, 5.5, 6.9, 8.3, 9.6, 11, 12.4,
	13.8, 15.1, 18.5, 22, 25.4, 27.1, 27.7, 28.2, 28.6};

const double wtb2009[115] = {26.9, 26.4, 25.9, 25.8, 25.7, 25.4, 25, 24.7, 21,
	22.9, 20.5, 18.1, 19, 20, 20.9, 22.4, 17.3, 18.7, 12.8, 13.1, 13.4,
	13.7, 14, 7, 0, 19.8, 17.8, 15.9, 13.9, 21, 17.7, 22.5, 21.2, 19.8,
	18.5, 17.1, 15.8, 12.2, 8.6, 9.8, 9.8, 9.8, 9.8, 9.8, 8.9, 8.3, 12.6,
	3.8, 2, 1.6, 1.2, 0.8, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1.9, 2.9, 3.8, 4.8,
	5.7, 6.7, 7.6, 8.6};

const double wtb2010[116] = {11.9, 9.9, 11.7, 11.4, 9.7, 10.1, 11.5, 12.8, 13.7,
	14.6, 15.5, 16.5, 13.8, 13.9, 16.2, 18, 19.1, 20.3, 19.8, 12.2,
	14.5, 14.5, 12.8, 14.7, 16.2, 16.8, 14.8, 12.8, 13.9, 16, 18,
	20.1, 21.8, 22.7, 24.3, 25.2, 25.8, 20.7, 23.3, 24.1, 25.8,
	26.8, 25.2, 19.9, 20.7, 23.1, 25.2, 27.1, 28.4, 22.6, 25.8,
	28.1, 29.8, 31.6, 33.3, 35, 35.9, 36.3, 36.1, 34.2, 35.9, 36.4,
	36.5, 36.6, 36.5, 36.5, 35.7, 36.5, 36.6, 36.6, 36.5, 36.6,
	36.8, 36.8, 36.8, 36.8, 36.8, 36.8, 36.7, 36.8, 36.8, 26.9,
	26.4, 28.3, 29.2, 30.4, 31.4, 32.2, 32.5, 32.7, 33.3, 33.3,
	17.4, 17.6, 18.7, 19.6, 20.3, 20.8, 21.2, 21.6, 22.1, 22.5,
	23.1, 23.6, 24.1, 24.8, 25.4, 26.2, 27.3, 28.8, 30.2, 31.9,
	34.7, 36.1, 36.5, 36.5};

const double wtb2011[115] = {7.2, 8.1, 9.1, 9.4, 8.7, 5.8, 6.7, 7.8, 9, 10.4,
	8.5, 10, 11.5, 11.7, 7.3, 7.2, 7.1, 8.1, 9.2, 11, 13, 13.5, 14.8, 15.8,
	17.1, 18.6, 19.1, 14.8, 17.1, 14.2, 13.3, 12.8, 15.7, 17.6, 17.9, 16.6,
	18.5, 21.5, 24, 23.3, 18.2, 23, 26, 27.8, 29.1, 31.4, 33.2, 25.4, 26.5,
	27.3, 30, 32.9, 34.9, 35.8, 36.2, 36.4, 36.4, 36.3, 30.5, 33.2, 35.8,
	34.1, 34.4, 36, 36.5, 36.5, 36.6, 36.6, 36.6, 36.5, 36.5, 36.5, 36.6,
	36.5, 35.8, 35.4, 35.8, 36, 36.1, 36.1, 36, 36, 36, 26.4, 24.9, 26.2,
	28.5, 30.7, 32.2, 33.9, 35.5, 36.2, 36.4, 36.3, 35.6, 36, 36.3, 36.4,
	36.5, 36.5, 36.5, 36.5, 36.5, 34.9, 30.9, 33.3, 34.8, 36, 36.4, 36.4,
	36.5, 36.6, 36.7, 36.7, 36.7};

#endif

#ifdef LOWERED
const double wtb2005[116] = {10, 10, 11, 12, 12.5, 13.9, 15.3, 16.3, 16.8, 18,
	16.8, 15.1, 17.4, 14.1, 13.1, 12.8, 12, 13, 13.8, 14, 15.3, 16.6, 17.5,
	18.4, 9.8, 5.1, 2.2, 1.6, 1, 1, 1.2, 2, 2.4, 3.2, 4, 4.8, 4.5, 5, 5,
	5.7, 6, 6.3, 7, 7, 7.3, 7.5, 7.6, 8, 8.4, 9, 9, 9.4, 10.1, 11, 11, 12,
	12.4, 13, 13, 13.2, 14, 15, 15.3, 16.1, 17, 17, 16.3, 17.8, 18.8, 19,
	19.3, 20, 20, 21, 20.3, 17.8, 16.8, 17, 17, 17.2, 18, 18.9, 19.3, 20,
	20, 20.5, 20.2, 18.3, 19.6, 20, 19.3, 17.7, 15.1, 13.8, 15, 14.8, 14.1,
	12.5, 13, 13.6, 14, 14, 14.9, 15, 15.7, 16.3, 17, 17.2, 18.1, 19.8,
	20.8, 21.7, 22.8, 22.7, 23, 23};

const double wtb2006[134] = {1, 1, 1, 1, 1, 2, 2, 3.1, 4.1, 5.2, 6.3, 7.3,
	8.4, 9.5, 10.5, 11.6, 12.7, 13.7, 14.8, 15.9, 16.9, 18, 19.9, 21.8,
	23.6, 25.5, 27.4, 29.3, 31.1, 33, 34.9, 36.8, 38.6, 40.5, 42.4, 44.3,
	45.7, 46.8, 45.8, 45.9, 40.3, 41.5, 44.1, 34.5, 34.5, 32.8, 37.3, 35.7,
	40.2, 44.5, 44, 42.5, 41, 41.4, 39.4, 40.8, 42.6, 35.6, 44, 51.1, 57.6,
	57.5, 57.4, 57.4, 57.3, 57.3, 57.2, 57.1, 57.1, 57, 55.3, 53.6, 51.8,
	50.1, 48.4, 46.7, 42.2, 38, 34.2, 35.2, 34.3, 30.4, 30.5, 31.3, 31.4,
	31.1, 28.3, 24.4, 24.2, 22.2, 18.5, 17, 16.2, 15.9, 15.8, 14.8, 15,
	14.7, 15.3, 15.8, 15.8, 15.8, 16, 15.8, 15.9, 17.1, 18.3, 19.5, 18.3,
	18.4, 19.1, 19.4, 20, 21.3, 22.8, 23.8, 24.5, 25.4, 25.6, 29.9, 29.7,
	33.5, 33.4, 33.9, 31.4, 31.6, 30.8, 30.5, 29.6, 27.2, 29.9, 27.4, 26.7,
	26};

const double wtb2007[105] = {21.6, 21.6, 21.6, 21.6, 21.6, 21.2, 20.8, 20.3,
	19.4, 18.4, 17.4, 16.3, 15.3, 14.3, 13.3, 12.2, 9.8, 7.3, 4.9, 2.4, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1, 0.2, 0.3, 0.5, 1.7, 2.9, 4.2, 4.5,
	4.9, 5.2, 5.6, 5.9, 6.3, 7.1, 6.1, 5.1, 4.1, 3.2, 3, 3, 3, 2.9, 2.9,
	2.9, 2.9, 2.9, 2.9, 7.1, 8.2, 9.4, 10.5, 11.6, 13.2, 16.1, 19, 18.3,
	17.6, 16.8, 16.1, 10.5, 4.8, 4.1, 3.4, 2.7, 2.1, 1.4, 0.7, 0, 0.3, 0.6,
	1, 1.3, 1.6, 1.9, 2.3, 2.6, 2.9, 1.9, 1, 0, 2.8, 5.7, 2.8, 0, 2.1, 4.2,
	6.3, 8.4, 10.5, 10.9, 11.2, 11.5, 11.9, 12.2};

const double wtb2008[77] = {21.3, 21.9, 22.4, 21.5, 20.6, 19.6, 18.7, 16.8,
	14.8, 12.9, 11, 11.2, 11.4, 11.5, 11.7, 11.9, 8.8, 5.7, 4.7, 4.2, 3.7,
	3.2, 2.7, 2.2, 1.7, 1.7, 1.7, 1.7, 1.7, 1.7, 2, 3.4, 4.8, 4.7, 4.7,
	4.6, 4.6, 4.6, 4.8, 5.1, 2.7, 2.9, 3.2, 3.5, 3.8, 4, 4, 4, 2.3, 2.2,
	2.1, 2, 1.3, 3.4, 2.7, 2, 1.3, 0.7, 0, 1.3, 2.6, 3.9, 5.2, 6.5, 7.9,
	9.2, 10.5, 11.8, 13.1, 14.4, 18.1, 21.7, 25.4, 27.6, 28.6, 30.3, 32.1};

const double wtb2009[106] = {29, 29.1, 29.1, 27.2, 25.2, 24.5, 23.8, 23.2,
	22.8, 22.7, 20.9, 19.1, 20.2, 21.2, 22.2, 19.8, 20.6, 19, 17.9, 18.3,
	18.6, 18.9, 19.3, 20.7, 22.1, 15.9, 17.8, 19.7, 21.7, 21.2, 21.2, 22.7,
	21.6, 20.5, 19.4, 18.3, 17.2, 8.9, 15.9, 14.9, 13.5, 12, 10.6, 9.1,
	11.4, 10.2, 8.4, 8.8, 9.2, 8, 7.1, 6.1, 5.1, 4.2, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const double wtb2010[106] = {26.8, 23, 28.7, 27.3, 23.3, 26.3, 29.7, 31.3,
	31.5, 31.9, 32.3, 33, 28.2, 30.1, 32.8, 34.4, 35.1, 35.8, 34.3, 25.4,
	32, 30.9, 28.2, 33.1, 34.8, 34.2, 31.7, 28.1, 32.4, 35.2, 36.3, 37.1,
	37.5, 37.2, 38.4, 38, 38.1, 33.2, 36.4, 36.2, 37.2, 37.2, 35.3, 30.2,
	32.2, 33.4, 34.2, 35.2, 35.8, 31.2, 34, 34.9, 35.8, 37.2, 38.8, 40.2,
	41.1, 41.6, 41.4, 38.4, 39.5, 40.2, 40.5, 40.9, 41, 41.4, 38.8, 40.3,
	41.3, 42.1, 41.8, 41.8, 42.3, 42.5, 42.9, 43, 43.8, 44.4, 44.6, 44.9,
	45.4, 30.8, 33.5, 34.5, 34.5, 35, 35.5, 36, 36, 36.2, 36.7, 36.4, 22.6,
	26.5, 29.3, 30.5, 30.9, 31, 31.1, 31.3, 31.4, 31.5, 31.7, 31.7, 31.9,
	32.4};

const double wtb2011[111] = {10.6, 14.4, 21.5, 24.9, 24.3, 24.2, 20.9, 21.8,
	22.7, 22.1, 16.9, 17.7, 18.1, 19.7, 20.8, 22.5, 23.8, 23.5, 24.3, 24.7,
	25.5, 26.7, 26.4, 22.6, 24.5, 21.2, 22.5, 22.4, 24.9, 25.6, 25.5, 24.1,
	25.8, 27.3, 28.7, 27.5, 24.5, 27.8, 29.1, 30.1, 30.9, 32.3, 33.4, 27.6,
	29.6, 29.3, 31.1, 40.9, 47.5, 47.2, 47.3, 47.4, 47.7, 46.1, 43.9, 46.6,
	46.1, 45.4, 45.2, 46.8, 47.4, 47.5, 47.9, 47.6, 48.1, 47.7, 48.9, 48.1,
	49.2, 49.1, 49.1, 45.8, 49.9, 48.1, 48.1, 48.7, 48.4, 49.1, 48.7, 33.7,
	42.2, 39.7, 39, 41.1, 42.7, 44.3, 46, 46.7, 47.2, 46.5, 45.8, 47.8,
	46.5, 46.6, 46.7, 47.2, 46.9, 46.7, 46.3, 45.2, 45.2, 44.7, 45.2, 46.1,
	46.5, 46.9, 46.9, 46.9, 47.5, 47.5, 47.4};

#endif

#ifdef RAISED
const double wtb2005[79] = { 9.9, 5.1, 4.5, 3.7, 3.9, 3.4, 2.2, 3, 1, 1, 0, 0,
		0, 0, 0, 0, 0.5, 1, 1.5, 2, 1.5, 0.7, 0.3, 1.1, 2.7, 3.7, 3.8, 3.2,
		2.1, 4.2, 6.3, 7.1, 7.1, 6.5, 5.3, 6.8, 6.3, 7.2, 8.7, 9.8, 8.3, 5.4,
		7.5, 8.6, 9.9, 9.9, 10.5, 11.5, 10.7, 8.2, 5.8, 5.2, 5, 5.5, 6.1, 6.9,
		7, 7.1, 7.9, 8.3, 7.9, 5, 5.7, 6, 5.3, 3, 1.7, 0.5, 0.7, 0.5, 0.3, 0,
		1, 2, 3, 3.1, 3.2, 3, 3.60 };

const double wtb2006[134] = { 1, 1, 1.8, 2.6, 3.4, 4.2, 5, 5.1, 5.1, 5.2, 5.3,
		5.3, 5.4, 5.5, 5.5, 5.6, 5.7, 5.7, 5.8, 5.9, 5.9, 6, 6, 6, 6, 6, 6,
		6.9, 7.7, 8.6, 9.4, 10.3, 11.1, 12, 12.8, 13.7, 14.5, 15.9, 16.7, 17.3,
		13.7, 12.3, 12.4, 5.5, 5.4, 4.8, 4.5, 5.5, 8.3, 10.1, 0, 15.5, 16.5,
		15.3, 16.8, 19.5, 17.1, 17.3, 17.7, 18.8, 21.5, 17.3, 19.6, 22.3, 25.5,
		27.8, 29.3, 27.5, 25.6, 23.6, 22.5, 26.1, 30, 31.8, 33.5, 34.3, 29.1,
		28.4, 28.3, 29, 21.5, 16.8, 16.3, 17.3, 17.3, 16.1, 12.5, 10.5, 9.7,
		6.9, 5.4, 5, 5, 5, 5, 5, 5.2, 6, 6, 6, 6.3, 6.9, 7.1, 7.3, 8, 8, 8,
		8.4, 9, 9.7, 10.2, 11, 11, 11, 11.3, 12, 12.5, 12.4, 13, 13.3, 14, 14,
		13.7, 14, 15, 15, 15, 15, 12.8, 9.5, 10.5, 11, 11, 11.20 };

const double wtb2007[105] = { 14.7, 15.6, 0, 9.4, 18.8, 19.4, 20, 20.6, 19.9,
		17.6, 15.3, 13, 10.7, 8.4, 6, 3.7, 3, 2.2, 1.5, 0.7, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 2.2, 3.3, 3.2, 3.1, 2.9, 2.8, 2.6, 2.5,
		0, 0.2, 0.5, 0.7, 0.9, 0.9, 1.7, 2.6, 3.5, 4.3, 5.2, 6, 6.9, 7.8, 4.5,
		4.7, 5, 5.2, 5.5, 2.1, 0.1, 0.8, 0.6, 0.5, 0.3, 0.1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.4, 0.9, 1.3,
		1.8, 2.2, 2.2, 2.1, 2.1, 2, 2 };

const double wtb2008[77] = { 11.2, 11.5, 11.4, 11.3, 11.2, 11.1, 9.9, 8.6, 7.4,
		6.2, 5.8, 5.4, 5, 4.6, 4.2, 3.4, 2.6, 1.8, 1.7, 1.6, 1.5, 1.4, 1.3,
		1.2, 1.5, 1.7, 2, 2.3, 2.5, 5.3, 6.9, 8.4, 7.8, 7.1, 6.5, 5.8, 5.2,
		3.2, 1.3, 4.8, 4.6, 4.5, 4.3, 4.2, 4, 4.4, 4.7, 4.3, 4, 3.7, 3.4, 2.3,
		5, 5.1, 5.1, 5.2, 5.2, 5.3, 5.6, 6, 6.4, 6.7, 7.1, 7.4, 7.8, 8.2, 8.5,
		8.9, 9.3, 12.1, 14.8, 17.6, 20, 22.2, 22.2, 22.3 };

const double wtb2009[106] = { 21.1, 20.1, 19, 17.9, 16.9, 16.4, 15.9, 15.4,
		13.2, 13.4, 12.5, 11.7, 12.6, 13.5, 14.4, 12.2, 12.6, 11, 11.4, 11.8,
		12.2, 12.6, 13, 15.2, 17.3, 13.5, 13.7, 13.9, 14.1, 11.6, 13.5, 13.6,
		11.9, 10.2, 8.5, 6.9, 5.2, 16.1, 8.2, 8.1, 7.8, 7.6, 7.4, 7.1, 0, 4.1,
		7.6, 5, 2.3, 1.5, 1.1, 0.7, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const double wtb2010[106] = { 6.2, 5.3, 6.7, 7.4, 6.3, 7, 8.3, 9.4, 10.3, 10.9,
		11.8, 12.7, 10.9, 11, 12.9, 12.4, 8.4, 9.8, 10.3, 6.6, 8.3, 8.4, 6.6,
		7.9, 8.9, 10.9, 10.6, 9.4, 10.3, 12.1, 13.4, 14.8, 16.1, 16.9, 18.2,
		18.8, 17.2, 10.8, 13.1, 14, 15.5, 16.5, 14.9, 11.7, 11.1, 12.9, 15,
		16.8, 17.9, 13.2, 15.4, 17.7, 19.5, 21, 22.4, 23.7, 24.8, 25.7, 25.3,
		23.1, 24.5, 26, 26.4, 26.2, 26.2, 26.1, 22.2, 25.4, 26.5, 26.7, 26.6,
		26.7, 26.9, 27.8, 28.6, 29.4, 30.6, 31.2, 31.7, 32.1, 32.6, 19.5, 16.7,
		18.1, 18.8, 20.1, 20.9, 21.9, 22.4, 22.6, 23.3, 23.5, 11.4, 10.9, 11.9,
		13, 14, 14.9, 15.6, 16.2, 16.9, 17.7, 17.9, 18.2, 19.3, 20.2 };

const double wtb2011[111] = { 6.4, 6.1, 6.7, 8.4, 10.2, 11.5, 10, 11.3, 12.6,
		12.6, 8.9, 9.1, 8.9, 9.8, 6.9, 4.6, 7.2, 8.2, 9.4, 10.1, 11, 12, 11.7,
		8, 9.4, 7.3, 7.1, 6.8, 8.6, 9.6, 9.9, 9, 10.3, 12.2, 13.8, 13.3, 10,
		12.9, 14.4, 15.6, 16.5, 17.7, 18.8, 13.6, 14.4, 14.7, 16, 17.7, 19.4,
		20.8, 22, 23.1, 23.7, 23.3, 16.3, 18.4, 20.2, 18.7, 19.1, 20.8, 22.7,
		23.8, 25, 26.1, 26.3, 25.7, 26.2, 25.6, 26.2, 26, 26.1, 22.1, 22.3,
		24.4, 25.8, 25.9, 25.8, 26.1, 27.3, 13.8, 13.1, 13.9, 15.7, 17.1, 18.2,
		19.4, 20.5, 21.3, 21.9, 22.4, 20.8, 20.7, 21.6, 22.3, 23, 23.5, 24.6,
		25.4, 25.4, 19.9, 16, 17.1, 17.9, 19, 19.5, 20, 20.4, 21, 21.5, 21.5,
		21.9 };

#endif
#endif

#ifdef BOG
#endif

class Soil_Env {
public:
	Soil_Env();
	~Soil_Env();

	/*! the thickness of soil column , which is from the the top
	 * of moss layer, if exists, to the bottom of last mineral layer.(unit: m)*/
	double dztot;
	/*! number of soil layers */
	int num;
	double initem[MAX_SOI_LAY];
	double inivwc[MAX_SOI_LAY];

	/*! reset diagnostic variables to initial values */
	void resetDiagnostic();

	Moss moss;
	Peat peat;
	Mineral mineral;

	Richard richard;
	Stefan stefan;

	void setEnvData(EnvData* edp);
	void setFirData(FirData* fdp);
	void setCohortLookup(CohortLookup * chtlup);

	void updateDailySurfFlux(Layer* frontl, const double & tsurf,
			const double & dayl);

	double getWaterTable(Layer* fstsoil, const int year, const int doy);

	void initializeParameter(const int &drgtypep, const int &vegtypep);
	void initializeState(Layer* fstsoill);
	void initializeState5restart(Layer* fstsoill, RestartData* resin);

	double infilFrozen2(Layer* fstsoill, Layer *fstminl, const double & rnth,
			const double & melt);

	double infilFrozen(Layer* fstminl, const double & infilf);

	double getDrainage(const double & wtable);
	double getRunoff(Layer* fstsoill, const double & rnth, const double & melt,
			const double & frasat);
	double update5Drainage(Layer* drainl, const double & fracsat,
			const double & wtd);

	double getSoilTransFactor(Layer* fstsoill);

	double update5BaseFlow(Layer* drainl);

	double getBaseFlow(double const & wetness);

	double getRunoffVIC(Layer* fstsoill, const double & rnth,
			const double & melt);

	///////////////////
	void layer2structdaily(Layer* fstsoill);
	void layer2structmonthly(Layer* fstsoill);
	void retrieveDailyOutputs(Layer* fstsoill, Layer* fstminl, Layer* lstminl,
			Layer* backl);
	void retrieveDailyFronts(Layer* fstsoill);
	void retrieveThawPercent(Layer* fstsoill);

	//////////////////////

	void resetFineRootFrac(Layer* fstsoill);
	void resetTypeDZ(Layer* fstsoill);
	soipar_env envpar;

	double getFracSat(const double & wtd);

private:

	double getEvaporation(const double & tsurf, const double & dayl,
			const double &rad);

	double getPenMonET(const double & ta, const double& vpd,
			const double &irad, const double &rv, const double & rh);
	double updateLayerTemp5Lat(Layer* currl, const double & infil);

	double getFineRootFrac(const double & layertop, const double & layerbot,
			const double & mossthick);

	EnvData * ed;
	FirData * fd;

	CohortLookup* chtlu;

	void initTempMois(Layer* frontl);
	void initRootMass(Layer* fstsoill);
};

#endif /*SOIL_ENV_H_*/
