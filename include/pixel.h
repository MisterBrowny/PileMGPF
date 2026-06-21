#ifndef PIXEL_H
#define	PIXEL_H

#define PIXEL_NUM_STATE         0


#define DEF_COLOR_UNDER_30V_R   30
#define DEF_COLOR_UNDER_30V_G   0
#define DEF_COLOR_UNDER_30V_B   0

#define DEF_COLOR_UNDER_3V_R    25
#define DEF_COLOR_UNDER_3V_G    5
#define DEF_COLOR_UNDER_3V_B    0

#define DEF_COLOR_OK_R          0
#define DEF_COLOR_OK_G          30
#define DEF_COLOR_OK_B          0

void pixel_init (void);
void pixel_set_default (void);
void pixel_set (uint8_t numpixel, uint8_t red, uint8_t green, uint8_t blue);

#endif	/* PIXEL_H */

