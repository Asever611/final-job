#include "bird.h"
#include"config.h"

Bird::Bird()
{
    birdmap.load(BIRD_UP_PATH);
    m_x=GAME_WIDTH *0.1;
    m_y=GAME_HEIGHT*0.5;
    rec.setWidth(birdmap.width());
    rec.setHeight(birdmap.height());
    rec.moveTo(m_x,m_y);
    state=0;
    i=0;
    sound=0;
}
void Bird::setposition(int x,int y)
{
    m_x=x;
    m_y=y;
    rec.moveTo(m_x,m_y);
}
void Bird::birdposition()
{
    i++;
    if(i%3==0){
        m_y+=BIRD_DOWN_SPEED;
        state++;
    }
    switch(state%3)
    {
    case 0:
        birdmap.load(BIRD_UP_PATH);
        break;
    case 1:
        birdmap.load(BIRD_MID_PATH);
        break;
    case 2:
        birdmap.load(BIRD_DOWN_PATH);
        break;
    }
    rec.moveTo(m_x,m_y);
}
void Bird::dead(){
    birdmap.load(BIRD_DEAD_PATH);
    m_x-=TUBE_SPEED;
    m_y+=BIRD_DEAD_SPEED;
    if(sound==0){


        QSoundEffect effect;
        effect.setSource(QUrl::fromLocalFile(CRASH_PATH));
        effect.setLoopCount(1);
        effect.setVolume(1);
        effect.play();

        QSoundEffect effect1;
        effect1.setSource(QUrl::fromLocalFile(BIRD_DROP_SOUND));
        effect1.setLoopCount(1);
        effect1.setVolume(1);
        effect1.play();

        sound=1;
    }
}
