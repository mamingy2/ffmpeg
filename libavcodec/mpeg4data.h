// shapes
#define RECT_SHAPE       0
#define BIN_SHAPE        1
#define BIN_ONLY_SHAPE   2
#define GRAY_SHAPE       3

// aspect_ratio_info
#define EXTENDET_PAR 15

//vol_sprite_usage / sprite_enable
#define STATIC_SPRITE 1
#define GMC_SPRITE 2

/* dc encoding for mpeg4 */
const UINT8 DCtab_lum[13][2] =
{
    {3,3}, {3,2}, {2,2}, {2,3}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7},
    {1,8}, {1,9}, {1,10}, {1,11},
}; 

const UINT8 DCtab_chrom[13][2] =
{
    {3,2}, {2,2}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {1,8},
    {1,9}, {1,10}, {1,11}, {1,12},
}; 

const UINT16 intra_vlc[103][2] = {
{ 0x2, 2 },
{ 0x6, 3 },{ 0xf, 4 },{ 0xd, 5 },{ 0xc, 5 },
{ 0x15, 6 },{ 0x13, 6 },{ 0x12, 6 },{ 0x17, 7 },
{ 0x1f, 8 },{ 0x1e, 8 },{ 0x1d, 8 },{ 0x25, 9 },
{ 0x24, 9 },{ 0x23, 9 },{ 0x21, 9 },{ 0x21, 10 },
{ 0x20, 10 },{ 0xf, 10 },{ 0xe, 10 },{ 0x7, 11 },
{ 0x6, 11 },{ 0x20, 11 },{ 0x21, 11 },{ 0x50, 12 },
{ 0x51, 12 },{ 0x52, 12 },{ 0xe, 4 },{ 0x14, 6 },
{ 0x16, 7 },{ 0x1c, 8 },{ 0x20, 9 },{ 0x1f, 9 },
{ 0xd, 10 },{ 0x22, 11 },{ 0x53, 12 },{ 0x55, 12 },
{ 0xb, 5 },{ 0x15, 7 },{ 0x1e, 9 },{ 0xc, 10 },
{ 0x56, 12 },{ 0x11, 6 },{ 0x1b, 8 },{ 0x1d, 9 },
{ 0xb, 10 },{ 0x10, 6 },{ 0x22, 9 },{ 0xa, 10 },
{ 0xd, 6 },{ 0x1c, 9 },{ 0x8, 10 },{ 0x12, 7 },
{ 0x1b, 9 },{ 0x54, 12 },{ 0x14, 7 },{ 0x1a, 9 },
{ 0x57, 12 },{ 0x19, 8 },{ 0x9, 10 },{ 0x18, 8 },
{ 0x23, 11 },{ 0x17, 8 },{ 0x19, 9 },{ 0x18, 9 },
{ 0x7, 10 },{ 0x58, 12 },{ 0x7, 4 },{ 0xc, 6 },
{ 0x16, 8 },{ 0x17, 9 },{ 0x6, 10 },{ 0x5, 11 },
{ 0x4, 11 },{ 0x59, 12 },{ 0xf, 6 },{ 0x16, 9 },
{ 0x5, 10 },{ 0xe, 6 },{ 0x4, 10 },{ 0x11, 7 },
{ 0x24, 11 },{ 0x10, 7 },{ 0x25, 11 },{ 0x13, 7 },
{ 0x5a, 12 },{ 0x15, 8 },{ 0x5b, 12 },{ 0x14, 8 },
{ 0x13, 8 },{ 0x1a, 8 },{ 0x15, 9 },{ 0x14, 9 },
{ 0x13, 9 },{ 0x12, 9 },{ 0x11, 9 },{ 0x26, 11 },
{ 0x27, 11 },{ 0x5c, 12 },{ 0x5d, 12 },{ 0x5e, 12 },
{ 0x5f, 12 },{ 0x3, 7 },
};

const INT8 intra_level[102] = {
  1,  2,  3,  4,  5,  6,  7,  8,
  9, 10, 11, 12, 13, 14, 15, 16,
 17, 18, 19, 20, 21, 22, 23, 24,
 25, 26, 27,  1,  2,  3,  4,  5,
  6,  7,  8,  9, 10,  1,  2,  3,
  4,  5,  1,  2,  3,  4,  1,  2,
  3,  1,  2,  3,  1,  2,  3,  1,
  2,  3,  1,  2,  1,  2,  1,  1,
  1,  1,  1,  1,  2,  3,  4,  5,
  6,  7,  8,  1,  2,  3,  1,  2,
  1,  2,  1,  2,  1,  2,  1,  2,
  1,  1,  1,  1,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,
};

const INT8 intra_run[102] = {
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  1,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  2,  2,  2,
  2,  2,  3,  3,  3,  3,  4,  4,
  4,  5,  5,  5,  6,  6,  6,  7,
  7,  7,  8,  8,  9,  9, 10, 11,
 12, 13, 14,  0,  0,  0,  0,  0,
  0,  0,  0,  1,  1,  1,  2,  2,
  3,  3,  4,  4,  5,  5,  6,  6,
  7,  8,  9, 10, 11, 12, 13, 14,
 15, 16, 17, 18, 19, 20,
};

static RLTable rl_intra = {
    102,
    67,
    intra_vlc,
    intra_run,
    intra_level,
};

static const UINT16 sprite_trajectory_tab[15][2] = {
 {0x00, 2}, {0x02, 3},  {0x03, 3},  {0x04, 3}, {0x05, 3}, {0x06, 3},
 {0x0E, 4}, {0x1E, 5},  {0x3E, 6},  {0x7E, 7}, {0xFE, 8}, 
 {0x1FE, 9},{0x3FE, 10},{0x7FE, 11},{0xFFE, 12},
};

static const UINT8 mb_type_b_tab[4][2] = {
 {1, 1}, {1, 2}, {1, 3}, {1, 4},
};

static const UINT16 pixel_aspect[16][2]={
 {0, 0},
 {1, 1},
 {12, 11},
 {10, 11},
 {16, 11},
 {40, 33},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
 {0, 0},
};

/* these matrixes will be permuted for the idct */
INT16 ff_mpeg4_default_intra_matrix[64] = {
  8, 17, 18, 19, 21, 23, 25, 27,
 17, 18, 19, 21, 23, 25, 27, 28,
 20, 21, 22, 23, 24, 26, 28, 30,
 21, 22, 23, 24, 26, 28, 30, 32,
 22, 23, 24, 26, 28, 30, 32, 35,
 23, 24, 26, 28, 30, 32, 35, 38,
 25, 26, 28, 30, 32, 35, 38, 41,
 27, 28, 30, 32, 35, 38, 41, 45, 
};

INT16 ff_mpeg4_default_non_intra_matrix[64] = {
 16, 17, 18, 19, 20, 21, 22, 23,
 17, 18, 19, 20, 21, 22, 23, 24,
 18, 19, 20, 21, 22, 23, 24, 25,
 19, 20, 21, 22, 23, 24, 26, 27,
 20, 21, 22, 23, 25, 26, 27, 28,
 21, 22, 23, 24, 26, 27, 28, 30,
 22, 23, 24, 26, 27, 28, 30, 31,
 23, 24, 25, 27, 28, 30, 31, 33,
};

