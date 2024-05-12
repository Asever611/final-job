#ifndef CONFIG_H
#define CONFIG_H

//游戏
#define GAME_WIDTH 864 //宽度
#define GAME_HEIGHT 512 //高度
#define GAME_TITLE "FlaggyBird v1.0" //标题
#define GAME_RES_PATH "./bird.rcc" //rcc文件路径                //
#define GAME_ICON  ":/res/favicon.ico"              //

//背景
#define STARTMAP_PATH ":/image/text_ready.png"
#define MAP1_PATH ":/image/bg_day.png"
#define MAP2_PATH ":/image/bg_night.png"
#define GAME_RATE 10 //帧率 ms
//#define bgm ":/res/BGM.wav"

//地基
#define BASE_PATH ":/image/land.png"
#define BASE_SPEED 1
#define BASE_Y 470

//小鸟
#define BIRD_UP_PATH ":/image/bird1_0.png"
#define BIRD_MID_PATH ":/image/bird1_1.png"
#define BIRD_DOWN_PATH ":/image/bird1_2.png"
#define BIRD_DOWN_SPEED 6
#define BIRD_UP_SPEED 60
#define BIRD_FLAP1_SOUND "qrc:/image/fly1.m4a"
#define BIRD_FLAP2_SOUND "qrc:/image/fly1.m4a"
#define BIRD_DEAD_SPEED 9
#define BIRD_DEAD_PATH ":/image/bird1_0.png"
#define BIRD_DROP_SOUND "qrc:/image/die.wav"
#define BIRD_SCORE_SOUND "qrc:/image/score1.m4a"

//管道
#define TUBE_SPEED 1
#define TUBE_PATH ":/image/pipe_up.png"
#define TUBE_PATH2 ":/image/pipe_down.png"
#define TUBE_INTERVAL 220
#define TUBE_NUM 50

//死亡
#define GAMEOVER_PATH ":/image/text_game_over.png"
#define CRASH_PATH "qrc:/image/die.wav"

//得分
#define S_0 ":/image/number_score_00.png"
#define S_1 ":/image/number_score_01.png"
#define S_2 ":/image/number_score_02.png"
#define S_3 ":/image/number_score_03.png"
#define S_4 ":/image/number_score_04.png"
#define S_5 ":/image/number_score_05.png"
#define S_6 ":/image/number_score_06.png"
#define S_7 ":/image/number_score_07.png"
#define S_8 ":/image/number_score_08.png"
#define S_9 ":/image/number_score_09.png"

#endif // CONFIG_H
