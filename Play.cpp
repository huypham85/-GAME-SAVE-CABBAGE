#include "Play.h"

Play::Play()
{
    printf("state Play is created\n");
}

Play::~Play()
{
    if (player != nullptr) delete player;
}

void Play::Exit()
{
}

void Play::Pause()
{
}

void Play::Resume()
{
}

void Play::Init()
{
    // trap
    trapAnimation = Animation(1, 4, 0.1f, "trap");
    trapAnimation.setTexture(trapSprite);
    trap.setSize((Vector2f)trapSprite.getTexture()->getSize());
    trapSprite.setPosition(20, 710);
    

    //sound
    hitBuffer.loadFromFile("hit_sound.wav");
    hitSound.setBuffer(hitBuffer);
    dingBuffer.loadFromFile("DING.wav");
    dingSound.setBuffer(dingBuffer);
    bloodBuffer.loadFromFile("blood.wav");
    bloodSound.setBuffer(bloodBuffer);
    hurtBuffer.loadFromFile("hurt.wav");
    hurtSound.setBuffer(hurtBuffer);
    
    //background[0].Init("Lay.png");
    currenIndex = 1;
    background[1].Init("Layer1.png");
    background[2].Init("Layer2.png");
    background[3].Init("Layer3.png");
    background[4].Init("Layer4.png");
    background[5].Init("Layer5.png");
    background[6].Init("Layer6.png");

    //init Ui
    cout << "Gameplay Init\n";
    scoreBoxTex.loadFromFile("ScoreBox.png");
    scoreBox.setTexture(scoreBoxTex);
    scoreBox.setScale(0.4f, 0.4f);
    scoreBox.setPosition(590, 730);

    TimeLeft = 0.f;
    button = new GameButton();
    //setBG.setScale(13.0f, 13.0f);
    enemy = new Enemy();
    heart = new Heart();
    shield = new Shield();
    collision = new Collision();
    hasCollision = false;
    buttonTex.loadFromFile("Back.png");
    button->setTexture(buttonTex);
    button->setPosition(0.0f, 0.0f);
    BackPos = button->getPosition();
    button->setScale(3.0f, 3.0f);
    button->SetOnClick([]() {
        State_Machine::GetInstance()->PopState();
        });
    player = new Player();
    player->Init();
    player->initBox();
}

void Play::Update(const float& deltaTime)
{
    // trap
    trapAnimation.Update();
    trapAnimation.setTexture(trapSprite);
    if (player->getPoints() >= 0 && player->getPoints() <= 1000) currentBackGround = &background[1];
    if (player->getPoints() > 1000 && player->getPoints() <= 2000) currentBackGround = &background[2];
    if (player->getPoints() > 2000 && player->getPoints() <= 3000) currentBackGround = &background[3];
    if (player->getPoints() > 3000 && player->getPoints() <= 4000) currentBackGround = &background[4];
    if (player->getPoints() > 4000 && player->getPoints() <= 5000) currentBackGround = &background[5];
    if (player->getPoints() > 5000 && player->getPoints() <= 6000) currentBackGround = &background[6];
    currentBackGround->Update(deltaTime);

    //heart update
    heart->Update();

    //shield update
    shield->Update();
        
    //player
    player->Update(window);

    // collision animation
    if (collision->getTimer() < 4.0f&& hasCollision==true) {
        Vector2f pos = player->getPlayer().getPosition();
        collision->Update(pos.x, pos.y);
    }
    else {
        delete collision;
        hasCollision = false;
        collision = new Collision;
    }
    //enemy
    enemy->Update();

    //collision vs enemy
    if (player->getBox().getGlobalBounds().intersects(enemy->getEnemy().getGlobalBounds())) {
        cout << "GAME OVER " << endl;
        delete enemy;
        if (shield->getIsUseTime() == false) {
            hurtSound.play();
            player->DeadAnim();
         
        }
        enemy = new Enemy();
    }
    if (player->getPlayer().getGlobalBounds().intersects(enemy->getEnemy().getGlobalBounds())) {
        hitSound.play();
        hasCollision = true;
        collision->SetCollisionAnim();
        if (shield->getIsUseTime() == true) player->LoseHp(1);
        else player->LoseHp(2);
        player->UpdateGUI();
        if (player->getHpSize() == 0) {
            player->DeadAnim();
        }
        delete enemy;
        enemy = new Enemy();
    }

    //trap collision
    if (player->getPlayer().getGlobalBounds().intersects(trapSprite.getGlobalBounds())) {
        bloodSound.play();
        player->LoseHp(10);
        player->UpdateGUI();
        if (player->getHpSize() == 0) {
            player->DeadAnim();
        }
    }
    // heart collision
    if (player->getPlayer().getGlobalBounds().intersects(heart->getHeart().getGlobalBounds())) {
        dingSound.play();
        if (player->getPressable()) {
            player->GainHp(5);
            player->UpdateGUI();
            cout << "HP is Bonus" << endl;
            delete heart;
            heart->setHasHeart(false);
            heart = new Heart();
        }
    }
    else if (heart->getHeartTimer() >= 150.f && heart->getHasHeart()) {
        delete heart;
        heart->setHasHeart(false);
        heart = new Heart();    
    }

    // shield collision
    if (player->getPlayer().getGlobalBounds().intersects(shield->getShield().getGlobalBounds())) {
        dingSound.play();
        if (player->getPressable()) {
            shield->setIsUseTime(true);
            shield->setUseTime(0);
            cout << "shield is Bonus" << endl;
            delete shield;
            shield->setHasShield(false);
            shield = new Shield();
        }
    }
    else if (shield->getShieldTimer() >= 150.f && shield->getHasShield()) {
        delete shield;
        shield->setHasShield(false);
        shield = new Shield();
    }

    // catch event
    button->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, BackPos.x, BackPos.y, "Back", window);
    button->Update(deltaTime);

    // change state into EndGame
    unsigned scores = player->getPoints();
    if (player->getPressable() == false) TimeLeft += deltaTime;
    if(TimeLeft >=1.f) State_Machine::GetInstance()->ChangeState(StateTypes::STATE_EndGame);
}

void Play::Draw(RenderTarget* Target)
{
    currentBackGround->Draw(Target);
    Target->draw(trapSprite);
    //Target->draw(trap);
    Target->draw(scoreBox);
    player->Draw(Target);
    enemy->Draw(Target);
    Target->draw(*button);
    heart->Draw(Target);
    collision->Draw(Target);
    button->Draw(Target);
    shield->Draw(Target);
}
unsigned Player::point = 0;
bool Heart::hasHeart = false;
bool Shield::hasShield = false;
bool Shield::isUseTime = false;