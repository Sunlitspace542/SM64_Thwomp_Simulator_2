// thwomp.c.inc

void grindel_thwomp_act_4(void) {
    if (o->oTimer == 0)
        o->oThwompUnkF4 = 10.0f;
    if (o->oTimer > o->oThwompUnkF4)
        o->oAction = 0;
}

void grindel_thwomp_act_2(void) {
    o->oVelY += -200.0f;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oVelY = 0;
        o->oAction = 3;
    }
}

void grindel_thwomp_act_3(void) {
    if (o->oTimer == 0){
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
        }
    if (o->oTimer > 9)
        o->oAction = 4;
}

void grindel_thwomp_act_1(void) {
    // if (o->oTimer == 0)
        // o->oThwompUnkF4 = random_float() * 30.0f + 10.0f;
    if (gPlayer1Controller->buttonPressed & A_BUTTON)
        o->oAction = 2;
    if (gPlayer1Controller->buttonPressed & B_BUTTON)
        o->oAction = 2;
    if (gPlayer1Controller->buttonPressed & Z_TRIG)
        o->oAction = 2;
}

void grindel_thwomp_act_0(void) {
    if (o->oBehParams2ndByte + 5 < o->oTimer) {
        o->oAction = 1;
        o->oPosY += 5.0f;
    } else
        o->oPosY += 80.0f;
}

void (*sGrindelThwompActions[])(void) = { grindel_thwomp_act_0, grindel_thwomp_act_1,
                                          grindel_thwomp_act_2, grindel_thwomp_act_3,
                                          grindel_thwomp_act_4 };

void bhv_grindel_thwomp_loop(void) {
    cur_obj_call_action_function(sGrindelThwompActions);
}
