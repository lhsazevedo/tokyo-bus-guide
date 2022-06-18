#include "includes.h"

extern void _8c051618();
extern boolean getUknPvmBool_8c01432a();
extern void _8c011f7e();
extern void _8c01940e();
extern void push_fadein_8c015b5c();
extern void _8c05738a();
extern int _8c0fcd28;
extern int is_fading_8c226568;
extern void drawSprite_8c014f54(void *r4, int r5, float fr4, float fr5, float fr6);
extern void push_fadeout_8c015b60();

struct MenuState {
    void *field_0x00;
    void *field_0x04;
    void *field_0x08;
    DrawDatStruct1 *drawdatstruct1_0x0c;
    void *field_0x10;
    void *field_0x14;
    int mode_0x18;
    int field_0x1c;
    float field_0x20;
    float field_0x24;
    // ...
    int logo_timer_0x68;
}
typedef MenuState;

MenuState menu_state_8c1bc7a8;

struct UknMenuStruct1  {
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
}
typedef UknMenuStruct1;

UknMenuStruct1 _8c1ba35c;

void task_title_8c015ab8(Task *task, void *state) {
    // r12 = 0x8c226568
    // fr12 = -4.5
    // fr13 = -4.0
    // fr14 = -5.0
    // fr15 = 0

    int m = menu_state_8c1bc7a8.mode_0x18;

    if (m >= 0xb && m < 0xc && _8c1ba35c.field_0x10 != 8) {
        _8c051618(_8c0fcd28, 1, 0, 0);

        _8c1ba35c.field_0x10 = 0;
        menu_state_8c1bc7a8.mode_0x18 = 0xe;
        is_fading_8c226568 = 0;
    }

    switch (menu_state_8c1bc7a8.mode_0x18) {
        case 0x00:
            if (getUknPvmBool_8c01432a()) {
                _8c011f7e();
                _8c01940e();

                if (task->field_0x08 != 0) {
                    // 0x8c015bd8
                    menu_state_8c1bc7a8.mode_0x18 = 0x0d;

                    push_fadein_8c015b5c(0xa);

                    // 0x8c015c84
                    _8c05738a(-1, -1, -1);
                } else {
                    // 0x8c015baa
                    menu_state_8c1bc7a8.mode_0x18 = 0x01;

                    push_fadein_8c015b5c(20);

                    _8c05738a(0xff000000, 0xff000000, 0xff000000);
                }
            }

            return;

        case 0x01:
            // FORTYFIVE FADE IN
            // 0x8c015be4

            if (is_fading_8c226568 == 0) {
                menu_state_8c1bc7a8.mode_0x18 = 0x02;
                menu_state_8c1bc7a8.logo_timer_0x68 = 0;
            }

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 0, 0.0, 0.0, -5.0);
            return;

        case 0x02:
            // FORTYFIVE
            // 0x8c015bf4
            // r4 = 0x1e

            menu_state_8c1bc7a8.logo_timer_0x68++;

            if (menu_state_8c1bc7a8.logo_timer_0x68 > 0x1e) {
                menu_state_8c1bc7a8.mode_0x18 = 0x03;
                push_fadeout_8c015b60(20);
            }

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 0, 0.0, 0.0, -5.0);
            return;

        case 0x03:
            // FORTYFIVE FADE OUT
            // 08c015c0c

            if (is_fading_8c226568 == 0) {
                drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 0, 0.0, 0.0, -5.0);
            } else {
                menu_state_8c1bc7a8.mode_0x18 = 0x04;

                push_fadein_8c015b5c(20);
            }

            return;

        case 0x04:
            // ADX FADE IN
            // 0x8c015c1e

            if (is_fading_8c226568 == 0) {
                menu_state_8c1bc7a8.mode_0x18 = 0x05;
                menu_state_8c1bc7a8.logo_timer_0x68 = 0;
            }

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 3, 0.0, 0.0, -5.0);
            return;

        case 0x05:
            // ADX
            
            menu_state_8c1bc7a8.logo_timer_0x68++;

            if (menu_state_8c1bc7a8.logo_timer_0x68 > 0x1e) {
                menu_state_8c1bc7a8.mode_0x18 = 0x06;
                push_fadeout_8c015b60(20);
            }

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 3, 0.0, 0.0, -5.0);

            break;

        case 0x06:
            // ADX FADE OUT
            
            if (is_fading_8c226568 == 0) {
                drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 0, 0.0, 0.0, -5.0);
            } else {
                // VMU Check?
                if (_8c012984() == 0 || _8c019550("TOKYOBUS.001", 3) != 0) {
                    menu_state_8c1bc7a8.mode_0x18 = 0xa;
                } else {
                    menu_state_8c1bc7a8.mode_0x18 = 0x7;
                }

                push_fadein_8c015b5c(10);
            }

            break;

        case 0x07:
            // VMU WARNING FADE IN
            // ...
            break;

        case 0x08:
            // VMU WARNING
            // ...
            break;

        case 0x09:
            // VMU WARNING FADE OUT
            // ...
            break;

        case 0x0a:
            // TITLE FADE IN

            if (is_fading_8c226568 == 0) {
                menu_state_8c1bc7a8.mode_0x18 = 0x0b;

                menu_state_8c1bc7a8.field_0x20 = 640;

                _8c010cd6(0, 0);
            }

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 2, 0.0, 0.0, -5.0);

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 46, 0.0, 0.0, -7.0);

            break;

        case 0x0b:
            // BUS SLIDE

            menu_state_8c1bc7a8.field_0x20 -= 5.11111;

            if (menu_state_8c1bc7a8.field_0x20 > 180) {
                // drawSprite_8c014f54();

                // ...
                break;
            } else {
                menu_state_8c1bc7a8.mode_0x18 = 0x0c;

                menu_state_8c1bc7a8.field_0x24 = 167.0;
            }

            // Missing break?

        case 0x0c:
            // FLAG REVEAL

            menu_state_8c1bc7a8.field_0x24 -= 2.33333;

            if (menu_state_8c1bc7a8.field_0x24 <= 97) {
                menu_state_8c1bc7a8.mode_0x18 = 0x0e;
            }

            drawSprite_8c014f54(&menu_state_8c1bc7a8.drawdatstruct1_0x0c, 4, 302, menu_state_8c1bc7a8.field_0x24, -4.5);

            // drawSprite_8c014f54(...);

            // drawSprite_8c014f54(...);

            break;

        case 0x0d:
            // ?

            // drawSprite_8c014f54(...) x 4
            break;

        case 0x0e:
            // ...
            break;

        case 0x0f:
            break;

        case 0x10:
            break;

        case 0x11:
            break;

        case 0x12:
            break;
    }
}